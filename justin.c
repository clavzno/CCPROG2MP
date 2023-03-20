/***************************************************************************

CCPROG2 Machine Project - Vaccination Registration Application with Chatbot

Description: // WIP //

Programmed by: Justin Patrick M. De Grano - S18B
Last modified: 3-16-2022
Version: V0.2A

***************************************************************************/

// library and other variable declarations

#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef char stg10[11];
typedef char stg20[21];
typedef char stg30[31];

/* These are display functions which serve more as a display guide
   & decoration part for the program to the end-user. */

void displayLine() { printf("\n------------------------------------------\n"); }

// Printed introductory menu

void 
displayIntro() {

  displayLine();

  printf("\nVaxDB Introduction\n");

  displayLine();

  printf ("\nOh why, hello there! Welcome to the VaxDB Program!\n"); 
  
  printf ("\nThis program is designed for your best convenience in\n");
  printf ("your vaccine facilitation in registration, scheduling,\n");
  printf ("inquiries and all sorts of data management.\n");
  
  printf ("\nWith no further delay, you may now proceed forward in the program.\n");

  displayLine();
} 


// Printed display menu (before option A and B)

void
displayMenu() {

  displayLine();

  printf("\nVaxDB Primary Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) Vaccine Registration\n");
  printf("(B) Data/Settings Management\n");
  printf("(X) Exit the Program\n");

  displayLine();
}  

// Printed display menu (option A - vaxreg)

void 
displayMenu_A() {
	
  displayLine();

  printf("\nVaxDB Vaccine Registration Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) User Registration\n");
  printf("(B) Vaccine Appointment\n");
  printf("(C) Chat with AssistiVax (FAQs)\n");
  printf("(X) Go Back to the Primary Menu\n");

  displayLine();
} 

// Printed display menu (option B - datamanag)

void 
displayMenu_B() {

  displayLine();

  printf("\nVaxDB Data Management Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) User Management\n");
  printf("(B) Appointment Management\n");
  printf("(C) AssistiVax Management\n");
  printf("(D) Export Data\n");
  printf("(E) Import Data\n");
  printf("(X) Exit the Program\n");

  displayLine();
}

/* These are the structures to be used for the program. */

struct userStats
{
	int userID, contactNum;
	stg10 password;
	
	stg20 userNameF, userNameL;
	stg30 address;
	stg10 sex;
	
	stg10 dose1, dose1Vaxx, dose1Loc;

	stg10 dose2, dose2Vaxx, dose2Loc;
	
	stg10 dose3, dose3Vaxx, dose3Loc;
};

//struct vappStats {}
//struct chatStats {}

/* These are the functions to be made for the menu options,
   arranged from top-to-bottom - the same way it was ordered
   on function displayMenu. */

/* If the user selects vaccine registration, they would be forwarded
   to choose choices in between.

   user registration (User) - heads the user straight
   their data to be registered

   vaccine appointment (Vapp) - heads the user straight to
   input their schedule for vaccinations

   chat with assistivax (Chat) - heads the user straight to
   frequently asked questions

   back to menu - heads the user straight to the main menu */

void menuReg_User(struct userStats *uProf, int userAmount) {
	
	int tempDoseMult = 0;
	int tempUID = userAmount; //refers to the new registered user to be made

	displayLine();
	
	printf("\nVaxDB User Registration\n");

    displayLine();
    
	printf("\nPlease Input your User Data: \n");

	displayLine();

	printf("\nEnter UserID: ");
	scanf("%d", &uProf[tempUID].userID);
	printf("\nEnter Contact Number: ");
	scanf("%d", &uProf[tempUID].contactNum);
	printf("\nEnter Password: ");
	scanf("%d", &uProf[tempUID].password);
	
	displayLine();
	
	printf("\nEnter Full Name (One Space, First then Last): ");
	scanf("%s%s", &uProf[tempUID].userNameF, &uProf[tempUID].userNameL);
	printf("\nEnter Address): ");
	scanf("%s", &uProf[tempUID].address);
	printf("\nEnter Sex): ");
	scanf("%s", &uProf[tempUID].sex);
	
	displayLine();

	printf("\nEnter Date of First Vaccination): ");
	scanf("%s", &uProf[tempUID].dose1);
	printf("\nEnter Brand of First Vaccine): ");
	scanf("%s", &uProf[tempUID].dose1Vaxx);
	printf("\nEnter Location of First Vaccination): ");
	scanf("%s", &uProf[tempUID].dose1Loc);

	displayLine();
	
	printf("\nAnswer Simply with '0' (None), '1' (Two Doses), '2' (Three Doses)\n");
	printf("\nEnter Amount of Booster Doses: ");
	scanf("%d", &tempDoseMult);
	
    switch (tempDoseMult)
	{
        case 0:
			strcpy(uProf[tempUID].dose2, "N/A");        
			strcpy(uProf[tempUID].dose2Vaxx, "N/A");        
			strcpy(uProf[tempUID].dose2Loc, "N/A");   
			strcpy(uProf[tempUID].dose3, "N/A");        
			strcpy(uProf[tempUID].dose3Vaxx, "N/A");        
			strcpy(uProf[tempUID].dose3Loc, "N/A");            
			break;
        case 1:
        	printf("\nEnter Date of Second Vaccination): ");
			scanf("%s", &uProf[tempUID].dose2);
			printf("\nEnter Brand of Second Vaccine): ");
			scanf("%s", &uProf[tempUID].dose2Vaxx);
			printf("\nEnter Location of Third Vaccination): ");
			scanf("%s", &uProf[tempUID].dose2Loc);
			strcpy(uProf[tempUID].dose3, "N/A");        
			strcpy(uProf[tempUID].dose3Vaxx, "N/A");        
			strcpy(uProf[tempUID].dose3Loc, "N/A");       
        	break;
        case 2:
        	printf("\nEnter Date of Second Vaccination): ");
			scanf("%s", &uProf[tempUID].dose2);
			printf("\nEnter Brand of Second Vaccine): ");
			scanf("%s", &uProf[tempUID].dose2Vaxx);
			printf("\nEnter Location of Sceond Vaccination): ");
			scanf("%s", &uProf[tempUID].dose2Loc);
			printf("\nEnter Date of Third Vaccination): ");
			scanf("%s", &uProf[tempUID].dose3);
			printf("\nEnter Brand of Third Vaccine): ");
			scanf("%s", &uProf[tempUID].dose3Vaxx);
			printf("\nEnter Location of Third Vaccination): ");
			scanf("%s", &uProf[tempUID].dose3Loc);
        	break;
        default:
        	printf("\nInvalid Input, Please Read the Instructions Carefully.\n");
        	printf("\nAnswer Simply with 0 (None), 1 (Two Doses), 2 (Three Doses)\n");
			printf("\nEnter Amount of Booster Doses: ");
			scanf("%d", &tempDoseMult);
    }
	
	userAmount++;
}

void menuReg_Vapp() {}
// jack: try giving the user file a pointer to the vax appt details file

void menuReg_Chat() {}

void menuReg_Exit() {}

char menuReg(struct userStats uProf, int userAmount) {

	displayMenu_A();
	
	char cOpt;
    struct userStats *uProfptr = &uProf;
    
    printf("\nEnter Choice: ");
    scanf(" %c", &cOpt);
    
    switch (cOpt)
	{
        case 'A':
        case 'a':
            menuReg_User (uProfptr, userAmount);
        	break;
        case 'B':
        case 'b':
        	menuReg_Vapp ();
        	break;
        case 'C':
    	case 'c':
        	menuReg_Chat ();
        	break;
        case 'X':
        case 'x':
        	menuReg_Exit ();
        	break;
        default:
        	printf("\nInvalid input, please only use what's indicated.\n");
    }
    return cOpt;
}

/* file generation - here are the functions necessary for the
   saving and preservation of data that would be activated once
   the user has finished inputting their specified registered data,
   that can be accessed/managed later in the program */

void genUser() {}

void genVapp() {}

void genChat() {}

/* On the other hand, if the user decides to choose the latter choice of
   manage data & settings, they can choose to access & manage either
   their data (both their registration, vax appointment & chat logs)
   as necessary. It also includes an export & import data function as well.*/

void menuMng_User() {}

void menuMng_Vapp() {}

void menuMng_Chat() {}

void menuMng_Export() {}

void menuMng_Import() {}

void menuMng_Exit() {}

char menuMng() {

	displayMenu_B();
	
	char cOpt;
    
    printf("\nEnter Choice: ");
    scanf(" %c", &cOpt);
    
    switch (cOpt)
	{
        case 'A':
        case 'a':
            menuMng_User();
        	break;
        case 'B':
        case 'b':
        	menuMng_Vapp();
        	break;
        case 'C':
    	case 'c':
        	menuMng_Chat ();
        	break;
        case 'D':
        case 'd':
        	menuMng_Export ();
        	break;
        case 'E':
        case 'e':
        	menuMng_Import ();
        	break;
        case 'X':
        case 'x':
        	menuMng_Exit ();
        	break;
        default:
        	printf("\nInvalid input, please only use what's indicated.\n");
    }
    return cOpt;

}

/* The main menu that the user will be at initially. */

char menuMain (struct userStats uProf, int userAmount) {
	
	displayMenu();
	
	char cOpt;
    
    printf("\nEnter Choice: ");
    scanf(" %c", &cOpt);
    
    switch (cOpt)
	{
        case 'A':
        case 'a':
            menuReg(uProf, userAmount);
        	break;
        case 'B':
        case 'b':
        	menuMng();
        	break;
        case 'X':
        case 'x':
        	break;
        default:
        	printf("\nInvalid input, please only use what's indicated.\n");
    }
    return cOpt;
	
};

/* Here lies the function main. */

int main() {
	
  /* variable declaration */
  
  int userAmount = 0; // refers to the amount of users that inputted in the program, initially starts with 0
  struct userStats uProf[MAX_USERS]; // structural array for users in the program
     
  /* program introduction */

  displayIntro ();
  
  /* main project menu output */
  
  menuMain (uProf[MAX_USERS], userAmount);
  
  return 0;
}
