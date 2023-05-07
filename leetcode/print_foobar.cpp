#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <functional>
#include <cstdlib>

// 0 is foo, 1 is bar.
std::mutex mutexes[2];
std::mutex mtx;
std::condition_variable cvs[2];
int foo_index = 0;
int bar_index = 1;

class FooBar {
private:
    int n;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(std::function<void()> printFoo) {
        std::unique_lock<std::mutex> lock(mutexes[foo_index]);
        for (int i = 0; i < n; i++) {
            
        	// printFoo() outputs "foo". Do not change or remove this line.
            printFoo();
            cvs[bar_index].notify_all();
            if (i < n-1) {
                
                cvs[foo_index].wait(lock);
            }

        }
    }

    void bar(std::function<void()> printBar) {
        std::unique_lock<std::mutex> lock(mutexes[bar_index]);
        for (int i = 0; i < n; i++) {
            
        	// printBar() outputs "bar". Do not change or remove this line.
          cvs[bar_index].wait(lock);
        	printBar();
          cvs[foo_index].notify_all();
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
  int n = atoi(argv[1]);
  FooBar printer(n);
  std::thread threads[2];
  threads[1] = std::thread(&FooBar::bar,printer,&printBar);
  threads[0] = std::thread(&FooBar::foo,printer,&printFoo);
  
  for (auto& th : threads) th.join();

  return 0;
}