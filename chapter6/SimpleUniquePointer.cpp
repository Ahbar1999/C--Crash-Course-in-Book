

template <typename T>
struct SimpleUniquePointer {
	/*
	 * A simple template class for a regular pointer except that it can only have one owner
	 *
	 *
	 *
	 * */

	// according to default initialization rules, this compiler generated default constructor will initalize
	// an object with pointer variable set to nullptr
	SimpleUniquePointer() = default;
	SimpleUniquePointer(T* pointer): pointer{ pointer } {}
	~SimpleUniquePointer() {
		if( pointer ) delete pointer; 
	}
		
	// disable copy constructor, copy operator
	// so only one owner of the pointer exists at any point in code
	SimpleUniquePointer(const SimpleUniquePointer&) = delete;
	SimpleUniquePointer& operator=(const SimpleUniquePointer&) = delete;
	
	// Implement move semantics
	
	// Move constructor
	// basically copy the value of the pointer from other to this and remove it from other
	SimpleUniquePointer(SimpleUniquePointer&& other) noexcept: pointer { other.pointer } {
		other.pointer = nullptr;
	}

	// Move operator
	SimpleUniquePointer operator=(SimpleUniquePointer&& other) noexcept {
		// free the old memory that this pointer points to	
		// so we dont leak memory	
		if (pointer) {
			delete pointer;
		}
		// you know the drill
		this->pointer = other.pointer;
		other.pointer = nullptr;

		return *this;
	}

	// getter method to provide access to the pointer
	T* get() {
		return this->pointer;

	}


	private:
		// our private pointer variable
		T* pointer;
}


