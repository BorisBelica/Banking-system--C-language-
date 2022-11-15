#include <stdio.h>
#include <unistd.h>		// pause() function

#define SIZE 100

	
// function prototypes	
int mainMenu();

// struct
struct Person {
	int personID;
	char firstName[SIZE];
	char secondName[SIZE];
	int dayOfBirth, monthOfBirth, yearOfBirth;
	char cityOfBirth[SIZE];
	char IDcardNumber[SIZE];
};

// main function
int main () {
	
	// global variables
	int menuChoice = 0;
	double accBalance = 0;
	double amount = 0;
	
	// infinte menu loop
	while (1) {
		
		menuChoice = mainMenu();
		
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
	
	return 0;
}

int mainMenu () {
	
		int choice = 0;
	
		system("clear");
		printf("\n==== MAIN MENU ===\n\n");
		
		printf("[1] Deposit money\n");
		printf("[2] Withdraw money\n");
		printf("[3] Balance\n");
		printf("[4] Exit\n");
		
		// Choice of user
		printf("\nChoose menu option [1 - 4]: ");
		scanf("%d", &choice);
		
		return choice;
}



