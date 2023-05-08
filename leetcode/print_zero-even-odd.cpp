// https://leetcode.com/problems/print-zero-even-odd/
#include <thread>             // std::thread
#include <mutex>              // std::mutex, std::unique_lock
#include <condition_variable> // std::condition_variable
#include <functional>
#include <cstdlib>

std::mutex mtx;
std::condition_variable cv;

class ZeroEvenOdd {
private:
    int n;

public:
    int next;
    bool isZero;
    ZeroEvenOdd(int n) {
        this->n = n;
        this->next = 1;
        this->isZero = true;
    }

    // printNumber(x) outputs "x", where x is an integer.
    void zero(std::function<void(int)> printNumber) {
        do {
            std::unique_lock<std::mutex> lock(mtx);
            while(!this->isZero) {
                cv.wait_until(lock, std::chrono::steady_clock::now() + std::chrono::milliseconds(200));
                if (this->next > this->n) break;
            }
            if (this->next > this->n) break;
            printNumber(0);
            this->isZero = false;
            cv.notify_all();
        } while(this->next <= this->n);
    }

    void even(std::function<void(int)> printNumber) {
        do {
            std::unique_lock<std::mutex> lock(mtx);
            while(this->isZero || this->next % 2 == 1) {
                cv.wait_until(lock, std::chrono::steady_clock::now() + std::chrono::milliseconds(200));
                if (this->next > this->n) break;
            }
            if (this->next > this->n) break;
            printNumber(this->next);
            this->next++;
            this->isZero = true;
            cv.notify_all();
        } while (this->next <= this->n);
    }

    void odd(std::function<void(int)> printNumber) {
        do {
            std::unique_lock<std::mutex> lock(mtx);
            while(this->isZero || this->next % 2 == 0) {
                cv.wait_until(lock, std::chrono::steady_clock::now() + std::chrono::milliseconds(200));
                if (this->next > this->n) break;
            }
            if (this->next > this->n) break;
            printNumber(this->next);
            this->next++;
            this->isZero = true;
            cv.notify_all();
        } while (this->next <= this->n);
    }
};

void callback(int i) {
  printf("%d",i);
  fflush(stdout);
}

int main(int argc, char *argv[]) {
  if (argc <= 1) {
    printf("you must give us an argument");
    return 0;
  }
  int n = atoi(argv[1]);
  ZeroEvenOdd printer(n);
  std::thread threads[3];
  // need to pass in object as a pointer, or use a global variable. otherwise it won't work.
  threads[1] = std::thread(&ZeroEvenOdd::zero,&printer,&callback);
  threads[0] = std::thread(&ZeroEvenOdd::odd,&printer,&callback);
  threads[2] = std::thread(&ZeroEvenOdd::even,&printer,&callback);

  for (auto& th : threads) th.join();

  return 0;
}