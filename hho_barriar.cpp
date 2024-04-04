#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <functional>
#include <semaphore>
#include <barrier>

using namespace std;

static counting_semaphore hy_sm(2);
static counting_semaphore ox_sm(1);
static barrier hho_barrier(3);

void oxygen_thread_0(std::function<void()> releaseOxygen) {
	ox_sm.acquire();
	hho_barrier.arrive_and_wait();
	releaseOxygen();
	ox_sm.release();
}

void hyrogen_thread(std::function<void()> releaseHydrogen) {
	hy_sm.acquire();
	hho_barrier.arrive_and_wait(1);
	releaseHydrogen();
	hy_sm.release();
}

void simulate(std::function<void()> releaseOxygen, std::function<void()> releaseHydrogen) {
	std::thread	oxygen0(oxygen_thread_0, releaseOxygen);
	std::thread	hydrogen1(hyrogen_thread_1, releaseHydrogen);
	std::thread	hydrogen2(hyrogen_thread_2, releaseHydrogen);
	oxygen0.join();
	hydrogen1.join();
	hydrogen2.join();
}