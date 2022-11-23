/*
THINGS TO DO:

welcomeMenu():
1. Treat menu choice only for int (do not allow char/string or double/float).

registerNewAccount():
1. Create folder and relative path of saved file - created account in function registerNewAccount()
2. Change created acc filename from secondname ->>> ID.
3. Treat input for registration variables 
4. Check if the user with same ID doest not exist, if - generate new ID.

loginToAccount():
1. Wrong password counter and action.


*/

// LIBARIES
#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "structures.h"

// MACRO AND ASCI VALUES
#define SIZE 100
#define ENTER 13
#define TAB 9
#define BACKSPACE 8

// FUNCTION PROTOTYPES
int userMenu(void);
void welcomeMenu(void);
int generateRandomID(void);
void flushNewLine(void);
void aboutBankSystem(void);
void takePassword(char[]);
void registerNewAccount(void);
void loginToAccount(void);
void forgotPassword(void);
void userInfoScreen(struct Person);


// main function
int main () {
	system("color 0b");
	
	// GLOBAL VARIABLES
	struct Person arrayOfPersons[SIZE];
	struct Person person;

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
	randomID = rand();      			// Returns a pseudo-random integer between 0 and RAND_MAX.
	
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
		printf("[4] About\n");
		printf("[5] Exit\n");
		
		// Choice of user
		do {
			printf("\nChoose menu option [1 - 5]: ");
			scanf("%d", &choice);
			flushNewLine();
		} while (choice < 1 || choice > 5 );
	
		
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
			case 4:
				aboutBankSystem();
				break;
			case 5:
				exit(0);				
		}
		return;
}

void registerNewAccount(void) {
	system("clear");
	
	// LOCAL VARIABLES
	FILE *fp = NULL;
	struct Person person;
	char confirmChar;
	char confirmPassword[SIZE];
	int i=0;

	//GETTING DATA PERSONAL DATA
	
	system("clear");
	printf("[CREATE NEW ACCOUNT]\n\n");
	person.ID = generateRandomID();
	
	printf("____[Personal details]____\n");
	printf("Enter your name:\t");
	fgets(person.firstName, sizeof(person.firstName), stdin);
	person.firstName[strcspn(person.firstName, "\n")] = 0;		// flush new line
	
	printf("Enter your surname:\t");
	fgets(person.secondName, sizeof(person.secondName), stdin);
	person.secondName[strcspn(person.secondName, "\n")] = 0; 	// flush new line
	
	printf("Enter your day of birth:\t");
	scanf("%d", &person.dayOfBirth);
	flushNewLine();
	
	printf("Enter your month of birth:\t");
	scanf("%d", &person.monthOfBirth);
	flushNewLine();
	
	printf("Enter your year of birth:\t");
	scanf("%d", &person.yearOfBirth);
	flushNewLine();
	
	printf("Enter your address:\t");
	fgets(person.address, sizeof(person.address), stdin);
	person.address[strcspn(person.address, "\n")] = 0;			// flush new line
	
	printf("\n____[Account details]____\n");
	printf("Enter your e-mail address:\t");
	fgets(person.email, sizeof(person.email), stdin);
	person.email[strcspn(person.email, "\n")] = 0;				// flush new line
	
	//lowercase email input
	for(i = 0; person.email[i]; i++){
		person.email[i] = tolower(person.email[i]);
	}
	
	printf("Enter your password:\t");
	takePassword(person.password);
	person.password[strcspn(person.password, "\n")] = 0;		// flush new line
		
	printf("\nConfirm password: \t");
	takePassword(confirmPassword);
	confirmPassword[strcspn(confirmPassword, "\n")] = 0;
	
	// if password do not match do this
	if (strcmp(person.password,confirmPassword)) {
		printf("\n\n[ERROR] Passwords do not match !!\n");
		printf("Please register again...\n");
		sleep(4);
		registerNewAccount();
	}
	printf("\n\n[OK] Password confirmed\n");
	sleep(3);
		
	//print data to confirm correctness
	system("clear");
	printf("[CHECK PERSONAL INFO]\n");
	printf("\nID:\t\t %d", person.ID);
	printf("\nName:\t\t %s %s", person.firstName, person.secondName);
	printf("\nE-mail:\t\t %s", person.email);
	printf("\nBirth:\t\t %d/%d/%d", person.dayOfBirth, person.monthOfBirth, person.yearOfBirth);
	printf("\nAddress:\t %s", person.address);
	printf("\nPassword:\t %s", person.password);

	printf("\n\nCorrect data? [y/n]\n");
	
	while (1) {
		scanf("%c",&confirmChar);
		confirmChar = tolower(confirmChar);
		if (confirmChar == 'y' || confirmChar == 'n') {
			break;
		}
	}

	// n - data not correct, repeat register form
	if (confirmChar == 'n') {
		printf("\nPlease enter your registration data again...\n\n");
		sleep(2);
		flushNewLine();
		registerNewAccount();
	}
	
	// y - data confirmed save it
	else {
		printf("\n[OK] Creating profile...\n");
		sleep(1);
		char filename[SIZE];
		strcpy(filename, person.email);
		
		fp = fopen(strcat(filename, ".dat"),"w");
		fwrite(&person, sizeof(struct Person), 1, fp);
		
		if(fwrite != 0){
			fclose(fp);	
			printf("*** NEW USER SUCCESFULLY CREATED ***\n\n");
			sleep(3);
			welcomeMenu();	
		}
		else {
			fclose(fp);	
			printf("\n *** Registraion FAILED, please try again. ***\n\n");
			sleep(3);
			registerNewAccount();
		}
	}			
}

void flushNewLine(void){
	while(getchar() != '\n');
}

void aboutBankSystem(void) {
	system("cls");
	printf("Some info about bank system here.");
} 

void loginToAccount (void) {	
	system("clear");
	
	// LOCAL VARIABLES
	char loginEmail[SIZE], loginPassword[SIZE];
	char filename[SIZE];
	char dataFromFile[SIZE*2];
	FILE *fp = NULL;
	struct Person person;
	int wrongPswrdCounter=0;
	int i=0;

	//GETTING DATA FOR LOGIN
	
	// 3 times wrong password
	while (wrongPswrdCounter<3) {
		system("clear");
		printf("[LOGIN TO ACCOUNT]\n\n");
		
		printf("Enter your e-mail address:\t");
		fgets(loginEmail, sizeof(loginEmail), stdin);
		loginEmail[strcspn(loginEmail, "\n")] = 0;				// flush new line
		
		//lowercase email input
		for(i = 0; loginEmail[i]; i++){
		  loginEmail[i] = tolower(loginEmail[i]);
		}
		
		printf("Enter your password:\t");
		takePassword(loginPassword);
		loginPassword[strcspn(loginPassword, "\n")] = 0;		// flush new line
			
		// copy email to filename for open user file	
		strcpy(filename, loginEmail);
		
		// open file
		fp = fopen(strcat(filename, ".dat"),"r");
		
		// error in reading from file / user not exist
		if (fp == NULL) {
			fclose(fp);	
			printf("\n\n[ERROR] User doest not exist...\n");
			sleep(2);
			loginToAccount();
		}
	
		// read from file of person
		while(fread(&person, sizeof(struct Person), 1, fp))
		{	
			// check password match = 0
			if(!(strcmp(person.password, loginPassword)))
			{	
				printf("\n\n[OK] Password match - loging in screen...\n");
				sleep(2);
				system("clear");
				userInfoScreen(person);
				fclose(fp);	
				break;			
			}
			else {
				fclose(fp);	
				wrongPswrdCounter++;
				printf("\n\n[ERROR] Wrong password [%d/3]\n", wrongPswrdCounter);
				sleep(2);
			}
		}
	}
	
	fclose(fp);	
	printf("\n[ERROR] LOGIN FAILED! \n");
	sleep(2);
	welcomeMenu();
	
}
void userInfoScreen (struct Person person) {
		printf("[USER INFO]\n");
			
		printf("\nID:\t\t %d", person.ID);
		printf("\nName:\t\t %s %s", person.firstName, person.secondName);
		printf("\nE-mail:\t\t %s", person.email);
		printf("\nBirth:\t\t %d/%d/%d", person.dayOfBirth, person.monthOfBirth, person.yearOfBirth);
		printf("\nAddress:\t %s", person.address);
		sleep(5);
}

void forgotPassword (void) {
	printf("Forgot password function");
}

void takePassword (char psword[SIZE]) {
	int i=0;
	char ch;
	while (1) {
		ch = getch();
		if (ch == ENTER || ch == TAB){
			psword[i] = '\0';
			break;
		}
		else if (ch == BACKSPACE) {
			if(i>0) {
				i--;
				printf("\b \b");	// remove letter and space
			}
		}
		else {
			psword[i++] = ch;
			printf("* \b");
		}
	}
}






