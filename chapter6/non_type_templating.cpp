#include <cstdio>

// below is a simple, generic/template function for getting a value from an array given index and array ref
template <size_t Index, typename T, size_t Length>
T& get(T (&arr)[Length]) {
	static_assert(Index < Length, "Out-of-bounds access");
	return arr[Index];
}


int main() {
	int fib[]{1, 1, 2, 0};
	printf("%d %d %d ", get<0>(fib), get<1>(fib), get<2>(fib));
	// calculate fib[3] with get<>()	
	get<3>(fib) = get<1>(fib) + get<2>(fib);
	printf("%d", get<3>(fib));
	// following line will throw error
	printf("%d", get<4>(fib));
}
