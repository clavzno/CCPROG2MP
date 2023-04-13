/***************
CCPROG2 S18 GRP <NUMBER>
Clavano, Angelica Therese
De Grano, Justin Patrick

Date Created: 2023-03-22s
Date Merged: 2023-04-02
Date Updated: 2023-04-11
***************/

#include "cdg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int mng_User(struct user *userProfilesptr)
{
	int choice;
	do
	{
		printf("\n");
		printf("User Data\n\n");
		printf("[1] Add New User\n"
			   "[2] View All Users\n"
			   "[3] Edit User Details\n"
			   "[4] Delete User\n"
			   "[5] Return to Data Management\n\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			/* Add new user details that includes userID, password, name, address, contact, sex, first dose, first dose vaccine, first dose location, second dose, second dose vaccine, booster dose and booster dose vaccine. Your program will ask the admin if they want to add another user or go back to the User menu. */
			mng_User_Add(userProfilesptr);
			break;
		}
		case 2:
		{
			/* View all the users arranged by user ID. The display should be in table format in the following sequence: userID, name, address, contact, sex,  first  dose,  first  dose  vaccine,  first  dose  location,    second dose, second dose vaccine, booster dose and booster dose vaccine. The program goes back to the User menu after viewing the User details.*/
			mng_UserView(userProfilesptr);
			break;
		}
		case 3:
		{
			/* Edit  new  user  details  that  includes  userID,  name,  address, contact,  sex,  first  dose, first dose vaccine, first dose location, second dose, second dose vaccine, booster dose and booster dose vaccine.  Your  program  will ask  the  admin  if  they  want  to  edit  another  user  details  or  go  back  to  the User menu */
			mng_User_Edit(userProfilesptr);
			break;
		}
		case 4:
		{
			/* Delete user details from the text file. Your program will ask the admin if they want to delete another user details or go back to the User menu */
			mng_User_Delete(userProfilesptr);
			break;
		}
		case 5:
		{
			/* The  exit  option  allows  the  user  to  quit  the  User  menu.  The  program  goes  back  to  the  Data Management  Menu*/
			return 0;
		}
		}
	} while (choice != 5);
}

int mng_Appt(struct user *userProfilesptr)
{
	int choice;
	do
	{
		printf("\n");
		printf("User Data\n\n");
		printf("[1] Add New Appointments\n"
			   "[2] View All Appointments\n"
			   "[3] Edit Appointments\n"
			   "[4] Delete Appointments\n"
			   "[5] Return to Data Management\n\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			/* Add new appointment details that includes appID, name, location, vaccine, date and time. Your program will ask the admin if they want to add another  appointment or  go back to the Appointment menu.*/
			mng_Appt_Add(userProfilesptr);
			break;
		}
		case 2:
		{
			/* View all the appointments by the users. The display should be in table format in the following  sequence:  appID, name, location,  vaccine,  date  and  time.  The program goes  back  to  the Appointment menu after viewing the Appointment details.*/
			mng_Appt_View(userProfilesptr);
			break;
		}
		case 3:
		{
			/* Edit the details of the appointment that includes appID, name, location, vaccine, date and time. Your program will ask the admin if they want to edit another appointment details or go back to the Appointment menu.*/
			mng_Appt_Edit(userProfilesptr);
			break;
		}
		case 4:
		{
			/* Cancel  an  appointment  by  deleting  it  from  the  list  of  appointments.  Your program will ask the admin if they want to delete another appointment or go back to the Appointment menu. */
			mng_Appt_Delete(userProfilesptr);
			break;
		}
		case 5:
		{
			/* The  exit  option  allows  the  user  to  quit  the  Appointment  menu.  The  program  goes  back to  the Data Management  Menu. */
			return 0;
		}
		}
	} while (choice != 5);
}

int mng_Chat(struct user *userProfilesptr)
{
	int choice;
	do
	{
		printf("\nChoose an option:\n");
		printf("[1] Add New QnA\n");
		printf("[2] View all QnA\n");
		printf("[3] Manage QnA\n");
		printf("[4] Delete QnA\n");
		printf("[5] Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			/*Add vaccination FAQ question and answer in the chatbot text file. Your program will ask the admin if  they want to add another  question and answer or go back to the Chatbot menu.*/
			mng_Chat_Add();
			break;
		}
		case 2:
		{
			/* This feature shows all the questions and answers for the chatbot. The program goes back to the Chatbot menu after viewing the Chatbot questions and answers*/
			mng_Chat_View();
			break;
		}
		case 3:
		{
			/* This will allow the admin to edit questions and answers in the chatbot text file. Your program will ask the admin if they want to edit another  question and answer or go back to the Chatbot menu.*/
			mng_Chat_Edit();
			break;
		}
		case 4:
		{
			/* This  will  allow  the  admin  to  delete  questions  and  answers  in  the chatbot text file. Your program will ask the admin if they want to delete another question and answer page 5 or go back to the Chatbot menu.*/
			mng_Chat_Delete();
			break;
		}
		case 5:
		{
			/*  The  exit  option  allows  the  user  to  quit  the  Chatbot  menu.  The  program  goes  back  to  the  Data Management  Menu. */
			return 0;
		}
		}
	} while (choice != 5);
}

int mng_ChoosePort(struct user *userProfilesptr)
{
	int choice;
	do
	{
		printf("\nChoose an Option:\n");
		printf("[1] Import\n");
		printf("[2] Export\n");
		printf("[3] Exit\n");
		printf("Choice: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			mng_Import(userProfilesptr);
			break;
		}
		case 2:
		{
			mng_Export(userProfilesptr);
			break;
		}
		case 3:
		{
			return 0;
			// mng_Exit(userProfilesptr, );
			break;
		}
		}
	} while (choice != 3);
}

int management(struct user *userProfilesptr)
{
	int choice;

	do
	{
		printf("\n");
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
			mng_User(userProfilesptr);
			break;
		}
		case 2:
		{
			system("cls");
			mng_Appt(userProfilesptr);
			break;
		}
		case 3:
		{
			system("cls");
			mng_Chat(userProfilesptr);
			break;
		}
		case 4:
		{
			system("cls");
			mng_ChoosePort(userProfilesptr);
			break;
		}
		case 5:
		{
			system("cls");
			return 0;
			// mng_Exit(userProfilesptr, );
			break;
		}
		default:
		{
			printf(ANSI_RED "Error: Invalid Choice\n" ANSI_OFF);
			sleep(2);
			system("cls");
			return 0; // goes back to main menu
		}
		} // end switch case
	} while (choice != 5);
}

int submainmenu(struct user *userProfilesptr)
{
	int choice;

	do
	{
		displayLine_ast();

		printf("Welcome to AssistiVAX! Your Personal Vaccination Assistant\n\n");

		printf("Choose your option:\n"
			   "[1] User Registration\n"
			   "[2] Schedule an Appointment\n"
			   "[3] Talk with AssistiVax\n"
			   "[4] Exit\n\n");

		displayLine_ast();

		printf("Enter your choice below:\n> ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			/* Once this option is chosen, the user will be asked to input all the necessary information about the user. For simplicity, the userID  is also given by the user as input. However, this userID should be unique (that is, no other such userID exists  in the list of users). After registering, the user is redirected back to the Vaccination Registration System menu. Don’t forget to prompt the user of their Successful Registration */
			system("cls");
			reg_User(userProfilesptr);
			break;
		}
		case 2:
		{
			/* When a user registers successfully, they can log in with their userID and password. Your program should give the user three unsuccessful attempts before terminating the program. The Vaccination Appointment menu has two sub-menus: Appointment Request and Manage Appointment menu with the following specifications:*/
			system("cls");
			reg_Appt(userProfilesptr);
			break;
		}
		case 3:
		{
			/* This menu allows the user to ask FAQs (Frequently Asked Questions) to a simple chatbot related to COVID 19.Your program will ask the user to enter a question as a string, then compares the string from the content of the chatbot text file. You can compare the two strings lexicographically using the strcmp() function from string.h, which  simply  means  that  it  compares  each  character  in  sequence  starting  with  the  first  character  until  the characters in both strings are equal or a NULL character is found. If a match is found, the answer will be displayed on the screen. However, if the match is not found, the user will be prompted with “Sorry, I  don’t know the answer.  Please type another question”. This will allow the user to enter another question or exit the chatbot feature and go back to the main menu.  Note that format of the text files are listed under Exit menu of the Data Management Menu.*/
			system("cls");
			reg_Chat(userProfilesptr);
			break;
		}
		case 4:
		{
			/* The exit option allows the user to quit the program. */
			system("cls");
			return 0;
			break;
		}
		default:
		{
			printf(ANSI_RED "Error: Invalid Choice\n" ANSI_OFF);
			sleep(2);
			system("cls");
			return 0; // goes back to main menu
		}
		}
	} while (choice != 4);
}

int mainmenu(struct user *userProfilesptr)
{

	int choice;
	int emptyprofile = checkEmptyIndex(userProfilesptr); // checks and return empty index

	do
	{
		displayLine_ast();

		printf("Welcome to AssistiVAX! Your Personal Vaccination Assistant\n\n");
		printf("Are you an admin or user?\n");
		printf("Choose your option:\n"
			   "[1] User\n"
			   "[2] Admin\n"
			   "[3] Exit\n\n");

		displayLine_ast();

		printf("Enter your choice below:\n> ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
		{
			system("cls");
			submainmenu(userProfilesptr);
			break;
		}
		case 2:
		{
			/* Data  management  menu  is  for  the  administrator  who  will  manage  the  Vaccination  Registration  with  Chatbot  Application. To grant access to the module, the user must log-in using their userID and password (you should have all  the characters to asterisks ) . Further, the user is granted with three attempts to log-in, otherwise the program will  be terminated. For verification, he is asked to input the password. Upon successful log-in, the following features are available:*/
			system("cls");
			management(userProfilesptr);
			mainmenu(userProfilesptr);
			break;
		}
		case 3:
		{
			/* The exit option allows the user to quit the program. */
			system("cls");
			return 0;
			break;
		}
		default:
		{
			printf(ANSI_RED "Error: Invalid Choice\n" ANSI_OFF);
			sleep(2);
			system("cls");
			mainmenu(userProfilesptr);
			break;
		}
		}
	} while (choice != 3);
	return 0;
}

int main()
{
	struct user userProfiles[MAX_USERS];		 // array of user profiles
	struct user *userProfilesptr = userProfiles; // pointer to user profiles array

	printf("Initializing user profiles...\n");
	sleep(1);
	// initalize all user profiles to be empty
	for (int i = 0; i < MAX_USERS; i++)
	{
		memset(userProfiles[i].userID, '\0', sizeof(userProfiles[i].userID));
		memset(userProfiles[i].password, '\0', sizeof(userProfiles[i].password));
		memset(userProfiles[i].name, '\0', sizeof(userProfiles[i].name));
		memset(userProfiles[i].contact, '\0', sizeof(userProfiles[i].contact));
		memset(userProfiles[i].address, '\0', sizeof(userProfiles[i].address));
		memset(userProfiles[i].sex, '\0', sizeof(userProfiles[i].sex));
		memset(userProfiles[i].dose1_date, '\0', sizeof(userProfiles[i].dose1_date));
		memset(userProfiles[i].dose1_type, '\0', sizeof(userProfiles[i].dose1_type));
		memset(userProfiles[i].dose1_loc, '\0', sizeof(userProfiles[i].dose1_loc));
		memset(userProfiles[i].dose2_date, '\0', sizeof(userProfiles[i].dose2_date));
		memset(userProfiles[i].dose2_type, '\0', sizeof(userProfiles[i].dose2_type));
		memset(userProfiles[i].dose2_loc, '\0', sizeof(userProfiles[i].dose2_loc));
		memset(userProfiles[i].dose3_date, '\0', sizeof(userProfiles[i].dose3_date));
		memset(userProfiles[i].dose3_type, '\0', sizeof(userProfiles[i].dose3_type));
		memset(userProfiles[i].dose3_loc, '\0', sizeof(userProfiles[i].dose3_loc));

		for (int j = 0; j < MAX_APPOINTMENTS; j++)
		{
			memset(userProfiles[i].appdetails[j].appID, '\0', sizeof(userProfiles[i].appdetails[j].location));
			memset(userProfiles[i].appdetails[j].location, '\0', sizeof(userProfiles[i].appdetails[j].location));
			memset(userProfiles[i].appdetails[j].vaccine, '\0', sizeof(userProfiles[i].appdetails[j].vaccine));
			memset(userProfiles[i].appdetails[j].time, '\0', sizeof(userProfiles[i].appdetails[j].time));
			memset(userProfiles[i].appdetails[j].date, '\0', sizeof(userProfiles[i].appdetails[j].date));
			memset(userProfiles[i].appdetails[j].dose, '\0', sizeof(userProfiles[i].appdetails[j].dose));
		}
	}

	/* To test out index */
	/*
	strcpy(userProfiles[0].userID, "1");;
	strcpy(userProfiles[0].password, "password");;
	strcpy(userProfiles[0].name, "admin");;
	strcpy(userProfiles[0].contact, "admin num");;
	strcpy(userProfiles[0].address, "1 street");;
	strcpy(userProfiles[0].dose1_date, "2023-01-01");
	strcpy(userProfiles[0].dose1_type, "Pfizer");
	strcpy(userProfiles[0].dose1_loc, "2 street");
	strcpy(userProfiles[0].appdetails[0].appID, "1");
	strcpy(userProfiles[0].appdetails[0].location, "1 street");
	strcpy(userProfiles[0].appdetails[0].vaccine, "Moderna");
	strcpy(userProfiles[0].appdetails[0].time, "12:12");
	strcpy(userProfiles[0].appdetails[0].date, "2023-01-01");
	strcpy(userProfiles[0].appdetails[0].dose, "Second");
	*/

	// displayLoading();
	mainmenu(userProfilesptr);
	displayExit();
	return 0;
}