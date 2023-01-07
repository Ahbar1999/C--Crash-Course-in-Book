#include <cstdio>


enum class Operation {
	Add,
	Subtract,
	Multiply,
	Divide
};

struct Calculator {
		
	Operation _op;

	Calculator(Operation op) {
		_op = op;
	}

	int calculate(int a, int b) {
		switch(_op) {
			case Operation::Add: {
				return a + b;	
			} break;
			
			case Operation::Subtract: {
				return a - b;	
			} break;

			case Operation::Multiply: {
				return a * b;	
			} break;

			case Operation::Divide: {
				return a / b;	
			} break;
			
			default: {
				printf("Uknown operation, returning -1 as default.");	
			}
		}
		return -1; 
	}
};


int main() {

	// three ways of initializing a POD object
	
	Calculator calc1 = { Operation::Add };

	printf("Result: %d", calc1.calculate(1, 2));
	printf("\n");

	Calculator calc2 = Calculator( Operation::Multiply );
	printf("Result: %d", calc2.calculate(1, 2));
	printf("\n");

	Calculator calc3{ Operation::Subtract };
	printf("Result: %d", calc3.calculate(1, 2));
	printf("\n");

	return 0;
}
