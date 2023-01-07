#include <cstdio>
#include <ctime>
#include <windows.h>
#include <utility>

struct TimerClass {
	
	// invalid values are 0 for both the fields
	// we will use these values to represent moved-from variables
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
		// if this is not a moved-from object
		if (this->id != 0) {
			std::time_t current_time = std::time(nullptr);
			// printf("Destruct time: %d\n", current_time);	
			printf("Age of timer%d in seconds: %d\n", this->id, (current_time - timestamp));			
		}
	}

	// copy constructor
	TimerClass(const TimerClass& other, int id): id { other.id }, timestamp { other.timestamp } {
		printf("Constructed as copy of timer%d, timer%d timestamp: %d\n", other.id, id, timestamp);	
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
		
	// move constructor
	// the type signature in the parameter denotes an rvalue
	TimerClass(TimerClass&& other) noexcept {
		// step 1: copy the content of the `other` object into `this` object
		// step 2: delete the contents of the `other` object		
		printf("Moved-from timer%d to timer%d, old timestamp %d,  new timestamp: %d\n", other.id, this->id, this->timestamp, other.timestamp);		

		this->id = other.id;
		this->timestamp = other.timestamp;

		other.id = 0;
		other.timestamp = 0;	
	}


	// move assignment operator
	// the type signature in the parameter denotes an rvalue
	TimerClass& operator=(TimerClass&& other) noexcept {
		// same steps as the Move constructor
		
		// assigning to self	
		if (this == &other) {
			return *this;	
		}
		
		printf("Moved-from timer%d to timer%d, old timestamp %d,  new timestamp: %d\n", other.id, this->id, this->timestamp, other.timestamp);		


		this->id = other.id;
		this->timestamp = other.timestamp;
		other.id = 0;
		other.timestamp = 0;

		return *this;
	}
};




int main() {
	
	TimerClass timer1 = TimerClass{1};
	TimerClass timer2 = TimerClass{2};
	// checking the functionality of copy constructions and assignments
	TimerClass timer3 = TimerClass{ timer1, 3 };	
	TimerClass timer4 = TimerClass{ 4 };
	// create an rvalue for timer4 to move to	
	timer4 = std::move(timer2);
	// timer2 is now a moved-from variable	
	return 0;
}
