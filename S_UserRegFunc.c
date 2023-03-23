#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

// User Registration Structure
struct 
	VaxRecord 
	{
		char dose1date[100];
		char dose1vax[100];
		char dose1loc[100];
		char dose2date[100];
		char dose2vax[100];
		char dose2loc[100];
		char boosterdate[100];
		char boostervax[100];
		char boosterloc[100];
	};

struct 
UserReg 
{
	int userID; // numeric ID number
	char password[10]; // string password
	char name[21]; 
	
	char address[30]; // user's full address
	char contact[12]; // contact number
	char sex[10]; // male/female
	
	struct VaxRecord VR;
};

// Function to check if string contains only numerical characters
int isNumeric(char* str) 
{
   for (int i = 0; i < strlen(str); i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

// User Registration Function
void
UserRegInput (struct UserReg UR)
{
	int IDcheck = 0;
	char idString[5];
	char minus[2] = "-";
	char *token;
	// ========================== User ID Input checker ==================================
	// UID
	do
	{
	    printf("\nPlease enter a unique 4-digit User ID: ");
	   
	    scanf("%s", idString);
	    fflush(stdin); // clear the buffer
	    
	    if (strlen(idString) == 4 && isNumeric(idString)) // check if input is exactly 4 digits and only contains numerical characters
	    {
	        UR.userID = atoi(idString); // convert string to integer
	        IDcheck = 0;
	    }
	    else
	    {
	        IDcheck = 1;
	        system("cls");    
	        displayLine();
	        printf("\n                 Error! Please Enter a 4-digit User ID\n");
	        printf("                       Press any key to proceed\n");
	        displayLine();
	        getch();
	    }
	    
	    system("cls");
	    displayUserReg();
	    
	} while (IDcheck != 0);

	printf("\nThis is your UserID: %04d", UR.userID);
	// Password
	do
	{
		
		printf("\nPlease enter your password");
		printf("\nDo not include any spaces");
		printf("\nYour Password: ");
		scanf("%s", UR.password);
			
		if (strlen(UR.password) <= 10) // password
			IDcheck = 0;
		else
		{
			IDcheck = 1;
			system("cls");	
			displayLine ();
			printf("\n             Error! Please limit your password to 10 characters!\n");
			printf("		         Press any key to proceed\n");
			displayLine ();
			getch();
		}
		
		system("cls");
		displayUserReg();
		printf("\nThis is your UserID: %d", UR.userID);
		
	} while (IDcheck != 0);
	
	printf("\nThis is your Password: %s", UR.password);
	
	// Name
	do
	{
	    printf("\nPlease enter your name ");
	    printf("\nPlease limit it to 20 characters");
	    printf("\nYour Name: ");
	    fflush(stdin); // clears the buffer
	    fgets(UR.name, sizeof(UR.name), stdin); // Justin Sacdalan
	
	    if (strlen(UR.name) > 1) // check if input is not empty
	    {
	        if (UR.name[strlen(UR.name)-1] == '\n') // remove newline character if present
	            UR.name[strlen(UR.name)-1] = '\0';
	
	        if (!(strlen(UR.name) < 21)) // check if input is greater than 20 characters
	        {
	        	IDcheck = 1;
	            system("cls");    
	            displayLine();
	            printf("\n             Error! Please limit your name to 20 characters\n");
	            printf("                     Press any key to proceed\n");
	            displayLine();
	            getch();
	        }
	        else // input is valid, exit loop
	        {
	            IDcheck = 0;
	        }
	    }
	    else // input is empty, display error message and loop
	    {
	    	IDcheck = 1;
	        system("cls");    
	        displayLine();
	        printf("\n                     Error! Please enter your name\n");
	        printf("                        Press any key to proceed\n");
	        displayLine();
	        getch();
	    }
	    
	    system("cls");
		displayUserReg();
		printf("\nThis is your UserID: %d", UR.userID);
		printf("\nThis is your Password: %s", UR.password);
	    
	} while (IDcheck != 0);
	
	printf("\nThis is your Name: %s", UR.name);
	
	// Address
	do
	{
	    printf("\nPlease enter your address ");
	    printf("\nPlease limit it to 30 characters");
	    printf("\nYour address: ");
	    fflush(stdin); // clears the buffer
	    fgets(UR.address, sizeof(UR.address), stdin); // Citta Italia, Bacoor, Cavite
	
	    if (strlen(UR.address) > 1) // check if input is not empty
	    {
	        if (UR.address[strlen(UR.address)-1] == '\n') // remove newline character if present
	            UR.address[strlen(UR.address)-1] = '\0';
	
	        if (!(strlen(UR.address) < 31)) // check if input is greater than 20 characters
	        {
	        	IDcheck = 1;
	            system("cls");    
	            displayLine();
	            printf("\n             Error! Please limit your name to 30 characters\n");
	            printf("                     Press any key to proceed\n");
	            displayLine();
	            getch();
	        }
	        else // input is valid, exit loop
	        {
	            IDcheck = 0;
	        }
	    }
	    else // input is empty, display error message and loop
	    {
	    	IDcheck = 1;
	        system("cls");    
	        displayLine();
	        printf("\n                     Error! Please enter your address\n");
	        printf("                         Press any key to proceed\n");
	        displayLine();
	        getch();
	    }
	    
	    system("cls");
		displayUserReg();
		printf("\nThis is your UserID: %d", UR.userID);
		printf("\nThis is your Password: %s", UR.password);
		printf("\nThis is your Name: %s", UR.name);
	    
	} while (IDcheck != 0);
	
	printf("\nThis is your Home Address: %s", UR.address);
	
	// Contact #
	do 
	{
	    printf("\nPlease enter your 11-digit contact number: ");
	    fflush(stdin);
	    fgets(UR.contact, sizeof(UR.contact), stdin);
	
	    // remove newline character if present
	    if (UR.contact[strlen(UR.contact)-1] == '\n') {
	        UR.contact[strlen(UR.contact)-1] = '\0';
	    }
	
	    IDcheck = 0;
	
	    // check if input is not empty
	    if (strlen(UR.contact) > 0) 
		{
	        // check if input is numeric
	        for (int i = 0; i < strlen(UR.contact); i++) 
			{
	            if (!isdigit(UR.contact[i])) 
				{
	                IDcheck = 1;
	                break;
	            }
	        }
	    } 
	
	    // check if input is valid
	    if (strlen(UR.contact) != 11 || IDcheck) 
		{
	        IDcheck = 1;
	        system("cls");    
	        displayLine();
	        printf("\n                  Error! Please enter a valid contact number\n");
	        printf("                         Press any key to proceed\n");
	        displayLine();
	        getch();
	    }
		
		system("cls");
		displayUserReg();
		printf("\nThis is your UserID: %d", UR.userID);
		printf("\nThis is your Password: %s", UR.password);
		printf("\nThis is your Name: %s", UR.name);
		printf("\nThis is your Home Address: %s", UR.address);
		
	} while (IDcheck);

	printf("\nThis is your Contact Number: %s", UR.contact);
	
	// Sex
	do 
	{
	    printf("\nPlease enter your Sex (Male/Female): ");
	    fflush(stdin); // clears the buffer
	    fgets(UR.sex, sizeof(UR.sex), stdin); // Justin Sacdalan
	
	    if (strlen(UR.sex) > 0) 
		{ // check if input is not empty
	        if (UR.sex[strlen(UR.sex)-1] == '\n') // remove newline character if present
	            UR.sex[strlen(UR.sex)-1] = '\0';
	
	        if (strcmp(UR.sex, "Male") != 0 && strcmp(UR.sex, "Female") != 0 && 
			strcmp(UR.sex, "M") != 0 && strcmp(UR.sex, "F") != 0) 
			{
	            IDcheck = 1;
	            system("cls");    
	            displayLine();
	            printf("\n             Error! Please enter a valid sex (Male or Female)\n");
	            printf("                     Press any key to proceed\n");
	            displayLine();
	            getch();
	        }
	        else {
	            IDcheck = 0;
	        }
	        
	        if (strcmp(UR.sex, "M") == 0)
	        	strcpy(UR.sex, "Male");
	        else if (strcmp(UR.sex, "F") == 0)
	        	strcpy(UR.sex, "Female");	
	    }
	    
	    else {
	        IDcheck = 1;
	        system("cls");    
	        displayLine();
	        printf("\n                      Error! Please enter your sex\n");
	        printf("                        Press any key to proceed\n");
	        displayLine();
	        getch();
	    }
	    
	   		system("cls");
			displayUserReg();
			printf("\nThis is your UserID: %d", UR.userID);
			printf("\nThis is your Password: %s", UR.password);
			printf("\nThis is your Name: %s", UR.name);
			printf("\nThis is your Home Address: %s", UR.address);
			printf("\nThis is your Contact Number: %s", UR.contact);
	    
	} while (IDcheck != 0);

	printf("\nThis is your Sex: %s", UR.sex);
	
	// First dose date
	do 
	{
	    printf("\nPlease enter the date of your first dose (YYYY-MM-DD): ");
		fflush(stdin);
		fgets(UR.VR.dose1date, sizeof(UR.VR.dose1date), stdin);
		
		token = strtok (UR.VR.dose1date, minus);
	    IDcheck = 0;
	
	    // check if input is not empty
	    if (strlen(UR.VR.dose1date) < 1) 
		{
	        IDcheck = 1;
	        system("cls");    
	        displayLine();
	        printf("\n                      Error! Please enter a valid date!\n");
	        printf("                         Press any key to proceed\n");
	        displayLine();
	        getch();
	    }
		        
        system("cls");
			displayUserReg();
			printf("\nThis is your UserID: %d", UR.userID);
			printf("\nThis is your Password: %s", UR.password);
			printf("\nThis is your Name: %s", UR.name);
			printf("\nThis is your Home Address: %s", UR.address);
			printf("\nThis is your Contact Number: %s", UR.contact);
        	printf("\nThis is your Sex: %s", UR.sex);
        
    } while (IDcheck != 0);
	
	do
	{
		printf("%s", token);
		token = strtok(0, minus);
		if(token != 0) 
			printf("-");
	} while (token != 0);
	
}

