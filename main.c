#include <stdio.h>
#include <unistd.h>		// pause() function


#define SIZE 100

	
// FUNCTION PROTOTYPES
int userMenu(void);
void welcomeMenu(void);
int generateRandomID(void);
void flushNewLine(void);

void registerNewAccount(void);
void loginToAccount(void);
void forgotPassword(void);


// STRUCTURES
struct Account {
	int ID;
	double balance;
};

struct Person {
	int ID;
	
	char firstName[SIZE];
	char secondName[SIZE];
	int dayOfBirth, monthOfBirth, yearOfBirth;
	
	char IDcardNumber[SIZE];
	char address[SIZE];
	
	char email[SIZE];
	char password[SIZE];
	
	struct Account account;
};

// main function
int main () {
	
	// GLOBAL VARIABLES
	struct Person arrayOfPersons[SIZE];

	// 1. Start welcome menu for login/register/forgot password
	welcomeMenu();
	
	
	/*
	// infinte menu loop
	while (1) {
		
		menuChoice = userMenu();
		
		switch (menuChoice) {
			
			// deposit money
			case 1:
				system("clear");
				printf("[1] Deposit money\n");
				printf("Enter amount (€): ");
				scanf("%lf", &amount);
				accBalance = accBalance + amount; 
				
				printf("I deposit cash...\n");
				sleep(3);
				printf("Completed!\n");
				sleep(1);
				break;
			
			// vyber hotovosti
			case 2:
				system("clear");
				printf("[2] Cash withdrawal\n");
				printf("Enter amount (€): ");
				scanf("%lf", &amount);
				accBalance = accBalance - amount; 
				
				printf("Vyberam hotovost...\n");
				sleep(3);
				printf("Hotovo!\n");
				sleep(1);
				break;
			
			// stav na ucte
			case 3:
				system("clear");
				printf("[3] Stav uctu\n");
				printf("%.2lf eur\n", accBalance);
				sleep(3);
				break;
			
			// koniec programu
			case 4:
				printf("Ukoncujem program...\n");
				sleep(3);
				printf("Dovidenia!\n");
				sleep(1);
				exit(0);
		}
	}
	*/
	
	return 0;
}

int generateRandomID (void) {
	int randomID = 0;
	
	srand((unsigned int)time(NULL));   // Initialization, should only be called once.
	randomID = rand();      // Returns a pseudo-random integer between 0 and RAND_MAX.
	
	return randomID;
}

int userMenu () {
	
		int choice = 0;
	
		system("clear");
		printf("\n==== USER MAIN MENU ===\n\n");
		
		printf("[1] Deposit money\n");
		printf("[2] Withdraw money\n");
		printf("[3] Balance\n");
		printf("[4] Exit\n");
		
		// Choice of user
		printf("\nChoose menu option [1 - 4]: ");
		scanf("%d", &choice);
		
		return choice;
}

void welcomeMenu (void) {
	
		int choice;
		
		system("clear");
		printf("==== WELCOME TO BANKING SYSTEM ===\n\n");
		
		printf("[1] Create new account\n");
		printf("[2] Login\n");
		printf("[3] Forgot password\n");
		printf("[4] Exit\n");
		
		// Choice of user
		do {
			printf("\nChoose menu option [1 - 4]: ");
			scanf("%d", &choice);
			flushNewLine();
		} while (choice < 1 || choice > 4 );
	
		
		switch (choice) {
			case 1:
				registerNewAccount();
				break;
				
			case 2:
				loginToAccount();
				break;
			
			case 3:
				forgotPassword();
				break;		
		}
		return;
}

void takeInput(char ch[SIZE]) {
	fgets(ch, SIZE, stdin);
	ch[strlen(ch) - 1] = 0;
}

void registerNewAccount(void) {
	system("clear");
	
	// LOCAL VARIABLES
	FILE *fp;
	struct Person person;
	char confirmChar;

	//GETTING DATA PERSONAL DATA
	
	system("clear");
	printf("[CREATE NEW ACCOUNT]\n\n");
	person.ID = generateRandomID();
	
	printf("Enter your name:\t");
	fgets(person.firstName, sizeof(person.firstName), stdin);
	person.firstName[strcspn(person.firstName, "\n")] = 0;		// flush new line
	
	printf("Enter your surname:\t");
	fgets(person.secondName, sizeof(person.secondName), stdin);
	person.secondName[strcspn(person.secondName, "\n")] = 0; 	// flush new line
	
	printf("Enter your e-mail address:\t");
	fgets(person.email, sizeof(person.email), stdin);
	person.email[strcspn(person.email, "\n")] = 0;				// flush new line
	
	printf("Enter your day of birth:\t");
	scanf("%d", &person.dayOfBirth);
	flushNewLine();
	
	printf("Enter your month of birth:\t");
	scanf("%d", &person.monthOfBirth);
	flushNewLine();
	
	printf("Enter your year of birth:\t");
	scanf(" %d", &person.yearOfBirth);
	flushNewLine();
	
	printf("Enter your address:\t");
	fgets(person.address, sizeof(person.address), stdin);
	person.address[strcspn(person.address, "\n")] = 0;			// flush new line
	
	printf("Enter your password:\t");
	fgets(person.password, sizeof(person.password), stdin);
	person.password[strcspn(person.password, "\n")] = 0;		// flush new line
	
	//print data to confirm correctness
	system("clear");
	printf("\n--PERSON INFO TO SAVE--\n");
	printf("\nID: %d", person.ID);
	printf("\nName: %s %s", person.firstName, person.secondName);
	printf("\nE-mail: %s", person.email);
	printf("\nBirth: %d/%d/%d", person.dayOfBirth, person.monthOfBirth, person.yearOfBirth);
	printf("\nAddress: %s", person.address);
	printf("\nPassword: %s", person.password);

	printf("\n\n--CONFIRM DATA? [y/n]--\n");
	
	while (1) {
		scanf("%c",&confirmChar);
		confirmChar = tolower(confirmChar);
		if (confirmChar == 'y' || confirmChar == 'n') {
			break;
		}
	}

	// data not correct, repeat register form
	if (confirmChar == 'n') {
		printf("\nPlease enter your data again...\n\n");
		sleep(2);
		flushNewLine();
		registerNewAccount();
	}
	
	// data confirmed save it
	else {
		printf("\n\nSaving data to file");
	}		
	
}

void flushNewLine(void)
{
	while(getchar() != '\n');
}

void loginToAccount (void) {
	printf("Login account function");
}

void forgotPassword (void) {
	printf("Forgot password function");
}



