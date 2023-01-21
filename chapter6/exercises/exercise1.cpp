#include <cstdio>
#include <climits>
#include <type_traits>

// a concept that checks if a type is integral(char, integer, long, long long) or not
// floating types like float, double will fail 
template<typename T>
concept bool Integer(){	
	return std::is_integral<T>::value;
}

template<Integer T>
int mode(const T* values, size_t length) {		
	if (length < 1) {
		return 0;
	}

	// value in values can have max value 100000
	static int freq[100000] = {};	
	int max_freq = 0;
	T result = 0;

	for(int i = 0; i < length; i++) {
		// casting all the datatypes to int ?
		// where's polymorphism you moron ?
		int index = values[i];
		freq[index] += 1;
		if (max_freq < freq[index]) {
			max_freq = freq[index];
			result = values[index];
		}
	}
	
	// printf("Inside mode function, result: %d \n", result);
	return result;
}

int main() {
	
	// char passes under integral type
	char char_array[] = {0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4, 4, 5, 5};
	// double fails
	double double_array[] = {0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4, 4, 5, 5};
	int integer_array[] = {0, 0, 0, 0, 0, 1, 2, 3, 3, 4, 4, 4, 5, 5};
	
	size_t length = 9;

	printf("%d \n", mode(integer_array, length));	
	
	return 0; 
}
