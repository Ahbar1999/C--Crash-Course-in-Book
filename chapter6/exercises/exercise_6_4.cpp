#include <cstddef>
#include <cstdio>


// taking an array ref instead of a const pointer allows for a cleaner syntax
template<size_t Length, typename T>
T mean(T (&values)[Length]) {
	T result{};
	
	for(size_t i{}; i < Length; i++) {
		result += values[i];
	}
	
	return result / Length;
}

int main() {
	float nums[] {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0};
	
	printf("%f \n", mean<sizeof(nums) / sizeof(float)>(nums));

	return 0;
}
