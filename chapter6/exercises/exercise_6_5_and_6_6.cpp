#include <cstddef>
#include <cstdio>
#include <cstdlib>


/*
enum class LoggerType {
	Console = 0, 
	File = 1
};
*/

template <typename T>
struct Bank {		
	// making transfer and logging console 
	void make_transfer(T& from, T& to, double amount) {		
		printf("Initiating transfer of amount: %lf From: %c To %c: \n", amount, from.get_name(), to.get_name());
		bool success = from.update_balance(-amount);
		if (!success){
			printf("Failed to make transfer!, Exiting\n\n");
			return;
		}
		to.update_balance(amount);
		printf("Transfer successful!\n\n");
	}	
};

// Interface for Account Implementations 
struct Account {	
	virtual ~Account() = default;	

	virtual double get_balance() = 0;	

	virtual bool update_balance(double value) = 0;	
	
	virtual char get_name() = 0;
};

// A Class for CheckingAccount deriving from Account class
struct CheckingAccount: Account {
	CheckingAccount(double value, char name): balance{value}, name{name} {
		printf("Created new Checking Account with name: %c with current balance: %lf\n", name, balance);
	}
	
	double get_balance() override {
		return balance;
	}

	char get_name() override {
		return name;
	}

	bool update_balance(double value) override {
		// boundary checks and return early	
		if(balance + value < 0) {
			printf("INSUFFICIENT FUNDS IN Account: %c\n", name);
			return false;
		}

		balance += value;
		printf("Account: %c UPDATE!, new balance: %lf\n", name, balance); 		
		
		return true;	
	}


	private:
		char name;
		double balance;
};


// A Savings Account deriving from Account Class
struct SavingsAccount: Account {
	SavingsAccount(double value, char name): balance{value}, name{name} {
		printf("Created new Savings Account with name: %c with current balance: %lf\n", name, balance);
	}
	
	double get_balance() override {
		return balance;
	}

	char get_name() override {
		return name;
	}

	bool update_balance(double value) override {
		// boundary checks and return early	
		if(value < 0) {
			printf("ERROR: Cant transfer from Savings Account %c\n", name);
			return false;
		}

		balance += value;
		printf("Account: %c UPDATE!, new balance: %lf\n", name, balance); 		
		return true;
	}


	private:
		char name;
		double balance;
};

int main() {
	/*
	printf("Constructing with LoggerType::File with %d code \n", (int)LoggerType::File);
	Bank file{ LoggerType::File };
	file.make_transfer(1000, 2000, 49.95);
	
	printf("Constructing with LoggerType::Console with %d code \n", (int)LoggerType::Console);	
	Bank console{ LoggerType::Console };
	console.make_transfer(3000, 4000, 75.55);
	*/

	Bank<Account> bank{};
	CheckingAccount checkingAccountA = CheckingAccount{5000, 'A'};
	CheckingAccount checkingAccountB = CheckingAccount{0, 'B'};
	SavingsAccount savingsAccountS = SavingsAccount{0, 'S'};

	bank.make_transfer(checkingAccountA, checkingAccountB, 1000);
	bank.make_transfer(checkingAccountB, savingsAccountS, 1000);
	bank.make_transfer(checkingAccountA, savingsAccountS, 1000);
	bank.make_transfer(savingsAccountS, checkingAccountA, 1000);
	
	return 0;
}







