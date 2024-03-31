#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>
#include <functional>
const int c_num_thread = 3;

class Barrier {
public:
	Barrier() {
		srand((unsigned int)time(NULL));
	}
	~Barrier() {
	}
	void arrival_and_wait(int index) {
		//ASSERT(index < 3 && index >= 0)

		//set the marker
		this->arrival_markers[index]++; //atomatic operation;
		int index_1 = (index + 1) % c_num_thread;
		int index_2 = (index + 2) % c_num_thread;
		//wait the marker
		while ((this->arrival_markers[index_1] < 1 && this->arrival_markers[index_2] < 1))
		{
			std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 100));
		}

		//consume the other two
		this->arrival_markers[index_1]--;
		this->arrival_markers[index_2]--;
	}

private:
	unsigned int arrival_markers[c_num_thread] = { 0 };
};

static Barrier barrier;

void oxygen_thread_0(std::function<void()> releaseOxygen) {
	barrier.arrival_and_wait(0);
	releaseOxygen();
}

void hyrogen_thread_1(std::function<void()> releaseHydrogen) {
	barrier.arrival_and_wait(1);
	releaseHydrogen();
}
void hyrogen_thread_2(std::function<void()> releaseHydrogen) {
	barrier.arrival_and_wait(2);
	releaseHydrogen();
}

void simulate(std::function<void()> releaseOxygen, std::function<void()> releaseHydrogen) {
	std::thread	oxygen0(oxygen_thread_0, releaseOxygen);
	std::thread	hydrogen1(hyrogen_thread_1, releaseHydrogen);
	std::thread	hydrogen2(hyrogen_thread_2, releaseHydrogen);
	oxygen0.join();
	hydrogen1.join();
	hydrogen2.join();
}