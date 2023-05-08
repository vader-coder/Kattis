// https://leetcode.com/problems/print-foobar-alternately/
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <functional>
#include <cstdlib>

// 0 is foo, 1 is bar.
std::mutex mutexes[2];
std::mutex mtx;
std::condition_variable cv;
std::condition_variable cvs[2];
int foo_index = 0;
int bar_index = 1;

class FooBar {
private:
    int n;

public:
    bool isFooTurn;

    FooBar(int n) {
        this->n = n;
        this->isFooTurn = true;
    }

    void foo(std::function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            std::unique_lock<std::mutex> lock(mtx);
            while(!this->isFooTurn) {
              //printf("\ngoing into %d (foo) loop: %d\n", i, this->isFooTurn);
              cv.wait_until(lock, std::chrono::steady_clock::now() + std::chrono::milliseconds(500));
            }
            
        	  // printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            this->isFooTurn = false;
            cv.notify_all();
        }
    }

    void bar(std::function<void()> printBar) {
        for (int i = 0; i < n; i++) {
          std::unique_lock<std::mutex> lock(mtx);  
        	// printBar() outputs "bar". Do not change or remove this line.
          while(this->isFooTurn) {
            //printf("\ngoing into %d (bar) loop: %d\n", i, this->isFooTurn);
            cv.wait_until(lock, std::chrono::steady_clock::now() + std::chrono::milliseconds(500));
          }
          printBar();
          this->isFooTurn = true;
          cv.notify_all();
        }
    }
};

void printFoo() {
  printf("foo");
  fflush(stdout);
}
void printBar() {
  printf("bar");
  fflush(stdout);
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("you must give us an argument");
    return 0;
  }
  int n = atoi(argv[1]);
  FooBar printer(n);
  std::thread threads[2];
  // need to pass in object as a pointer, or use a global variable. otherwise it won't work.
  threads[1] = std::thread(&FooBar::bar,&printer,&printBar);
  threads[0] = std::thread(&FooBar::foo,&printer,&printFoo);
  
  for (auto& th : threads) th.join();

  return 0;
}