#include <iostream>
#include <thread>
#include <mutex>

/* One thread counts up from 1 to 20, and the other thread waits until the count
reaches 20, then counts down from 20 to 0. A mutex is used so that only
one thread can modify the shared counter at a given time.*/ 

std::mutex counterMutex;
int counter = 0;

// Counts from 1 to 20.
void countUp() {
    for (int i = 1; i <= 20; i++) {
        counterMutex.lock();
        counter = i;
        std::cout << "Count Up: " << counter << std::endl;
        counterMutex.unlock();
    }
}

//Counts from 20 down to 0.
void countDown() {
    while (counter < 20) {
		// Just keep waiting...
    }

    for (int i = 20; i >= 0; i--) {
        counterMutex.lock();
        counter = i;
        std::cout << "Count Down: " << counter << std::endl;
        counterMutex.unlock();
    }
}

int main() {
	// Count up and down in separate threads.
    std::thread upThread(countUp);
    std::thread downThread(countDown);

    // Wait for both threads to finish.
    upThread.join();
    downThread.join();

    return 0;
}
