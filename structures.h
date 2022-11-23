#define SIZE 100

// STRUCTURES
struct Account {
	int ID;
	double balance;
};

struct Person {
	// personal info
	int ID;							// randomly generated
	char firstName[SIZE];
	char secondName[SIZE];
	int dayOfBirth, monthOfBirth, yearOfBirth;
	
	//char IDcardNumber[SIZE];
	char address[SIZE];
	
	// for login
	char email[SIZE];
	char password[SIZE];
	
	struct Account account;
};
