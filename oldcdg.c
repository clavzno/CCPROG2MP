/***************
CCPROG2 S18 GRP <NUMBER>
Clavano, Angelica Therese
De Grano, Justin Patrick

Date Created: 2023-03-22
Date Merged: 2023-04-02
Date Updated: 2023-04-08

***************/

#include "oldcdg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Data Management Menu [Admin]

// Import/Export
int mng_ChoosePort(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{
	int choice;
	printf("Choose an option:\n");
	printf("[1] Import\n");
	printf("[2] Export\n");
	printf("[3] Exit\n");
	printf("Choice: ");
	scanf("%d", &choice);

	do
	{
		switch (choice)
		{
		case 1:
		{
			mng_Import(userProfilesptr, userAmountptr);
			break;
		}
		case 2:
		{
			mng_Export(userProfilesptr, userAmountptr);
			break;
		}
		case 3:
		{
			return 0;
			//mng_Exit(userProfilesptr, userAmountptr);
			break;
		}
		}
	} while (choice != 3);
}

int mng_User(struct user *userProfilesptr, int *userAmountptr)
{
	int choice;
	printf("User Data\n\n");
	printf("[1] Add new user\n"
		   "[2] View all users\n"
		   "[3] Edit User details\n"
		   "[4] Delete User\n"
		   "[5] Return to Data Management\n\n");
	scanf("%d", &choice);

	do
	{
		switch (choice)
		{
		case 1:
		{
			mng_User_Add(userProfilesptr, userAmountptr);
			break;
		}
		case 2:
		{
			mng_User_View(userProfilesptr, userAmountptr);
			break;
		}
		case 3:
		{
			mng_User_Edit(userProfilesptr, userAmountptr);
			break;
		}
		case 4:
		{
			mng_User_Delete(userProfilesptr, userAmountptr);
			break;
		}
		case 5:
		{
			return 0;
		}
		}
	} while (choice != 5);
}

int mng_Appt(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{

	int choice;
	printf("User Data\n\n");
	printf("[1] Add new Appointments\n"
		   "[2] View all Appointments\n"
		   "[3] Edit Appointments\n"
		   "[4] Delete Appointments\n"
		   "[5] Return to Data Management\n\n");
	scanf("%d", &choice);

	do
	{
		switch (choice)
		{
		case 1:
		{
			mng_Appt_Add(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 2:
		{
			mng_Appt_View(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 3:
		{
			mng_Appt_Edit(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 4:
		{
			mng_Appt_Delete(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 5:
		{
			return 0;
		}
		}
	} while (choice != 5);
}

int management(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{
	int choice = 0;

	do
	{
		printf("Data Management\n\n");

		printf("Choose your option:\n"
			   "[1] User Data\n"
			   "[2] Appointment Data\n"
			   "[3] Chatbot Data\n"
			   "[4] Import/Export\n"
			   "[5] Exit Program\n\n");

		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			system("cls");
			mng_User(userProfilesptr, userAmountptr);
			break;
		}
		case 2:
		{
			system("cls");
			mng_Appt(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 3:
		{
			system("cls");
			mng_Chat(userProfilesptr, userAmountptr);
			break;
		}
		case 4:
		{
			system("cls");
			mng_ChoosePort(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 5:
		{
			system("cls");
			return 0;
			//mng_Exit(userProfilesptr, userAmountptr);
			break;
		}
		default:
		{
			printf(ANSI_RED "Error: Invalid Choice\n" ANSI_OFF);
			sleep(2);
			system("cls");
			return 0; // return to main menu
		}
		} // end switch case
	} while (choice != 5);
}

int mainmenu(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{

	int choice = 0;
	int emptyprofile = checkEmpty(userProfilesptr, userAmountptr); // checks and return empty index

	do
	{
		displayLine_ast();

		printf("Welcome to AssistiVAX! Your Personal Vaccination Assistant\n\n");

		printf("Choose your option:\n"
			   "[1] User Registration\n"
			   "[2] Schedule an Appointment\n"
			   "[3] Talk with AssistiVAX\n"
			   "[4] Exit\n"
			   "[5] Admin Data Management\n\n");

		displayLine_ast();

		printf("Enter your choice below:\n> ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			system("cls");
			reg_User(userProfilesptr, userAmountptr);
			mainmenu(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 2:
		{
			system("cls");
			reg_Appt(userProfilesptr, userAmountptr, apptAmountptr);
			mainmenu(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 3:
		{
			system("cls");
			reg_Chat(userProfilesptr, userAmountptr);
			mainmenu(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		case 4:
		{
			system("cls");
			return 0;
		}
		case 5:
		{
			system("cls");
			management(userProfilesptr, userAmountptr, apptAmountptr);
			mainmenu(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		default:
		{
			printf(ANSI_REPEATCHOICE);
			printf(ANSI_RED "Error: Invalid Choice\n" ANSI_OFF);
			sleep(2);
			system("cls");
			mainmenu(userProfilesptr, userAmountptr, apptAmountptr);
			break;
		}
		}
		fflush(stdin);
	} while (choice != 4);
	return 0;
}

int main()
{
	struct user userProfiles[MAX_USERS];		 // array of user profiles
	struct user *userProfilesptr = userProfiles; // pointer to user profiles array
	int userAmount = 0;							 // amount of users registered
	int *userAmountptr = &userAmount;			 // pointer to amount of users registered
	int apptAmount = 0;							 // amount of appointments made
	int *apptAmountptr = &apptAmount;			 // pointer to the amount of appointments made

	// displayLoading();
	mainmenu(userProfilesptr, userAmountptr, apptAmountptr);
	displayExit();
	return 0;
}