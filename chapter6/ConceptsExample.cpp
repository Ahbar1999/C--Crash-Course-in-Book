#include <cstdio>
#include <cstdlib>
#include <cstddef>
#include <type_traits>

// accompanying concept for the above templated function which addresses the aforementioned assumption
template<typename T>
concept bool Averageable() {
	// all the above assumptions have been addressed in the following code
	// ANDing a types trait and requires expression	
	return std::is_default_constructible<T>::value
		&& requires (T a, T b) {
			{ a += b} -> T;
			{ a / size_t{1} } -> T;
		};
}


// Note the use of 'Averagable' in the template declaration
template<Averageable T>
T mean(const T* values, size_t length) {
	// assumption 1: T is constructible	
	T result{};

	for(size_t i{}; i < length; i++) {
		// assumption 2: operator+= is supported on T 		
		result += values[i];
	}

	return result / length;
}


int main() {
	const int array[] = {1, 2, 3, 4, 5};	
	const auto result = mean(array, (int)(sizeof(array) / sizeof(int)));
	
	printf("Executing\n");
	printf("Int: %d\n", result);
}



