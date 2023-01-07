// this code snippet shall help us to understand
// the difference between a variable storing an array 
// and a pointer variable
//

/* 
 * From the book: 
 * Pointers share several characteristics with arrays. Pointers encode object location. 
 * Arrays encode the location and length of contiguous objects.
 * At the slightest provocation, an array will decay into a pointer. 
 * A decayed array loses length information and converts to a pointer to the array’s first element.
*/


#include <cstdio>

// the variable key_to_array is like a pointer but stores a bit more info than a typical pointer
int key_to_array[]{3, 6, 9};

// you dont even need the & before key_to_array
// it just straight away decays into a pointer
int* key_ptr = key_to_array;

struct College { 
	char name[256];
};

// just a function to print the demonstrate pointer decay
void print_name(College* college_ptr) {
	// note the use of format specifier has an effect on the pointer decay
	// college_ptr is a ptr to College struct object
	// college_ptr->name is an array variable,
	// on using the string format specifier it will decay into char*
	printf("%s College\n", college_ptr->name);
}

int main() {
	// as we can see in the output even just using the pointer specifier cause key_to_array to decay into a ptr
	// printf("Raw value of key_to_array: %p \n", key_to_array);
	// printf("Raw value of key_ptr: %p \n", key_ptr);
	// printf("Deref value: %d \n", *key_ptr);
	College best_colleges[] = {"Magadalen", "Nuffield", "Kellogg"}; 
	print_name(best_colleges);
	
	return 0;
}

