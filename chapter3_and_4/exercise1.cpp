#include <cstdio>



bool read_from(char* str, int n, int index) {
	
	if (index >= n) {
		printf("Error: index %d out bounds \n", index);
		return false;
	}
	// using pointer arithmetic to point at the desired index
	char result = *(str + index);
	printf("reading element at index: %d from string: %s \n", index, str); 	
	printf("Element: %c \n", result);

	return true;
}

bool write_to(char* str, int n, int index, char ch) {
	
	if (index >= n) {
		printf("Error: index %d out bounds \n", index);
		return false;
	}
	
	// using array syntaxs to reseat value	
	printf("writing element at index: %d to string: %s \n", index, str); 	
	str[index] = ch; 
	printf("modified string reads: %s \n", str);	

	return true;
}




int main() {

 	char lower[] = "abc?efgh"; 
	char upper[] = "ABC?EFGH";
	char* upper_ptr = upper;
	
	// lower[3] = 'd';
	// upper_ptr[3] = 'D';
	read_from(lower, sizeof(lower), 3);	
	write_to(lower, sizeof(lower), 3, 'd');
	
	read_from(lower, sizeof(upper), 3);
	write_to(upper, sizeof(upper), 3, 'D');
	
	printf("size of lower: %d \n", sizeof(lower));
	read_from(lower, sizeof(lower), 7);
	
	read_from(lower, sizeof(lower), 10);

	return 0;	
}
