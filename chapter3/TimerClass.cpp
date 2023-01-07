#include <cstdio>
#include <ctime>
#include <windows.h>

struct TimerClass {
	
	int id;
	std::time_t timestamp;	
	// initialize the fields in the constructor
	TimerClass(int id): timestamp { std::time(nullptr) } {
		this->id = id;		
		printf("timer%d timestamp: %d\n", this->id, timestamp);		
		// to introduce noticeable delay
		Sleep(2000);
	}
	
	// destructor
	~TimerClass() {	
		std::time_t current_time = std::time(nullptr);
		// printf("Destruct time: %d\n", current_time);	
		printf("Age of timer%d in seconds: %d\n", this->id, (current_time - timestamp));	
	}

	// copy constructor
	TimerClass(const TimerClass& other, int id): timestamp { other.timestamp } {
		this->id = id;
		printf("Constructed as copy of timer%d, timer%d timestamp: %d\n", other.id, this->id, timestamp);	
	}

	// copy operator
	TimerClass& operator=(const TimerClass& other) {
		// if this and other are same objects	
		if (this == &other) {
			return *this;	
		}

		this->timestamp = other.timestamp;
		
		printf("timer%d's new assigned timestamp %d \n", this->id, this->timestamp);
		return *this;
	}
};




int main() {
	
	TimerClass timer1 = TimerClass{1};
	TimerClass timer2 = TimerClass{2};
	// checking the functionality of copy constructions and assignments
	TimerClass timer3 = TimerClass{ timer1, 3};	
	TimerClass timer4 = TimerClass{ 4 };
	timer4 = timer2;
	
	return 0;
}
