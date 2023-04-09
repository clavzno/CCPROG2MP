/* 
	Objectives:
	1. Start on Chatbot Menu 
		3.1 Chatbot option
		3.2 Exit chatbot
	2. Start on Data Management Menu
		2.1 User - Add, View, Edit, Delete, Exit
		2.2 Appointment - Add, View, Edit, Delete, Exit
		2.3 Chatbot - Add, View, Edit, and Delete Question & Answers, Exit
		2.4 Export - Export Structures to txt file
		2.5 Import - Import File data to structures
		2.6 Exit - simple do/while function (or switch-case)
		
	Errors:
	1. Check chatbot compare statementsa
		
*/

#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

typedef struct UserReg_Tag // UR[0].Var_name, UR[1].Var_name
{
	int userID; // numeric ID number
	char password[11]; // string password
	char name[21]; 
	
	char address[31]; // user's full address
	char contact[14]; // contact number
	char sex[11]; // male/female
	
	char dose1date[12];
	char dose1vax[11];
	char dose1loc[11];
	
	char dose2date[12];
	char dose2vax[11];
	char dose2loc[11];
	
	char boosterdate[12];
	char boostervax[11];
	char boosterloc[11];
} UR_Array[100];

typedef struct Appointment_Tag
{
	int appID;
	int UID;
	char name[21];
	char location[11];
	char vaccine[11];
	char date[12];
	char time[7]; // 24-hour format
	char dose[11]; // first, second, booster
} VA_Array[100], New_Array[100];

void 
displayLine ()
{
	printf("==============================================================================\n");
}

void displayMainMenu (int *pMenu)
{
	printf("==============================================================================\n");
	printf("                        Welcome to the Animo Vax Program!                     \n");
	printf("                                   Main Menu                                  \n");
	displayLine();
    printf("  1) Vaccination Registration Menu\n");
    printf("  2) Data Management Menu\n");
    printf("  3) Exit the program\n");
    displayLine();
    printf(" Enter Option: ");
    scanf("%d", pMenu);
    system("cls");
}

void displayDataMan ()
{
	displayLine();
	printf("                              Data Management Menu                         \n");
	displayLine();
    printf("  1) Manage Users\n");
    printf("  2) Manage Appointments\n");
    printf("  3) Manage Chatbot [FAQ]\n");
    printf("  4) Import data from a text file\n");
    printf("  5) Export data to a text file\n");
    printf("  6) Exit to [Main Menu]\n");
    displayLine();
}

void displayImport()
{
	printf("==============================================================================\n");
	printf("                               Import Files Menu                              \n");
	printf("==============================================================================\n");
    printf("  1) Import Users\n");
    printf("  2) Import Appointments\n");
    printf("  3) Import Question & Answers\n");
    printf("  4) Exit to [Main Menu]\n");
    printf("==============================================================================\n");
}

void displayExport()
{
	printf("==============================================================================\n");
	printf("                               Export Files Menu                              \n");
	printf("==============================================================================\n");
    printf("  1) Export Users\n");
    printf("  2) Export Appointments\n");
    printf("  3) Export Question & Answers\n");
    printf("  4) Exit to [Main Menu]\n");
    printf("==============================================================================\n");
}

void 
displayUserReg ()
{
	printf("==============================================================================\n");
  	printf ("                            User Registration Menu                           \n");
  	printf("==============================================================================\n");
}

void 
displayAdminAddUser ()
{
	printf("==============================================================================\n");
  	printf ("                               Add a New User                                \n");
  	printf("==============================================================================\n");
}

void 
displayAdminAddQA ()
{
	printf("==============================================================================\n");
  	printf ("                          Add a Question and Answer                          \n");
  	printf("==============================================================================\n");
}

void 
displayAdminEditUser ()
{
	printf("==============================================================================\n");
  	printf ("                                Edit a User                                  \n");
  	printf("==============================================================================\n");
}

void 
displayAdminEditApp ()
{
	printf("==============================================================================\n");
  	printf("                              Edit an Appointment                             \n");
  	printf("==============================================================================\n");
}

void 
displayAdminEditChat ()
{
	printf("==============================================================================\n");
  	printf("                           Edit Questions & Answers                           \n");
  	printf("==============================================================================\n");
  	printf("  1) Edit Question\n");
  	printf("  2) Edit Answer\n");
  	printf("  3) Exit to [Manage Chatbot]\n");
  	printf("==============================================================================\n");
}


void
displayAdminDeleteUser ()
{
	printf("==============================================================================\n");
  	printf("                                 Delete a User                                \n");
  	printf("==============================================================================\n");
}

void
displayAdminDeleteApp ()
{
	printf("==============================================================================\n");
  	printf("                             Delete an Appointment                             \n");
  	printf("==============================================================================\n");
}

void
displayAdminDeleteChat ()
{
	printf("==============================================================================\n");
  	printf("                          Delete a Question and Answer                        \n");
  	printf("==============================================================================\n");
}

void
displayEditOptions(int ID)
{
	displayAdminEditUser();
	printf("  Select an Option to Edit\n");
	printf("  Editing User %d\n", ID);
	displayLine();
	printf("  1)  User ID\n");
	printf("  2)  Password\n");
	printf("  3)  Name\n");
	printf("  4)  Address\n");
	printf("  5)  Contact Number\n");
	printf("  6)  Sex\n");
	printf("  7)  First Dose Date\n");
	printf("  8)  First Dose Vaccine\n");
	printf("  9)  First Dose Location\n");
	printf("  10) Second Dose Date\n");
	printf("  11) Second Dose Vacine\n");
	printf("  12) Second Dose Location\n");
	printf("  13) Booster Date\n");
	printf("  14) Booster Vaccine\n");
	printf("  15) Booster Location\n");
	printf("  16) Edit another user\n");
	printf("  17) Return to [Manage Users]\n");
	displayLine();
}

void
displayEditAppOptions(int ID)
{
	displayAdminEditApp();
	printf("  Select an Option to Edit\n");
	printf("  Editing Appointment %d\n", ID);
	displayLine();
	printf("  1) User ID\n");
	printf("  2) Appointment ID\n");
	printf("  3) Name\n");
	printf("  4) Location\n");
	printf("  5) Vaccine Brand\n");
	printf("  6) Date\n");
	printf("  7) Time\n");
	printf("  8) Dose\n");
	printf("  9) Edit another Appointment\n");
	printf("  0) Return to [Manage Appointments]\n");
	displayLine();
}

void
displayChatbotMenu ()
{
	printf("==============================================================================\n");
  	printf ("                             Animo Chatbot [FAQ]                             \n");
  	printf ("                      Ask questions related to COVID-19                      \n");
  	printf ("                       or enter EXIT to exit this menu                       \n");
  	printf("==============================================================================\n");
}

void AdminUserMan ()
{
	printf("==============================================================================\n");
  	printf ("                                Manage Users                                 \n");
  	printf("==============================================================================\n");
  	printf("  1) Add a New User                                                           \n");
  	printf("  2) View All Users                                                           \n");
  	printf("  3) Edit User Details                                                        \n");
  	printf("  4) Delete User                                                              \n");
  	printf("  5) Exit to [Data Management Menu]                                           \n");
  	printf("==============================================================================\n");
}

void AdminChatMan ()
{
	printf("==============================================================================\n");
  	printf ("                               Manage Chatbot                                \n");
  	printf("==============================================================================\n");
  	printf("  1) Add a New Question & Answer                                              \n");
  	printf("  2) View All Questions & Answers                                             \n");
  	printf("  3) Edit Questions and Answers                                               \n");
  	printf("  4) Delete Questiona and Answer                                              \n");
  	printf("  5) Exit to [Data Management Menu]                                           \n");
  	printf("==============================================================================\n");
}

void AdminAppMan ()
{
	printf("==============================================================================\n");
  	printf ("                             Manage Appointments                             \n");
  	printf("==============================================================================\n");
  	printf("  1) Add a New Appointment                                                    \n");
  	printf("  2) View All Appointments                                                    \n");
  	printf("  3) Edit Appointment Details                                                 \n");
  	printf("  4) Delete Appointment                                                       \n");
  	printf("  5) Exit to [Data Management Menu]                                           \n");
  	printf("==============================================================================\n");
}

void displayAppReq()
{
	printf("==============================================================================\n");
  	printf ("                            Appointment Request                              \n");
  	printf("==============================================================================\n");
}

void
displayVaxApp ()
{
	printf("==============================================================================\n");
  	printf ("                         Vaccination Appointment Menu                        \n");
  	printf("==============================================================================\n");
}

void
displayManageApp()
{
	printf("==============================================================================\n");
  	printf ("                             Manage Appointments                             \n");
  	printf("==============================================================================\n");
}

void displayReschedDT()
{
	printf("==============================================================================\n");
  	printf ("                           Reschedule Date & Time                            \n");
  	printf("==============================================================================\n");
}

void displayReschedLoc()
{
	printf("==============================================================================\n");
  	printf ("                                Edit Location                                \n");
  	printf("==============================================================================\n");
}

void displayReschedBrand()
{
	printf("==============================================================================\n");
  	printf ("                           Edit Vaccination Brand                            \n");
  	printf("==============================================================================\n");
}

int Read_Users (UR_Array Users, int *nUsers)
{
	char *WordList[1000], *temp, *tempword, c;
	int i, j, line, valid, x, num, oldUsers;
	int line_num = 10, byte = 0;
	FILE *fp;
	
	fp = fopen("Users.txt", "r");
	
	oldUsers = *nUsers; // 2
	
	for (i = 0; i < 1000; i++)
		WordList[i] = malloc(31 * sizeof(char));
	
	temp = malloc(1000 * sizeof(char));
	
	if (fgets(temp, 1000, fp) == NULL)
		valid = 0;
	else // reads the file then assigns the file data to WordList struct array
	{
		line = 1;
		j = 0;
		fseek(fp, 0, SEEK_SET);
		while (fgets(temp, 1000, fp) != NULL)
		{
			if (line % 9 == 2 || line % 9 == 3 || line % 9 == 4)
			{
				tempword = strtok(temp, "\n");
				strcpy(WordList[j], tempword);
				j++;
			}
			else
			{
				tempword = strtok(temp, " \n");
				while (tempword != NULL)
				{
					strcpy(WordList[j], tempword);
					tempword = strtok(NULL, " \n");
					j++;
				}
			}
			line++;
		}
		
		valid = 1;
		*nUsers = j / 15; // 4
	
		(*nUsers) += oldUsers;
		(*nUsers)--;

		for (i = oldUsers, j = 15; i < *nUsers; i++) // loop for Users struct array
			for (x = 0; x < 15; x++, j++) // loop to store the txt file data to structure array
				switch(j % 15)
				{
					case 0:
						num = atoi(WordList[j]);
						Users[i].userID = num; // 2
						break;
					case 1:
						strcpy(Users[i].password, WordList[j]);
						break;
					case 2:
						strcpy(Users[i].name, WordList[j]);
						break;
					case 3:
						strcpy(Users[i].address, WordList[j]);
						break;
					case 4:
						strcpy(Users[i].contact, WordList[j]);
						break;
					case 5:
						strcpy(Users[i].sex, WordList[j]);
						break;
					case 6:
						strcpy(Users[i].dose1loc, WordList[j]);
						break;
					case 7:
						strcpy(Users[i].dose1date, WordList[j]);
						break;
					case 8:
						strcpy(Users[i].dose1vax, WordList[j]);
						break;
					case 9:
						strcpy(Users[i].dose2loc, WordList[j]);
						break;
					case 10:
						strcpy(Users[i].dose2date, WordList[j]);
						break;
					case 11:
						strcpy(Users[i].dose2vax, WordList[j]);
						break;
					case 12:
						strcpy(Users[i].boosterloc, WordList[j]);
						break;
					case 13:
						strcpy(Users[i].boosterdate, WordList[j]);
						break;
					case 14:
						strcpy(Users[i].boostervax, WordList[j]);
						break;
				}
	}
	for (i = 0; i < 1000; i++)
		free(WordList[i]);
	
	free(temp);
	fclose(fp);
	
	return valid;
}

int Read_App (VA_Array App, int *nApp)
{
	char *WordList[1000], *temp, *tempword;
	int i, j, line, valid, x, num, oldApps;
	FILE *fp;
	
	fp = fopen("Appointment.txt", "r");
	
	oldApps = *nApp;
	
	for (i = 0; i < 1000; i++)
		WordList[i] = malloc(31 * sizeof(char));
	
	temp = malloc(1000 * sizeof(char));
	
	if (fgets(temp, 1000, fp) == NULL)
		valid = 0;
	else
	{
		line = 1;
		j = 0;
		fseek(fp, 0, SEEK_SET);
		while (fgets(temp, 1000, fp) != NULL)
		{
			if (line % 8 == 2 || line % 8 == 3)
			{
				tempword = strtok(temp, "\n");
				strcpy(WordList[j], tempword);
				j++;
			}
			else
			{
				tempword = strtok(temp, " \n");
				while (tempword != NULL)
				{
					strcpy(WordList[j], tempword);
					tempword = strtok(NULL, " \n");
					j++;
				}
			}
			line++;
		}
		
		valid = 1;
		*nApp = j / 8;
		(*nApp) += oldApps;
		
		for (i = oldApps, j = 0; i < *nApp; i++) // loop for Users struct array
			for (x = 0; x < 8; x++, j++) // loop to store the txt file data to structure array
				switch(j % 8)
				{
					case 0:
						num = atoi(WordList[j]);
						App[i].appID = num;
						break;
					case 1:
						num = atoi(WordList[j]);
						App[i].UID = num;
						break;
					case 2:
						strcpy(App[i].name, WordList[j]);
						break;
					case 3:
						strcpy(App[i].location, WordList[j]);
						break;
					case 4:
						strcpy(App[i].vaccine, WordList[j]);
						break;
					case 5:
						strcpy(App[i].date, WordList[j]);
						break;
					case 6:
						strcpy(App[i].time, WordList[j]);
						break;
					case 7:
						strcpy(App[i].dose, WordList[j]);
						break;
				}
	}
	for (i = 0; i < 1000; i++)
		free(WordList[i]);
	
	free(temp);
	fclose(fp);
	
	return valid;
}
// Error: If question_index is odd, it reverses the question & answer (also array indexing might be wrong)
int Read_Chat(char *Question[], char *Answer[], int *nQuestion, int *nAnswer) 
{
    FILE *fp;
    char line[2000];
    char *token;
    int qIndex = 0, aIndex = 0, valid = 0;

    fp = fopen("Chatbot.txt", "r");
	
	qIndex = *nQuestion;
	aIndex = *nAnswer;
	
    if (fp == NULL) 
	{
        printf("Error: Could not open file.\n");
        valid = 0;
    }
	
	else
		valid = 1;
		
	while(fgets(line, 1000, fp) != NULL) 
	{
        line[strcspn(line, "\r\n")] = '\0'; // remove newline character
    
        if(qIndex == aIndex) 
		{
            Question[qIndex] = strdup(line);
            qIndex++;
        }
        else 
		{
            Answer[aIndex] = strdup(line);
            aIndex++;
        }
    }
    
    *nQuestion = qIndex;
    *nAnswer = aIndex;
    
    fclose(fp);
    return valid;
}

void UserRegistration(UR_Array Users, int *nUsers)
{
	int ID, valid, i = 0, index = 0;
	char ch, option, option2;
	char pwd[20];
	
	do {
		system("cls");
		displayUserReg();
		valid = 1;
		printf(" Enter User ID: ");
		scanf("%d", &ID);
		
		for (i = 0; i < *nUsers; i++)
			if(Users[i].userID == ID)
				valid = 0;	
		if (valid == 0)
		{
			system("cls");
			displayLine();
			printf("                         This User ID is already taken!                       \n");
			displayLine();
			system("pause");
		}
	
	} while (valid != 1);
	
	Users[*nUsers].userID = ID;
	
	printf(" Enter a Password (Do not include spaces): "); // password masking
  
    while ((ch = getch()) != '\r') {
        if (ch == '\b' && index > 0) {
            index--;
            pwd[index] = '\0';
            printf("\b \b");  // erase the asterisk
        }
        else if (isalnum(ch) && index < 19) {
            pwd[index] = ch;
            index++;
            printf("*");
        }
    }
    
    pwd[index] = '\0';
    strcpy(Users[*nUsers].password, pwd);
    printf("\n");
	printf(" Please enter your Username: ");
	scanf(" %[^\n]s", Users[*nUsers].name);
	printf(" Please enter your Address: ");
	scanf(" %[^\n]s", Users[*nUsers].address);
	printf(" Please enter a Contact Number: ");
	scanf(" %[^\n]s", Users[*nUsers].contact);
	
	do 
	{
        printf(" Please enter your sex (Male/Female): ");
        scanf(" %[^\n]s", Users[*nUsers].sex);
        for (i = 0; i < strlen(Users[*nUsers].sex); i++) 
            Users[*nUsers].sex[i] = tolower(Users[*nUsers].sex[i]);
        
    } while (strcmp(Users[*nUsers].sex, "male") != 0 && strcmp(Users[*nUsers].sex, "female") != 0);
    
    printf(" Please enter the Location of your First Dose: ");
	scanf(" %[^\n]s", Users[*nUsers].dose1loc);
	printf(" Please enter the Date of your First Dose (YYYY-MM-DD): ");
	scanf(" %[^\n]s", Users[*nUsers].dose1date);
	printf(" Please enter the Brand of your First Dose: ");
	scanf(" %[^\n]s", Users[*nUsers].dose1vax);
	
	do
	{
		system("cls");
		displayUserReg();
		printf(" Have you gotten your 2nd Dose? (Y or N): ");
		scanf(" %c", &option);	
		option = toupper(option);
	} while (option != 'Y' && option != 'N' && option != 'y' && option != 'n');
	
	
	if (option == 'Y' || option == 'y')
	{
		printf(" Please enter the Location of your Second Dose: ");
		scanf(" %[^\n]s", Users[*nUsers].dose2loc);
		printf(" Please enter the Date of your Second Dose (YYYY-MM-DD): ");
		scanf(" %[^\n]s", Users[*nUsers].dose2date);
		printf(" Please enter the Brand of your Second Dose: ");
		scanf(" %[^\n]s", Users[*nUsers].dose2vax);
		
	}
		
	else
	{
		strcpy(Users[*nUsers].dose2date, "N/A");
		strcpy(Users[*nUsers].dose2vax, "N/A");
		strcpy(Users[*nUsers].dose2loc, "N/A");
	}
	
	do
	{
		system("cls");
		displayUserReg();
		printf(" Have you gotten your Booster Shot? (Y or N): ");
		scanf(" %c", &option2);	
		option2 = toupper(option2);
	} while (option2 != 'Y' && option2 != 'N');
	
	
	if (option2 == 'Y')
	{
		printf(" Please enter the Location of your Booster Shot: ");
		scanf(" %[^\n]s", Users[*nUsers].boosterloc);
		printf(" Please enter the Date of your Booster Shot (YYYY-MM-DD): ");
		scanf(" %[^\n]s", Users[*nUsers].boosterdate);
		printf(" Please enter the Brand of your Booster Shot: ");
		scanf(" %[^\n]s", Users[*nUsers].boostervax);
		
	}
		
	else
	{
		strcpy(Users[*nUsers].boosterdate, "N/A");
		strcpy(Users[*nUsers].boostervax, "N/A");
		strcpy(Users[*nUsers].boosterloc, "N/A");
	}
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                          Registered User Information                        \n");
  	printf("==============================================================================\n");
	printf("  UserID: %d\n", Users[*nUsers].userID);
	printf("  Pass: %s\n", Users[*nUsers].password);
	printf("  Name: %s\n", Users[*nUsers].name);
	printf("  Address: %s\n", Users[*nUsers].address);
	printf("  Contact Number: %s\n", Users[*nUsers].contact);
	printf("  Sex: %s\n", Users[*nUsers].sex);
	printf("  Dose 1 Date: %s\n", Users[*nUsers].dose1date);
	printf("  Dose 1 Vax: %s\n", Users[*nUsers].dose1vax);
	printf("  Dose 1 Location: %s\n", Users[*nUsers].dose1loc);
	printf("  Dose 2 Date: %s\n", Users[*nUsers].dose2date);
	printf("  Dose 2 Vax: %s\n", Users[*nUsers].dose2vax);
	printf("  Dose 2 Location: %s\n", Users[*nUsers].dose2loc);
	printf("  Booster Date: %s\n", Users[*nUsers].boosterdate);
	printf("  Booster Vax: %s\n", Users[*nUsers].boostervax);
	printf("  Booster Location: %s\n", Users[*nUsers].boosterloc);
	system("pause");
	
	(*nUsers)++;
}

void AppRequest(VA_Array App, int *nApp, int User)
{
	int valid, ID, i = 0;
	
	do
	{
		system("cls");
		displayAppReq(); 
		valid = 1;
		printf(" Enter Appointment ID: ");
		scanf("%d", &ID);
		
		for (i = 0; i < *nApp; i++)
			if(App[i].appID == ID)
				valid = 0;	
		if (valid == 0)
		{
			system("cls");
			displayLine();
			printf("                     This Appointment ID is already taken!                    \n");
			displayLine();
			system("pause");
		}
		
	} while (valid != 1);
		
	App[*nApp].appID = ID;
	
	printf(" Enter your Name: ");
	scanf(" %[^\n]s", App[*nApp].name);
	printf(" Enter the Location of your Vaccination: ");
	scanf(" %[^\n]s", App[*nApp].location);
	printf(" Enter the Vaccine Brand you wish to take: ");
	scanf(" %[^\n]s", App[*nApp].vaccine);
	printf(" Enter the Date of your Vaccination (YYYY-MM-DD): ");
	scanf(" %[^\n]s", App[*nApp].date);
	printf(" Enter the Time of your Vaccination: ");
	scanf(" %[^\n]s", App[*nApp].time);
	printf(" Enter the Dose of your Vaccination (First, Second, or Booster): ");
	scanf(" %[^\n]s", App[*nApp].dose);
	App[*nApp].UID = User; 	
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                          Registered User Information                        \n");
  	printf("==============================================================================\n");
  	printf("  Appointment for User %d\n", App[*nApp].UID);
  	printf("  Appointment ID: %d\n", App[*nApp].appID);
  	printf("  Name: %s\n", App[*nApp].name);
  	printf("  Location %s\n", App[*nApp].location);
  	printf("  Vaccine Brand: %s\n", App[*nApp].vaccine);
  	printf("  Date: %s\n", App[*nApp].date);
  	printf("  Time: %s\n", App[*nApp].time);
  	printf("  Dose: %s\n ", App[*nApp].dose);
  	system("pause");
  	
	(*nApp)++;
}

void CancelApp(VA_Array App, int *nApp, int User, VA_Array newApp) 
{
    int i, j, appID;
    int check = 0;

    // Find all appointments associated with the User parameter
    for (i = 0; i < *nApp; i++) 
	{
        if (User == App[i].UID) 
		{
            newApp[check] = App[i];
            check++;
        }
    }

    // Display the details of all the appointments found in newApp
    printf("==============================================================================\n");
  	printf ("                              Cancel Appointment                             \n");
  	printf ("                     Enter 0 if you wish to delete nothing                   \n");
  	printf("==============================================================================\n");
    for (i = 0; i < check; i++) 
	{
        printf(" Appointment ID: %d\n", newApp[i].appID);
        printf(" Name: %s\n", newApp[i].name);
        printf(" Location: %s\n", newApp[i].location);
        printf(" Vaccine: %s\n", newApp[i].vaccine);
        printf(" Date: %s\n", newApp[i].date);
        printf(" Time: %s\n", newApp[i].time);
        printf(" Dose: %s\n", newApp[i].dose);
        printf("\n");
    }

    // Prompt the user to enter the appID of the appointment they wish to cancel
    displayLine();
    printf("Please enter the [Appointment ID] you wish to delete: ");
    scanf("%d", &appID);

    // Remove the appointment with the matching appID
    for (i = 0, j = 0; i < check; i++) 
	{
        if (appID != newApp[i].appID) 
		{
            newApp[j] = newApp[i];
            j++;
        }
    }
    check = j;

    // Copy the remaining appointments back to the original App array
    for (i = 0, j = 0; i < *nApp; i++) 
	{
        if (User != App[i].UID) 
		{
            App[j] = App[i];
            j++;
        }
    }

    // Add remaining appointments from newApp to the end of the App array
    for (i = 0; i < check; i++) 
	{
        App[j] = newApp[i];
        j++;
    }
    *nApp = j;

    // Display the details of all the appointments in the App array to confirm that the appointment has been deleted
    printf("\nUpdated Appointment List:\n");
    for (i = 0; i < *nApp; i++) 
	{
        printf(" App ID: %d\n", App[i].appID);
        printf(" Name: %s\n", App[i].name);
        printf(" Location: %s\n", App[i].location);
        printf(" Vaccine: %s\n", App[i].vaccine);
        printf(" Date: %s\n", App[i].date);
        printf(" Time: %s\n", App[i].time);
        printf(" Dose: %s\n", App[i].dose);
        printf("\n");
    }

    printf("Appointment with ID %d has been deleted.\n ", appID);
    system("pause");

}

void EditApp (VA_Array App, int *nApp, VA_Array newApp, int User)
{
	int i, j, option, check = 0, index = 0, num, appOpt;
	
	for (i = 0; i < *nApp; i++) // i < total number of appointments
		if (User == App[i].UID) // if user id is equal to 
			{
				newApp[index] = App[i];
				index++;
				check++;
			}
	
	printf("User ID: %d\n", newApp[0].UID);
	printf("Check = %d\n ", check);
	
	do
	{
		do
		{
			system("cls");
			displayLine();
			printf("                     These are the appointments for User %d                   \n", User);
			printf("                Which appointment schedule do you want to edit?               \n");
			printf("                          Enter 0 if you wish to exit                         \n");
			displayLine();
				for (i = 0; i < check; i++)
				{
					printf(" Appointment %d\n", i+1);
					printf(" App ID: %d\n", newApp[i].appID);
					printf(" Name: %s\n", newApp[i].name);
					printf(" Location: %s\n", newApp[i].location);
					printf(" Vaccine: %s\n", newApp[i].vaccine);
					printf(" Date: %s\n", newApp[i].date);
					printf(" Time: %s\n", newApp[i].time);
					printf(" Dose: %s\n", newApp[i].dose);
					printf("\n");
				}
			printf(" Number of Appointments: %d\n", check);
			printf(" Enter Option: ");
			scanf("%d", &appOpt);
			num = appOpt;
			
			if (!(appOpt <= check && appOpt > 0))
			{
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
			}
			
		} while (!(appOpt <= check) && appOpt != 0);
		
		if (appOpt == 0)
		{
			option = 4;
			system("cls");
        	printf("==============================================================================\n");
  			printf ("                   Returning to [Manage Appointments Menu]                   \n");
  			printf("==============================================================================\n");
        	system("pause");
		}
		
		else
		{
			system("cls");
			displayLine();
			printf("  What do you want to do?\n");
			printf("  1) Reschedule Date & Time\n");
			printf("  2) Change Vaccination Location\n");
			printf("  3) Change Vaccination Brand\n");
			printf("  4) Exit to [Manage Appointments]\n");
			displayLine();
			printf(" Appointment Schedule %d\n", num);
			printf(" User: %d\n", User);
			printf(" Enter Option: ");
			scanf("%d", &option);
			num--;
			
			switch (option)
			{
				case 1:
					system("cls");
					displayReschedDT();
					printf(" Re-enter Date (YYYY-MM-DD): ");
					scanf(" %[^\n]s", newApp[num].date);
					printf(" Re-enter Time: ");
					scanf(" %[^\n]s", newApp[num].time);
					printf(" New Date: %s New Time: %s\n", newApp[num].date, newApp[num].time);
					system("pause");
					break;
				case 2:
					system("cls");
					displayReschedLoc();
					printf(" Enter new Location: ");
					scanf(" %[^\n]s", newApp[num].location);
					printf(" New Location: %s\n", newApp[num].location);
					system("pause");
					break;
				case 3:
					system("cls");
					displayReschedBrand();
					printf(" Enter a new Vax Brand: ");
					scanf(" %[^\n]s", newApp[num].vaccine);
					printf(" New Vax Brand: %s\n", newApp[num].vaccine);
					system("pause");
					break;
				case 4:
					system("cls");
        			printf("==============================================================================\n");
  					printf ("                   Returning to [Manage Appointments Menu]                   \n");
  					printf("==============================================================================\n");
        			system("pause");
					break;
				default:
					system("cls");
	            	printf("==============================================================================\n");
  					printf ("                      Error: Please input a valid option                     \n");
  					printf("==============================================================================\n");
	            	system("pause");
					break;
			}
		}
	} while (option != 4);
	
	for (i = 0; i < check; i++)
    {
        for (j = 0; j < *nApp; j++)
        {
            if (newApp[i].appID == App[j].appID)
            {
                strcpy(App[j].date, newApp[i].date);
                strcpy(App[j].time, newApp[i].time);
                strcpy(App[j].location, newApp[i].location);
                strcpy(App[j].vaccine, newApp[i].vaccine);
                break;
            }
        }
    }
	
}

void ManageApp (VA_Array App, int *nApp, UR_Array Users, int *nUsers, int User, VA_Array newApp)
{
	int option;
	
	do
	{
		system("cls");
		displayManageApp();
		printf("  1) Edit Appointments\n");
		printf("  2) Cancel Appointment\n");
		printf("  3) Exit to [Vaccination Appointment Menu]\n");
		displayLine();
		printf(" User: %d\n", User);
		printf(" Enter Option: ");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				system("cls");
				EditApp(App, nApp, newApp, User);
				break;
			case 2:
				system("cls");
				CancelApp(App, nApp, User, newApp);
				break;
			case 3:
				system("cls");
        		printf("==============================================================================\n");
  				printf ("                Returning to [Vaccination Appointment Menu]                 \n");
  				printf("==============================================================================\n");
        		system("pause");
				break;
			default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
				break;			
		}
		
	} while (option != 3);
	
	
	
}

void displayVaxMenu (int *pOpt)
{
	displayLine();
	printf("                         Vaccination Registration Menu                     \n");
	displayLine();
    printf("  1) User Registration\n");
    printf("  2) Vaccination Appointment\n");
    printf("  3) Animo Chatbot [FAQs]\n");
    printf("  4) Exit to Main Menu\n");
    displayLine();
    printf(" Enter Option: ");
    scanf("%d", pOpt);
    system("cls");
}

void displayVaxOptions ()
{
	printf("  1) Appointment Request                                                      \n");
	printf("  2) Manage Appointment Menu                                                  \n");
	printf("  3) Exit to [Vaccination Registration Menu]                                  \n");
	displayLine();
}

void VaxAppointment (UR_Array Users, int *nUsers, VA_Array App, int *nApp, VA_Array newApp)
{
	int i, UID, index = 0, valid = 0, option, User, login, attempt = 1;
	char ch;
	char pwd[20];
	char *Pass;
	
	Pass = malloc(11 * sizeof(char));
	
	do
	{
		system("cls");
		displayVaxApp();
		printf("  1) Login to Create/Edit an Appointment\n");
		printf("  2) Exit to [Vaccination Registration Menu]\n");
		displayLine();
		
		printf(" Enter Option: ");
		scanf("%d", &login);
		
	} while (login != 1 && login != 2);
		
	if (login == 2)
	{
		system("cls");
        printf("==============================================================================\n");
  		printf ("                Returning to [Vaccination Registration Menu]                 \n");
  		printf("==============================================================================\n");
        system("pause");	
	}  
	else
	{
		system("cls");
		do
		{
			valid = 0;
			if (attempt == 5)
				valid = 2;
			// User ID input
			displayVaxApp();
			printf(" Please login (Enter -999 and any Password to exit)\n");
			printf(" Attempt: %d\n", attempt);
			printf(" User ID: ");
			scanf("%d", &UID); // 122
			
			// Password input
			printf(" Password: ");
			index = 0;
			memset(pwd, 0, sizeof(pwd)); // sets all pwd elements to 0 (for resetting purposes)
			
			while ((ch = getch()) != '\r') 
			{
			    if (ch == '\b' && index > 0) 
				{
			        index--;
			        pwd[index] = '\0';
			        printf("\b \b");  // erase the asterisk
			    }
			    else if (isalnum(ch) && index < 19) 
				{
			        pwd[index] = ch;
			        index++;
			        printf("*");
			    }
			}
			
			pwd[index] = '\0';
			strcpy(Pass, pwd);
		    
			for (i = 0; i < *nUsers; i++)
				if (UID == Users[i].userID && strcmp(Users[i].password, Pass) == 0)
				{
					User = UID;
					valid = 1;
				}	
			
			if (valid != 1 && valid != 2 && UID != -999)
			{
				system("cls");
				system("cls");
            	printf("==============================================================================\n");
  				printf ("           Error: The User ID you entered does not match any records         \n");
  				printf ("        Please register as a user first before creating an appointment       \n");
  				printf("==============================================================================\n");
            	system("pause");;
				system("cls");
			}
			attempt++;
		} while (valid != 1 && valid != 2 && UID != -999);
		
		if (valid == 1)
		{
			do
			{
				system("cls");
				displayVaxApp();
				displayVaxOptions();
				
				printf(" User: %d\n", User);
				printf(" Enter Option: ");
				scanf(" %d", &option);
				
				switch (option)
				{
					case 1:
						system("cls");
						AppRequest(App, nApp, User); // Appointment Request
						break;
					case 2:
						system("cls");
						ManageApp(App, nApp, Users, nUsers, User, newApp);
						break;
					case 3:
						system("cls");
            			printf("==============================================================================\n");
  						printf ("                Returning to [Vaccination Registration Menu]                 \n");
  						printf("==============================================================================\n");
            			system("pause");
						break;
					default:
						system("cls");
	            		printf("==============================================================================\n");
  						printf ("                      Error: Please input a valid option                     \n");
  						printf("==============================================================================\n");
	            		system("pause");
				}
			
			} while (option != 3);
		}
		else if (valid == 2)
		{
			system("cls");
			printf("==============================================================================\n");
  			printf ("           You have used up all of your attempts. Please login again         \n");
  			printf("==============================================================================\n");
			system("pause");
		}
		
	}	
	
	free(Pass);
}

void ChatbotMenu (char *Question[], char *Answer[], int *nQuestion, int *nAnswer) 
{
    int i, option, found = 0;
    char input[100];
    char *temp;
    
    do 
	{
        system("cls");
        displayChatbotMenu();
        printf("  1) Ask a question!\n");
        printf("  2) Exit to [Vaccination Registration Menu]\n");
        displayLine();
        printf("Enter Option: ");
        scanf("%d", &option);

        if (option == 2) {
            system("cls");
            printf("==============================================================================\n");
  			printf ("                Returning to [Vaccination Registration Menu]                 \n");
  			printf("==============================================================================\n");
            system("pause");
        }
    	
    	if (option == 1)
    	{
    		do
			{
		        system("cls");
		        displayChatbotMenu();
		        printf("  Your Question: ");
		        scanf(" %[^\n]s", input);
		        
		        temp = strtok(input, " "); // tokenize the input to compare with the questions
		
		        for (i = 0; i < *nQuestion; i++) 
				{
		            if (strstr(Question[i], temp) != NULL || strcmp(temp, "EXIT") == 0) 
					{ // compare tokenized input with the question
						if (strcmp(temp, "EXIT") != 0)
		                	printf("  Answer: %s\n  ", Answer[i]); // print the answer if a matching question is found
		                system("pause");
		                i = *nQuestion;
		                found = 1;
		            }
		        }
		
		        if (i == *nQuestion)
				{ 
		            printf("  I'm sorry, I don't know the answer to that question. Please ask another time.\n");
		            system("pause");
		        }
	   		} while (found != 1);
		}
	} while (option != 2);
}
void VaxRegMenu(UR_Array Users, int *nUsers, VA_Array App, int *nApp, VA_Array newApp, char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
  	int VaxOption;
  	
  	do
  	{
  		system("cls");
	  	displayVaxMenu(&VaxOption);
  		switch (VaxOption)
	    {
	      	case 1: // User Registration
	        	system("cls");
	        	UserRegistration(Users, nUsers);
	        	break;
	      	case 2:
	        	system("cls");
	        	VaxAppointment(Users, nUsers, App, nApp, newApp);
	        	break;
	      	case 3:
	        	system("cls");
	        	if (*nQuestion != 0)
	        		ChatbotMenu(Question, Answer, nQuestion, nAnswer);
	        	else
	        	{
	        		printf("Error: The file for Chatbot does not contain anything\n");
	        		system("pause");
				}
	        	break;
	        case 4:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                           Returning to [Main Menu]                          \n");
  				printf("==============================================================================\n");
	            system("pause");	
				break;
	      	default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
		}
		
    } while (VaxOption != 4);
}

void AdminAddUser (UR_Array Users, int *nUsers)
{
	int ID, valid, i = 0, index = 0;
	char ch, option, option2;
	char pwd[20];
	
	do {
		system("cls");
		displayAdminAddUser();
		valid = 1;
		printf(" Enter User ID: ");
		scanf("%d", &ID);
		
		for (i = 0; i < *nUsers; i++)
			if(Users[i].userID == ID)
				valid = 0;
				
		if (valid == 0)
		{
			system("cls");
			displayLine();
			printf("                         This User ID is already taken!                       \n");
			displayLine();
			system("pause");
		}
	
	} while (valid != 1);
	
	Users[*nUsers].userID = ID;
	
	printf(" Enter a Password (Do not include spaces): "); // password masking
  
    while ((ch = getch()) != '\r') {
        if (ch == '\b' && index > 0) {
            index--;
            pwd[index] = '\0';
            printf("\b \b");  // erase the asterisk
        }
        else if (isalnum(ch) && index < 19) {
            pwd[index] = ch;
            index++;
            printf("*");
        }
    }
    
    pwd[index] = '\0';
    strcpy(Users[*nUsers].password, pwd);
    printf("\n");
	printf(" Please enter your Username: ");
	scanf(" %[^\n]s", Users[*nUsers].name);
	printf(" Please enter your Address: ");
	scanf(" %[^\n]s", Users[*nUsers].address);
	printf(" Please enter a Contact Number: ");
	scanf(" %[^\n]s", Users[*nUsers].contact);
	
	do 
	{
        printf(" Please enter your sex (Male/Female): ");
        scanf(" %[^\n]s", Users[*nUsers].sex);
        for (i = 0; i < strlen(Users[*nUsers].sex); i++) 
            Users[*nUsers].sex[i] = tolower(Users[*nUsers].sex[i]);
        
    } while (strcmp(Users[*nUsers].sex, "male") != 0 && strcmp(Users[*nUsers].sex, "female") != 0);
    
    printf(" Please enter the Location of your First Dose: ");
	scanf(" %[^\n]s", Users[*nUsers].dose1loc);
	printf(" Please enter the Date of your First Dose (YYYY-MM-DD): ");
	scanf(" %[^\n]s", Users[*nUsers].dose1date);
	printf(" Please enter the Brand of your First Dose: ");
	scanf(" %[^\n]s", Users[*nUsers].dose1vax);
	
	do
	{
		system("cls");
		displayUserReg();
		printf(" Have you gotten your 2nd Dose? (Y or N): ");
		scanf(" %c", &option);	
		option = toupper(option);
	} while (option != 'Y' && option != 'N' && option != 'y' && option != 'n');
	
	
	if (option == 'Y' || option == 'y')
	{
		printf(" Please enter the Location of your Second Dose: ");
		scanf(" %[^\n]s", Users[*nUsers].dose2loc);
		printf(" Please enter the Date of your Second Dose (YYYY-MM-DD): ");
		scanf(" %[^\n]s", Users[*nUsers].dose2date);
		printf(" Please enter the Brand of your Second Dose: ");
		scanf(" %[^\n]s", Users[*nUsers].dose2vax);
		
	}
		
	else
	{
		strcpy(Users[*nUsers].dose2date, "N/A");
		strcpy(Users[*nUsers].dose2vax, "N/A");
		strcpy(Users[*nUsers].dose2loc, "N/A");
	}
	
	do
	{
		system("cls");
		displayUserReg();
		printf(" Have you gotten your Booster Shot? (Y or N): ");
		scanf(" %c", &option2);	
		option2 = toupper(option2);
	} while (option2 != 'Y' && option2 != 'N');
	
	
	if (option2 == 'Y')
	{
		printf(" Please enter the Location of your Booster Shot: ");
		scanf(" %[^\n]s", Users[*nUsers].boosterloc);
		printf(" Please enter the Date of your Booster Shot (YYYY-MM-DD): ");
		scanf(" %[^\n]s", Users[*nUsers].boosterdate);
		printf(" Please enter the Brand of your Booster Shot: ");
		scanf(" %[^\n]s", Users[*nUsers].boostervax);
		
	}
		
	else
	{
		strcpy(Users[*nUsers].boosterdate, "N/A");
		strcpy(Users[*nUsers].boostervax, "N/A");
		strcpy(Users[*nUsers].boosterloc, "N/A");
	}
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                          Registered User Information                        \n");
  	printf("==============================================================================\n");
	printf("  UserID: %d\n", Users[*nUsers].userID);
	printf("  Pass: %s\n", Users[*nUsers].password);
	printf("  Name: %s\n", Users[*nUsers].name);
	printf("  Address: %s\n", Users[*nUsers].address);
	printf("  Contact Number: %s\n", Users[*nUsers].contact);
	printf("  Sex: %s\n", Users[*nUsers].sex);
	printf("  Dose 1 Date: %s\n", Users[*nUsers].dose1date);
	printf("  Dose 1 Vax: %s\n", Users[*nUsers].dose1vax);
	printf("  Dose 1 Location: %s\n", Users[*nUsers].dose1loc);
	printf("  Dose 2 Date: %s\n", Users[*nUsers].dose2date);
	printf("  Dose 2 Vax: %s\n", Users[*nUsers].dose2vax);
	printf("  Dose 2 Location: %s\n", Users[*nUsers].dose2loc);
	printf("  Booster Date: %s\n", Users[*nUsers].boosterdate);
	printf("  Booster Vax: %s\n", Users[*nUsers].boostervax);
	printf("  Booster Location: %s\n", Users[*nUsers].boosterloc);
	system("pause");
	
	(*nUsers)++;
}

void ViewAllUsers(UR_Array Users, int *nUsers) {
    int i;
    system("cls");
    printf("==========================================================================================================\n");
    printf("| %-5s | %-10s | %-11s |            Name             |                Address                |\n", "User", "UserID", "Password", "Name", "Address");
    printf("==========================================================================================================\n");
    printf("| %-5s | %-10d | %-11s | %-27s | %-37s |\n", "Admin", Users[0].userID, Users[0].password, Users[0].name, Users[0].address);
    for (i = 1; i < *nUsers; i++) 
    	printf("| %-5d | %-10d | %-11s | %-27s | %-37s |\n", i, Users[i].userID, Users[i].password, Users[i].name, Users[i].address);
    printf("==========================================================================================================\n");
    printf("\n");
    printf("==========================================================================================================\n");
    printf("| %-15s | %-10s | %-11s | %-20s | %-34s |\n", "Contact", "Sex", "First Dose", "First Vaccine", "First Location");
    printf("==========================================================================================================\n");
    printf("| %-15s | %-10s | %-11s | %-20s | %-34s |\n", Users[0].contact, Users[0].sex, Users[0].dose1date, Users[0].dose1vax, Users[0].dose1loc);
	for (i = 1; i < *nUsers; i++) 
    	printf("| %-15s | %-10s | %-11s | %-20s | %-34s |\n", Users[i].contact, Users[i].sex, Users[i].dose1date, Users[i].dose1vax, Users[i].dose1loc);
    printf("==========================================================================================================\n");
    printf("\n");
    printf("==========================================================================================================\n");
    printf("| %-11s | %-14s | %-15s | %-13s | %-16s | %-18s |\n", "Second Dose", "Second Vaccine", "Second Location", "Booster Dose", "Booster Vaccine", "Booster Location");
    printf("==========================================================================================================\n");
    printf("| %-11s | %-14s | %-15s | %-13s | %-16s | %-18s |\n", Users[0].dose2date, Users[0].dose2vax, Users[0].dose2loc, Users[0].boosterdate, Users[0].boostervax, Users[0].boosterloc);
	for (i = 1; i < *nUsers; i++) 
    	printf("| %-11s | %-14s | %-15s | %-13s | %-16s | %-18s |\n", Users[i].dose2date, Users[i].dose2vax, Users[i].dose2loc, Users[i].boosterdate, Users[i].boostervax, Users[i].boosterloc);
    printf("==========================================================================================================\n");
    
    system("pause");
}


void AdminEditUser (UR_Array Users, int *nUsers, int *pUser)
{
	int i, ID, valid, option, index, num = 0;
	int newUID;
	char pwd[20];
	char ch;
	
	do
	{
		do
		{
			valid = 0;
			system("cls");
			displayAdminEditUser();
			printf(" Enter the User ID you wish to edit (Enter -999 to exit): ");
			scanf("%d", &ID);
			
			for (i = 0; i < *nUsers; i++)
				if(Users[i].userID == ID)
				{
					valid = 1;
					index = i;
				}
					
			if (valid == 0 && ID != -999)
			{
				system("cls");
				printf("==============================================================================\n");
				printf("                           Error: User ID not found                           \n");
				printf("==============================================================================\n");
				system("pause");
			}
			
		} while (valid != 1 && ID != -999);
	
		if (valid == 1)
		{
			do
			{
				system("cls");
				displayEditOptions(ID);
				printf("  Enter Option: ");
				scanf("%d", &option);
					
				switch (option)
				{
					case 1:
						
						do 
						{
							valid = 1;
							system("cls");
							printf("==============================================================================\n");
							printf("                          Editing User ID of User %d                          \n", ID);
							printf("==============================================================================\n");
							printf(" Enter New User ID: ");
							scanf("%d", &newUID);
							
							for (i = 0; i < *nUsers; i++)
								if(Users[i].userID == newUID)
									valid = 0;	
							if (valid == 0)
							{
								system("cls");
								displayLine();
								printf("                         This User ID is already taken!                       \n");
								displayLine();
								system("pause");
							}
						
						} while (valid != 1);
						
						Users[index].userID = newUID;
						ID = newUID;
						printf(" New User ID: %d\n", Users[index].userID);
						displayLine();
						system("pause");
						break;
						
					case 2:
						system("cls");
						printf("==============================================================================\n");
						printf("                         Editing Password of User %d                          \n", ID);
						printf("==============================================================================\n");
						printf(" Enter New Password: ");
						while ((ch = getch()) != '\r') 
						{
						    if (ch == '\b' && num > 0) 
							{
						            num--;
						            pwd[num] = '\0';
						            printf("\b \b");
						    }
						    else if (isalnum(ch) && num < 19) 
							{
						            pwd[num] = ch;
						            num++;
						            printf("*");
						    }
					    }
					    
					    pwd[num] = '\0';
					    strcpy(Users[index].password, pwd);
					    printf("\n New Password: %s\n", Users[index].password);
					    system("pause");
					    break;
					
					case 3:
						system("cls");
						printf("==============================================================================\n");
						printf("                            Editing Name of User %d                           \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Name: ");
						scanf(" %[^\n]s\n", Users[index].name);
						printf(" New Name: %s\n", Users[index].name);
						system("pause");
						break;
					
					case 4:
						system("cls");
						printf("==============================================================================\n");
						printf("                           Editing Address of User %d                         \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Address: ");
						scanf(" %[^\n]s\n", Users[index].address);
						printf(" New Address: %s\n", Users[index].address);
						system("pause");
						break;	
							
					case 5:
						system("cls");
						printf("==============================================================================\n");
						printf("                      Editing Contact Number of User %d                       \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Contact Number: ");
						scanf(" %[^\n]s\n", Users[index].contact);
						printf(" New Contact Number: %s\n", Users[index].contact);
						system("pause");
						break;
						
					case 6:
						system("cls");
						printf("==============================================================================\n");
						printf("                            Editing Sex of User %d                            \n", ID);
						printf("==============================================================================\n");
					
							do 
							{	
								printf(" Enter a New Sex: ");
						        scanf(" %[^\n]s", Users[index].sex);
						        for (i = 0; i < strlen(Users[index].sex); i++) 
						            Users[index].sex[i] = tolower(Users[index].sex[i]);
						        
						    } while (strcmp(Users[index].sex, "male") != 0 && strcmp(Users[index].sex, "female") != 0);
						printf(" New Sex: %s\n", Users[index].sex);
						system("pause");
						break;
						
					case 7:
						system("cls");
						printf("==============================================================================\n");
						printf("                       Editing First Dose Date of User %d                     \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Date of First Dose: ");
						scanf(" %[^\n]s\n", Users[index].dose1date);
						printf(" New First Dose Date: %s\n", Users[index].dose1date);
						system("pause");
						break;
					
					case 8:
						system("cls");
						printf("==============================================================================\n");
						printf("                     Editing First Dose Vaccine of User %d                    \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New First Dose Vaccine: ");
						scanf(" %[^\n]s\n", Users[index].dose1vax);
						printf(" New First Dose Vaccine: %s\n", Users[index].dose1vax);
						system("pause");
						break;
						
					case 9:
						system("cls");
						printf("==============================================================================\n");
						printf("                     Editing First Dose Location of User %d                    \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New First Dose Location: ");
						scanf(" %[^\n]s\n", Users[index].dose1loc);
						printf(" New First Dose Location: %s\n", Users[index].dose1loc);
						system("pause");
						break;
					
					case 10:
						system("cls");
						printf("==============================================================================\n");
						printf("                      Editing Second Dose Date of User %d                     \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Date of Second Dose: ");
						scanf(" %[^\n]s\n", Users[index].dose2date);
						printf(" New Second Dose Date: %s\n", Users[index].dose2date);
						system("pause");
						break;
						
					case 11:
						system("cls");
						printf("==============================================================================\n");
						printf("                    Editing Second Dose Vaccine of User %d                    \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Second Dose Vaccine: ");
						scanf(" %[^\n]s\n", Users[index].dose2vax);
						printf(" New Second Dose Vaccine: %s\n", Users[index].dose2vax);
						system("pause");
						break;	
					
					case 12:
						system("cls");
						printf("==============================================================================\n");
						printf("                    Editing Second Dose Location of User %d                   \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Second Dose Location: ");
						scanf(" %[^\n]s\n", Users[index].dose2loc);
						printf(" New Second Dose Location: %s\n", Users[index].dose2loc);
						system("pause");
						break;
					
					case 13:
						system("cls");
						printf("==============================================================================\n");
						printf("                     Editing Booster Dose Date of User %d                     \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Date of Booster Dose: ");
						scanf(" %[^\n]s\n", Users[index].boosterdate);
						printf(" New Booster Dose Date: %s\n", Users[index].boosterdate);
						system("pause");
						break;
						
					case 14:
						system("cls");
						printf("==============================================================================\n");
						printf("                    Editing Booster Dose Vaccine of User %d                    \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Booster Dose Vaccine: ");
						scanf(" %[^\n]s\n", Users[index].boostervax);
						printf(" New Booster Dose Vaccine: %s\n", Users[index].boostervax);
						system("pause");
						break;	
					
					case 15:
						system("cls");
						printf("==============================================================================\n");
						printf("                    Editing Booster Dose Location of User %d                   \n", ID);
						printf("==============================================================================\n");
						printf(" Enter a New Booster Dose Location: ");
						scanf(" %[^\n]s\n", Users[index].boosterloc);
						printf(" New Booster Dose Location: %s\n", Users[index].boosterloc);
						system("pause");
						break;
					
					case 16:
						system("cls");
		           		printf("==============================================================================\n");
		  				printf ("                          Returning to [Edit Users]                          \n");
		  				printf("==============================================================================\n");
			            system("pause");
			            break;
			            
					case 17:
						system("cls");
			           	printf("==============================================================================\n");
		  				printf ("                         Returning to [Manage Users]                         \n");
		  				printf("==============================================================================\n");
			           	system("pause");
			           	break;
				}
				
			} while (option != 16 && option != 17);
		}
			
	} while (option != 17 && ID != -999);	
	
	if (ID == -999)
	{
		system("cls");
		printf("==============================================================================\n");
		printf ("                         Returning to [Manage Users]                         \n");
		printf("==============================================================================\n");
		system("pause");
	}
	
}

void AdminDeleteUser(UR_Array Users, int *nUsers, int *pUser)
{
    int admin, i, UID, valid, index;
    char option, del;

	admin = Users[0].userID;
		
    do 
	{
    	do
    	{
	    	valid = 0;
	        system("cls");
	        displayAdminDeleteUser();
	        printf(" Enter a User ID to delete (Enter -999 to exit): ");
	        scanf("%d", &UID);
	
	        for (i = 0; i < *nUsers; i++) {
	            if (Users[i].userID == UID) {
	                valid = 1;
	                index = i;
	                i = 500;
	            }
	        }
	
	        if (valid == 0 && UID != -999) 
			{
	            system("cls");
	            printf("==============================================================================\n");
	            printf("                           Error: User ID not found                           \n");
	            printf("==============================================================================\n");
	            system("pause");
	        }
	        
	        if (UID == admin)
	        {
	        	system("cls");
	            printf("==============================================================================\n");
	            printf("                  Error: You cannot delete the Administrator                  \n");
	            printf("==============================================================================\n");
	            system("pause");
			}
	        
			if (valid == 1 && UID != admin)
			{
				printf(" Do you wish to delete User %d? (Y/N): ", UID);
		        scanf(" %c", &del);
		
		        if (del == 'Y') 
				{
		            for (i = index; i < *nUsers - 1; i++) // index = 1, nUsers = 2
		                Users[i] = Users[i + 1]; 
		        
		            (*nUsers)--;
		            printf(" User %d has been deleted.\n", UID);
					printf(" Do you wish to delete another user? (Y/N): ");
					scanf(" %c", &option);
		        }
		        else
		        {
		        	printf(" Please re-enter a User ID\n ");
		        	system("pause");
				}
			}
		} while (UID != -999 && valid != 0 && UID == admin);
    } while (option != 'N' && UID != -999);
    
    if (option == 'N' || UID == -999)
    {
    	system("cls");
		printf("==============================================================================\n");
		printf ("                         Returning to [Manage Users]                         \n");
		printf("==============================================================================\n");
		system("pause");
	}
    
}

void AdminUserManage (UR_Array Users, int *nUsers, int *pUser)
{
	int option;
	
	do
	{
		system("cls");
		AdminUserMan (); // display function
  		printf(" Enter Option: ");
  		scanf("%d", &option);
  		
  		switch (option)
  		{
  			case 1:
			  	system("cls");
			  	AdminAddUser(Users, nUsers);
			  	break;
  			
  			case 2:
			  	system("cls");
			  	ViewAllUsers(Users, nUsers);
			  	break;
			  
			case 3:
				system("cls");
			  	AdminEditUser(Users, nUsers, pUser);
			  	break;
			  	
			case 4:
				system("cls");
			  	AdminDeleteUser(Users, nUsers, pUser);
			  	break;  	
			
			case 5:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                     Returning to [Data Management Menu]                     \n");
  				printf("==============================================================================\n");
	            system("pause");
	            break;
			
			default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
		}
  			
	} while (option != 5);
}

void AdminAddApp (UR_Array Users, int *nUsers, VA_Array App, int *nApp, VA_Array newApp)
{
	int valid, ID, i = 0, check, index;
		
	do
	{	
		system("cls");
		displayAppReq(); 
		printf(" Whose appointment is this for? (Enter User ID): ");
		scanf("%d", &ID);
		for (i = 0; i < *nUsers; i++)
			if(Users[i].userID == ID)
			{
				check = 1;
				index = i;
				i = 500;
			}
							
		if (check == 0 && ID != -999)
		{
			system("cls");
			printf("==============================================================================\n");
			printf("                           Error: User ID not found                           \n");
			printf("==============================================================================\n");
			system("pause");
		}
			
	} while (check != 1 && ID != -999);
	
	App[*nApp].UID = ID; // registers appointment to (user id)
	
	if (check == 1 && ID != -999)
	{
		do
		{
			system("cls");
			displayAppReq(); 
			valid = 1;
			printf(" Enter Appointment ID: ");
			scanf("%d", &ID);
			
			for (i = 0; i < *nApp; i++)
				if(App[i].appID == ID)
					valid = 0;	
			if (valid == 0)
			{
				system("cls");
				displayLine();
				printf("                     This Appointment ID is already taken!                    \n");
				displayLine();
				system("pause");
			}
		} while (valid != 1 && ID != -999);
		
		App[*nApp].appID = ID;
		
		printf(" Enter your Name: ");
		scanf(" %[^\n]s", App[*nApp].name);
		printf(" Enter the Location of your Vaccination: ");
		scanf(" %[^\n]s", App[*nApp].location);
		printf(" Enter the Vaccine Brand you wish to take: ");
		scanf(" %[^\n]s", App[*nApp].vaccine);
		printf(" Enter the Date of your Vaccination (YYYY-MM-DD): ");
		scanf(" %[^\n]s", App[*nApp].date);
		printf(" Enter the Time of your Vaccination: ");
		scanf(" %[^\n]s", App[*nApp].time);
		printf(" Enter the Dose of your Vaccination (First, Second, or Booster): ");
		scanf(" %[^\n]s", App[*nApp].dose);
		
		system("cls");
		printf("==============================================================================\n");
  		printf ("                        Registered Appointment Information                   \n");
  		printf("==============================================================================\n");
  		printf("  Appointment for User %d\n", App[*nApp].UID);
  		printf("  Appointment ID: %d\n", App[*nApp].appID);
  		printf("  Name: %s\n", App[*nApp].name);
  		printf("  Location %s\n", App[*nApp].location);
  		printf("  Vaccine Brand: %s\n", App[*nApp].vaccine);
  		printf("  Date: %s\n", App[*nApp].date);
  		printf("  Time: %s\n", App[*nApp].time);
  		printf("  Dose: %s\n ", App[*nApp].dose);
  		system("pause");
  		
		(*nApp)++; // increases new user
	}
	
	else if (ID == -999)
	{
		system("cls");
	    printf("==============================================================================\n");
  		printf ("                       Returning to [Manage Appointments]                    \n");
  		printf("==============================================================================\n");
	    system("pause");
	}
	
}

void ViewAllApps(VA_Array App, int *nApp)
{
	int i;
	
	if (*nApp != 0)
	{
		system("cls");
	    printf("==========================================================\n");
	    printf("| %-10s | %-15s | %-10s | %-10s |\n", "User ID", "Appointment ID", "Name", "Location");
	    printf("==========================================================\n");
		for (i = 0; i < *nApp; i++)
			printf("| %-10d | %-15d | %-10s | %-10s |\n", App[i].UID, App[i].appID, App[i].name, App[i].location);	
		printf("==========================================================\n");
		printf("\n");
		printf("==========================================================\n");
	    printf("| %-10s | %-15s | %-10s | %-10s |\n", "Vaccine", "Date", "Time", "Dose");
	    printf("==========================================================\n");
	    for (i = 0; i < *nApp; i++)
	    	printf("| %-10s | %-15s | %-10s | %-10s |\n", App[i].vaccine, App[i].date, App[i].time, App[i].dose);
		printf("==========================================================\n");
		system("pause");
	}
	else
	{
		system("cls");
		printf("==============================================================================\n");
		printf("                          Error: Appointments not found                       \n");
		printf("==============================================================================\n");
		system("pause");
	}
	
}

void AdminEditApp (UR_Array Users, int *nUsers, VA_Array App, int *nApp)
{
	int i, ID, valid, option, index, num = 0, check, temp;
	int newID;
	char pwd[20];
	char ch;
	
	do
	{
		do
		{
			valid = 0;
			system("cls");
			displayAdminEditApp();
			printf(" Enter the Appointment ID you wish to edit (Enter -999 to exit): ");
			scanf("%d", &ID);
			
			for (i = 0; i < *nApp; i++)
				if(App[i].appID == ID)
				{
					valid = 1;
					index = i;
					i = 500;
				}
					
			if (valid == 0 && ID != -999)
			{
				system("cls");
				printf("==============================================================================\n");
				printf("                            Error: App ID not found                           \n");
				printf("==============================================================================\n");
				system("pause");
			}
			
		} while (valid != 1 && ID != -999);
		
		if (valid == 1)
		{
			do
			{
				system("cls");
				displayEditAppOptions(ID);
				printf("  Enter Option: ");
				scanf("%d", &option);
				
				switch (option)
				{
					case 1:
						
						do
						{	
							system("cls");
							printf("==============================================================================\n");
							printf("                        Editing User ID of Appointment %d                     \n", ID);
							printf("==============================================================================\n");
							printf(" Enter New User ID (Enter -999 to exit): ");
							scanf("%d", &temp);
							for (i = 0; i < *nUsers; i++)
								if(Users[i].userID == temp)
								{
									check = 1;
									i = 500;
								}
												
							if (check == 0 && temp != -999)
							{
								system("cls");
								printf("==============================================================================\n");
								printf("                           Error: User ID not found                           \n");
								printf("==============================================================================\n");
								system("pause");
							}
								
						} while (check != 1 && temp != -999);
						if (check == 1 && temp != 999)
						{
							App[index].UID = temp;
							printf(" Appointment has been assigned to User %d\n ", App[index].UID);
							displayLine();
							system("pause");
						}
						break;
					
					case 2:
						
						do
						{
							valid = 1;
							system("cls");
							printf("==============================================================================\n");
							printf("                        Editing App ID of Appointment %d                      \n", ID);
							printf("==============================================================================\n");
							printf(" Enter New Appointment ID: ");
							scanf("%d", &newID);
							
							for (i = 0; i < *nApp; i++)
								if(App[i].appID == newID)
									valid = 0;
									
							if (valid == 0)
							{
								system("cls");
								displayLine();
								printf("                     This Appointment ID is already taken!                    \n");
								displayLine();
								system("pause");
							}
						} while (valid != 1 && ID != -999);
						
						App[index].appID = newID;
						ID = newID;
						printf(" New Appointment ID: %d\n", App[index].appID);
						displayLine();
						system("pause");
						break;
						
					case 3:
						system("cls");
						printf("==============================================================================\n");
						printf("                          Editing Name of Appointment %d                      \n", ID);
						printf("==============================================================================\n");
						printf(" Enter New Name: ");
						scanf(" %[^\n]s", App[index].name);
						printf(" New Name: %s\n ", App[index].name);
						displayLine();
						system("pause");
						break;
						
					case 4:
						system("cls");
						printf("==============================================================================\n");
						printf("                        Editing Location of Appointment %d                    \n", ID);
						printf("==============================================================================\n");
						printf(" Enter New Location: ");
						scanf(" %[^\n]s", App[index].location);
						printf(" New Location: %s\n ", App[index].location);
						displayLine();
						system("pause");
						break;
						
					case 5:
						system("cls");
						printf("==============================================================================\n");
						printf("                       Editing Vaccine Brand of Appointment %d                \n", ID);
						printf("==============================================================================\n");
						printf(" Enter New Vaccine Brand: ");
						scanf(" %[^\n]s", App[index].vaccine);
						printf(" New Vaccine Brand: %s\n ", App[index].vaccine);
						displayLine();
						system("pause");
						break;		
						
					case 6:
						system("cls");
						printf("==============================================================================\n");
						printf("                          Editing Date of Appointment %d                      \n", ID);
						printf("==============================================================================\n");
						printf(" Enter New Date of Appointment (YYYY-MM-DD): ");
						scanf(" %[^\n]s", App[index].date);
						printf(" New Appointment Date: %s\n ", App[index].date);
						displayLine();
						system("pause");
						break;
						
					case 7:
						system("cls");
						printf("==============================================================================\n");
						printf("                          Editing Time of Appointment %d                      \n", ID);
						printf("==============================================================================\n");
						printf(" Enter New Time of Appointment: ");
						scanf(" %[^\n]s", App[index].time);
						printf(" New Appointment Time: %s\n ", App[index].time);
						displayLine();
						system("pause");
						break;
						
					case 8:
						system("cls");
						printf("==============================================================================\n");
						printf("                                   Editing Dose                               \n");
						printf("==============================================================================\n");
						printf(" Enter Edited Dose: ");
						scanf(" %[^\n]s", App[index].dose);
						printf(" Edited Dose: %s\n ", App[index].dose);
						displayLine();
						system("pause");
						break;				
						
				}
			} while (option != 0 && option != 9);
		}
	} while (option != 0 && ID != -999);
	
	if (option == 0 || ID == -999)
	{
		system("cls");
	    printf("==============================================================================\n");
  		printf ("                       Returning to [Manage Appointments]                    \n");
  		printf("==============================================================================\n");
	    system("pause");
	}
}

void AdminDeleteApp (VA_Array App, int *nApp)
{
	int i, ID, valid, index;
	char option, del;
	
	do 
	{
    	do
    	{
	    	valid = 0;
	        system("cls");
	        displayAdminDeleteApp();
	        printf(" Enter the Appointment's App ID to delete (Enter -999 to exit): ");
	        scanf("%d", &ID);
	
	        for (i = 0; i < *nApp; i++) 
			{
	            if (App[i].appID == ID) 
				{
	                valid = 1;
	                index = i;
	                i = 500;
	            }
	        }
	
	        if (valid == 0 && ID != -999) 
			{
	            system("cls");
	            printf("==============================================================================\n");
	            printf("                           Error: Appointment not found                       \n");
	            printf("==============================================================================\n");
	            system("pause");
	        }
	        
			if (valid == 1)
			{
				printf(" Do you wish to delete Appointment %d? (Y/N): ", ID);
		        scanf(" %c", &del);
		
		        if (del == 'Y') 
				{
		            for (i = index; i < *nApp - 1; i++) // index = 1, nUsers = 2
		                App[i] = App[i + 1]; 
		        
		            (*nApp)--;
		            printf(" Appointment %d has been deleted.\n", ID);
					printf(" Do you wish to delete another Appointment? (Y/N): ");
					scanf(" %c", &option);
		        }
		        else
		        {
		        	printf(" Please re-enter an App ID\n ");
		        	system("pause");
				}
			}
		} while (ID != -999 && valid != 0 && option != 'N');
		
    } while (option != 'N' && ID != -999);
	
	if (option == 'N' || ID == -999)
    {
    	system("cls");
		printf("==============================================================================\n");
		printf ("                         Returning to [Manage Users]                         \n");
		printf("==============================================================================\n");
		system("pause");
	}
	
}

void AdminAppManage(UR_Array Users, int *nUsers, VA_Array App, int *nApp, VA_Array newApp)
{
	int option;
	do
	{
		system("cls");
		AdminAppMan (); // display function
  		printf(" Enter Option: ");
  		scanf("%d", &option);
  		
  		switch (option)
  		{
  			case 1:
			  	system("cls");
			  	AdminAddApp(Users, nUsers, App, nApp, newApp);
			  	break;
  			
  			case 2:
			  	system("cls");
			  	ViewAllApps(App, nApp);
			  	break;
			  
			case 3:
				system("cls");
			  	AdminEditApp(Users, nUsers, App, nApp);
			  	break;
			  	
			case 4:
				system("cls");
			  	AdminDeleteApp(App, nApp);
			  	break;  	
			
			case 5:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                     Returning to [Data Management Menu]                     \n");
  				printf("==============================================================================\n");
	            system("pause");
	            break;
			
			default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
		}
  			
	} while (option != 5);
}

void AdminAddChat (char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	char option;
	do
	{
		Question[*nQuestion] = malloc(1000);
		Answer[*nAnswer] = malloc(1000);
		system("cls");
		displayAdminAddQA();
		printf(" Enter New Question: ");
		scanf(" %[^\n]s", Question[*nQuestion]);
		printf(" New Question [%s] has been added!\n", Question[*nQuestion]);
		displayLine();
		printf(" Enter New Answer: ");
		scanf(" %[^\n]s", Answer[*nAnswer]);
		printf(" New Answer [%s] has been added!\n", Answer[*nAnswer]);
		displayLine();
		printf(" Do you wish to add another Question & Answer? (Y/N): ");
		scanf(" %c", &option);
		
		(*nQuestion)++;
		(*nAnswer)++;
		
	} while (option != 'N');
	
	if (option == 'N')
	{
		system("cls");
		printf("==============================================================================\n");
		printf ("                         Returning to [Manage Chatbot]                       \n");
		printf("==============================================================================\n");
		system("pause");
	}
	
}

void ViewAllChats (char *Question[], char *Answer[], int*nQuestion, int *nAnswer)
{
	int i;
	system("cls");
	printf("==============================================================================\n");
  	printf ("                             All Questions & Answers                         \n");
  	printf("==============================================================================\n");
	for (int i = 0; i < *nQuestion; i++) 
	{
        printf("Question %d: %s\n", i+1, Question[i]);
        printf("Answer %d: %s\n", i+1, Answer[i]);
        printf("\n");
    }
    system("pause");
	
}

void EditQuestion(char *Question[], int *nQuestion)
{
	int ID, valid;
	char response;
	do
	{
		valid = 0;
		system("cls");
		printf("==============================================================================\n");
  		printf ("                                  Edit Questions                             \n");
  		printf("==============================================================================\n");
  		printf(" Enter Question Number you wish to edit (Enter -999 to exit): ");
  		scanf("%d", &ID);
  		
  		if (ID >= 0 && ID <= *nQuestion)
  		{
  			ID--;
  			valid = 1;
  			do
  			{
  				printf(" Do you wish to edit this Question?\n");
  				printf(" [%s]\n", Question[ID]);
  				printf(" Response (Y/N): ");
  				scanf(" %c", &response);
  				
  				if (response == 'Y')
  				{
  					printf(" Please enter the Edited Question: ");
  					scanf(" %[^\n]s", Question[ID]);
  					printf(" Here is the Edited Question: [%s]\n ", Question[ID]);
  					system("pause");
				}
			} while (response != 'Y' && response != 'N');
			
			if (response == 'N')
			{
				system("cls");
				printf("==============================================================================\n");
				printf ("                        Please input another Question Number                 \n");
				printf("==============================================================================\n");
				system("pause");
			}
		}
		else if (ID >= 0 && ID <= *nQuestion && ID != -999)
		{
			system("cls");
	        printf("==============================================================================\n");
	        printf("                         Error: Question Number does not exist                \n");
	        printf("==============================================================================\n");
	        system("pause");
		}
  		
	} while (ID != -999);
}

void EditAnswer(char *Answer[], int *nAnswer)
{
	int ID, valid;
	char response;
	do
	{
		valid = 0;
		system("cls");
		printf("==============================================================================\n");
  		printf ("                                  Edit Answers                               \n");
  		printf("==============================================================================\n");
  		printf(" Enter Answer Number you wish to edit (Enter -999 to exit): ");
  		scanf("%d", &ID);
  		
  		if (ID >= 0 && ID <= *nAnswer)
  		{
  			ID--;
  			valid = 1;
  			do
  			{
  				printf(" Do you wish to edit this Answer?\n");
  				printf(" [%s]\n", Answer[ID]);
  				printf(" Response (Y/N): ");
  				scanf(" %c", &response);
  				
  				if (response == 'Y')
  				{
  					printf(" Please enter the Edited Answer: ");
  					scanf(" %[^\n]s", Answer[ID]);
  					printf(" Here is the Edited Answer: [%s]\n ", Answer[ID]);
  					system("pause");
				}
			} while (response != 'Y' && response != 'N');
			
			if (response == 'N')
			{
				system("cls");
				printf("==============================================================================\n");
				printf ("                        Please input another Answer Number                   \n");
				printf("==============================================================================\n");
				system("pause");
			}
		}
		else if (ID >= 0 && ID <= *nAnswer && ID != -999)
		{
			system("cls");
	        printf("==============================================================================\n");
	        printf("                         Error: Answer Number does not exist                  \n");
	        printf("==============================================================================\n");
	        system("pause");
		}
  		
	} while (ID != -999);
}

void AdminEditChat (char *Question[], char *Answer[], int*nQuestion, int *nAnswer)
{
	int option;
	
	do
	{
		system("cls");
		displayAdminEditChat();
		printf(" Enter Option: ");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				EditQuestion(Question, nQuestion);
				break;
			case 2:
				EditAnswer(Answer, nAnswer);
				break;
			case 3:
				system("cls");
				printf("==============================================================================\n");
				printf ("                         Returning to [Manage Chatbot]                       \n");
				printf("==============================================================================\n");
				system("pause");
				break;
			default:
				system("cls");
		        printf("==============================================================================\n");
	  			printf ("                      Error: Please input a valid option                     \n");
	  			printf("==============================================================================\n");
		        system("pause");	
		}
	} while (option != 3);
}

void AdminDeleteChat (char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	int i, ID;
	char response, option;
	do
	{
		system("cls");
		displayAdminDeleteChat();
		printf(" Enter the Question & Answer's Number to delete (Enter -999 to exit): ");
		scanf("%d", &ID);
		
		if (ID >= 0 && ID <= *nQuestion)
		{
			ID--;
			system("cls");
			displayAdminDeleteChat();
			printf(" Do you wish to delete this Question & Answer?\n");
			printf(" Question: [%s]\n Answer: [%s]\n", Question[ID], Answer[ID]);
			printf(" Response (Y/N): ");
			scanf(" %c", &response);
			
			if (response == 'Y')
			{
				for (i = ID; i < *nQuestion - 1; i++) // index = 1, nUsers = 2
		            strcpy(Question[i], Question[i + 1]);
		        (*nQuestion)--;
				for (i = ID; i < *nAnswer - 1; i++)
					strcpy(Answer[i], Answer[i + 1]);
				(*nAnswer)--;
				
				printf(" The Question & Answer you entered has been deleted!\n");
				printf(" Do you wish to delete another Question & Answer? (Y/N): ");
				scanf(" %c", &option);
			}
			if (option == 'Y' && ID != -999)
			{
				system("cls");
				printf("==============================================================================\n");
				printf ("                        Please input another Answer Number                   \n");
				printf("==============================================================================\n");
				system("pause");
			}
			else if (response == 'N')
			{
				system("cls");
				printf("==============================================================================\n");
				printf ("                        Please input another Answer Number                   \n");
				printf("==============================================================================\n");
				system("pause");
			}
		}
		else if (ID == -999)
		{
			system("cls");
			printf("==============================================================================\n");
			printf ("                         Returning to [Manage Chatbot]                       \n");
			printf("==============================================================================\n");
			system("pause");
		}
		
	} while (option != 'N' && ID != -999);
}

void AdminChatManage (char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	int option;
	
	do
	{
		system("cls");
		AdminChatMan (); // display function
  		printf(" Enter Option: ");
  		scanf("%d", &option);
  		
  		switch (option)
  		{
  			case 1:
			  	system("cls");
			  	AdminAddChat(Question, Answer, nQuestion, nAnswer);
			  	break;
  			
  			case 2:
			  	system("cls");
			  	ViewAllChats(Question, Answer, nQuestion, nAnswer);
			  	break;
			  
			case 3:
				system("cls");
			  	AdminEditChat(Question, Answer, nQuestion, nAnswer);
			  	break;
			  	
			case 4:
				system("cls");
			  	AdminDeleteChat(Question, Answer, nQuestion, nAnswer);
			  	break;  	
			
			case 5:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                     Returning to [Data Management Menu]                     \n");
  				printf("==============================================================================\n");
	            system("pause");
	            break;
			
			default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
		}
  			
	} while (option != 5);
}

void AdminImportUsers (UR_Array Users, int *nUsers)
{
	int User_File;
	User_File = Read_Users(Users, nUsers);
	
	if (User_File == 0)
		*nUsers = 0;
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                          User file has been imported!                       \n");
  	printf("==============================================================================\n");
	system("pause");
}

void AdminImportApps (VA_Array App, int *nApp)
{
	int App_File;
	App_File = Read_App(App, nApp);
	
	if (App_File == 0)
		*nApp = 0;
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                       Appointment file has been imported!                   \n");
  	printf("==============================================================================\n");
	system("pause");
}

void AdminImportChat (char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	int Chat_File;
	Chat_File = Read_Chat (Question, Answer, nQuestion, nAnswer);
	
	if (Chat_File == 0)
		{
			*nQuestion = 0;
			*nAnswer = 0;		
		}
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                         Chatbot file has been imported!                     \n");
  	printf("==============================================================================\n");
	system("pause");
}

void AdminImportFiles (UR_Array Users, int *nUsers, VA_Array App, int *nApp, VA_Array newApp, char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	int option;
	
	do
	{
		system("cls");
		displayImport();
		printf(" Enter Option: ");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				system("cls");
				AdminImportUsers (Users, nUsers);
				break;
			case 2:
				system("cls");
				AdminImportApps (App, nApp);
				break;
			case 3:
				system("cls");
				AdminImportChat (Question, Answer, nQuestion, nAnswer);
				break;
			case 4:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                     Returning to [Data Management Menu]                     \n");
  				printf("==============================================================================\n");
	            system("pause");
				break;
			default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
	            
		}
	} while (option != 4);
}

void AdminExportUsers (UR_Array Users, int *nUsers)
{
	int i, valid;
	FILE *fp;
	char *filename;
	
	filename = malloc(2000);
	
	do
	{
		system("cls");
		printf("==============================================================================\n");
	  	printf("                                Export User Data                              \n");
	  	printf("==============================================================================\n");
		printf(" Enter filename: ");
		scanf(" %[^\n]s", filename);
		
		if (strlen(filename) > 26)
		{
			valid = 0;
			system("cls");
			printf("==============================================================================\n");
	  		printf("         Error: Please input a filename with less than 30 characters          \n");
	  		printf("==============================================================================\n");
	  		system("pause");
		}
		else
			valid = 1;
		
	} while (valid != 1);
	
	
	fp = fopen(filename, "w");
	/*
	Format:
		UserID Password
		Name
		Address
		Contact
		Sex
		Location1 Date1 Vax1
		Location2 Date2 Vax2
		BoosterLoc DateBoost VaxBoost
	*/
	for (i = 0; i < *nUsers; i++)
	{
		fprintf(fp, "%d %s\n", Users[i].userID, Users[i].password);
		fprintf(fp, "%s\n", Users[i].name);
		fprintf(fp, "%s\n", Users[i].address);
		fprintf(fp, "%s\n", Users[i].contact);
		fprintf(fp, "%s\n", Users[i].sex);
		fprintf(fp, "%s %s %s\n", Users[i].dose1loc, Users[i].dose1date, Users[i].dose1vax);
		fprintf(fp, "%s %s %s\n", Users[i].dose2loc, Users[i].dose2date, Users[i].dose2vax);
		fprintf(fp, "%s %s %s\n\n", Users[i].boosterloc, Users[i].boosterdate, Users[i].boostervax);
	}
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                           User data has been exported!                      \n");
  	printf("==============================================================================\n");
	system("pause");
	
	fclose(fp);
}

void AdminExportApps (VA_Array App, int *nApp)
{
	int i, valid;
	FILE *fp;
	char *filename;
	
	filename = malloc(2000);
	
	do
	{
		system("cls");
		printf("==============================================================================\n");
	  	printf("                             Export Appointment Data                          \n");
	  	printf("==============================================================================\n");
		printf(" Enter filename: ");
		scanf(" %[^\n]s", filename);
		
		if (strlen(filename) > 26)
		{
			valid = 0;
			system("cls");
			printf("==============================================================================\n");
	  		printf("         Error: Please input a filename with less than 30 characters          \n");
	  		printf("==============================================================================\n");
	  		system("pause");
		}
		else
			valid = 1;
		
	} while (valid != 1);
	
	
	fp = fopen(filename, "w");
	/*
	Format:
		AppID UserId
		Name
		Location
		Vaccine
		Date
		Time
		Dose
		
	*/
	for (i = 0; i < *nApp; i++)
	{
		fprintf(fp, "%d %d\n", App[i].appID, App[i].UID);
		fprintf(fp, "%s\n", App[i].name);
		fprintf(fp, "%s\n", App[i].location);
		fprintf(fp, "%s\n", App[i].vaccine);
		fprintf(fp, "%s\n", App[i].date);
		fprintf(fp, "%s\n", App[i].time);
		fprintf(fp, "%s\n\n", App[i].dose);
	}
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                      Appointment data has been exported!                    \n");
  	printf("==============================================================================\n");
	system("pause");
	
	fclose(fp);
}

void AdminExportChat (char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	int i, valid;
	FILE *fp;
	char *filename;
	
	filename = malloc(2000);
	
	do
	{
		system("cls");
		printf("==============================================================================\n");
	  	printf("                             Export Appointment Data                          \n");
	  	printf("==============================================================================\n");
		printf(" Enter filename: ");
		scanf(" %[^\n]s", filename);
		
		if (strlen(filename) > 26)
		{
			valid = 0;
			system("cls");
			printf("==============================================================================\n");
	  		printf("         Error: Please input a filename with less than 30 characters          \n");
	  		printf("==============================================================================\n");
	  		system("pause");
		}
		else
			valid = 1;
		
	} while (valid != 1);
	
	
	fp = fopen(filename, "w");
	/*
	Format:
		Question1
		Answer1
		Question2
		Answer2
		
	*/
	for (i = 0; i < *nQuestion; i++)
	{
		fprintf(fp, "%s\n", Question[i]);
		fprintf(fp, "%s\n", Answer[i]);
	}
	
	system("cls");
	printf("==============================================================================\n");
  	printf ("                      Appointment data has been exported!                    \n");
  	printf("==============================================================================\n");
	system("pause");
	
	fclose(fp);
}

void AdminExportFiles (UR_Array Users, int *nUsers, VA_Array App, int *nApp, VA_Array newApp, char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	int option;
	
	do
	{
		system("cls");
		displayExport();
		printf(" Enter Option: ");
		scanf("%d", &option);
		
		switch (option)
		{
			case 1:
				system("cls");
				AdminExportUsers(Users, nUsers);
				break;
			case 2:
				system("cls");
				AdminExportApps(App, nApp);
				break;
			case 3:
				system("cls");
				AdminExportChat(Question, Answer, nQuestion, nAnswer);
				break;
			case 4:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                     Returning to [Data Management Menu]                     \n");
  				printf("==============================================================================\n");
	            system("pause");
				break;
			default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
	            
		}
	} while (option != 4);
	
}

void DataManagement (UR_Array Users, int *nUsers, VA_Array App, int *nApp, VA_Array newApp, char *Question[], char *Answer[], int *nQuestion, int *nAnswer)
{
	int i, option, login, valid, UID, attempt = 1, User, index = 0;
	*nApp = 0;
	*nQuestion = 0;
	*nAnswer = 0;
	char *Pass, ch;
	char pwd[20];
	Pass = malloc(11 * sizeof(char));
	
	time_t now = time(NULL);
	struct tm *currentTime = localtime(&now);
	
	do
	{
		system("cls");
		printf("==============================================================================\n");
  		printf("                              Administrator Login                             \n");
  		printf("==============================================================================\n");
		printf("  1) Login                                                                    \n");
		printf("  2) Exit to [Main Menu]                                                      \n");
		printf("==============================================================================\n");
		printf(" Enter Option: ");
		scanf("%d", &login);
		
	} while (login != 1 && login != 2);
	
	if (login == 2)
		{
			system("cls");
	        printf("==============================================================================\n");
  			printf ("                           Returning to [Main Menu]                          \n");
  			printf("==============================================================================\n");
	        system("pause");
		}
	else
	{
		do
		{
			valid = 0;
			
			if (attempt == 4)
				valid = 2;
				
			else
			{
				// User ID input
				system("cls");
			    printf("==============================================================================\n");
		  		printf("                              Administrator Login                             \n");
		  		printf("==============================================================================\n");
				printf(" Please login (Enter -999 and any Password to exit)\n");
				printf(" Attempt: %d\n", attempt);
				printf(" User ID (Numerical Input): ");
				scanf("%d", &UID); // 122
				
				// Password input
				printf(" Password: ");
				
				index = 0;
				memset(pwd, 0, sizeof(pwd)); // sets all pwd elements to 0 (for resetting purposes)
				
				while ((ch = getch()) != '\r') 
				{
				    if (ch == '\b' && index > 0) 
					{
				        index--;
				        pwd[index] = '\0';
				        printf("\b \b");  // erase the asterisk
				    }
				    else if (isalnum(ch) && index < 19) 
					{
				        pwd[index] = ch;
				        index++;
				        printf("*");
				    }
				}
				
				pwd[index] = '\0';
				strcpy(Pass, pwd);
				
				if (UID == Users[0].userID && strcmp(Users[0].password, Pass) == 0)
				{
					User = UID;
					valid = 1;
				}	
				
				if (valid != 1 && valid != 2 && UID != -999)
				{
					system("cls");
					system("cls");
	            	printf("==============================================================================\n");
	  				printf ("      Error: The User ID and Password you entered is not an Administrator    \n");
	  				printf("==============================================================================\n");
	            	system("pause");;
					system("cls");
				}
				else if (UID == -999)
				{
					system("cls");
			        printf("==============================================================================\n");
		  			printf ("                           Returning to [Main Menu]                          \n");
		  			printf("==============================================================================\n");
			        system("pause");
				}	
			}	
			attempt++;
		} while (valid != 1 && valid != 2 && UID != -999);
		
		if (valid == 1)
		{
			system("cls");
		    printf("==============================================================================\n");
	  		printf ("                            Welcome Administrator!                           \n");
	  		printf("==============================================================================\n");
			system("pause");
			
			do 
			{
		        system("cls");
		        displayDataMan();
		        printf(" Current date and time: %s", asctime(currentTime));
		        printf(" Administrator User ID: %d\n", User);
		        printf(" Enter Option: ");
		        scanf(" %d", &option);
		        
		        switch (option) {
		            case 1:
		                system("cls");
		                AdminUserManage(Users, nUsers, &User); // done!!
		                break;
		            case 2:
		                system("cls");
		                AdminAppManage(Users, nUsers, App, nApp, newApp);
		                break;
		            case 3:
		                system("cls");
		                AdminChatManage(Question, Answer, nQuestion, nAnswer);
		                break;
		            
					case 4:
		                system("cls");
						AdminImportFiles(Users, nUsers, App, nApp, newApp, Question, Answer, nQuestion, nAnswer);
		                break;
						
					case 5:
		                system("cls");
		                AdminExportFiles(Users, nUsers, App, nApp, newApp, Question, Answer, nQuestion, nAnswer);
		                break;	    
		                
		            case 6:
		                system("cls");
		                printf("==============================================================================\n");
		                printf("                            Returning to [Main Menu]                          \n");
		                printf("==============================================================================\n");
		                system("pause");
		                break;
		                
		            default:
		                system("cls");
		                printf("==============================================================================\n");
		                printf("                       Error: Please input a valid option                     \n");
		                printf("==============================================================================\n");
		                system("pause");
		        }
		
		    } while (option != 6);
		}
		
		else if (valid == 2)
		{
			system("cls");
			printf("==============================================================================\n");
  			printf ("           You have used up all of your attempts. Please login again         \n");
  			printf("==============================================================================\n");
			system("pause");
		}
	} // end of else statement
} // end of function

int Read_Admin (UR_Array Users, int *nUsers)
{
	char *WordList[1000], *temp, *tempword;
	int i, j, line, valid, x, num;
	FILE *fp;
	
	fp = fopen("Users.txt", "r");
	
	for (i = 0; i < 1000; i++)
		WordList[i] = malloc(31*sizeof(char));
		
	temp = malloc(1000 * sizeof(char));
	
	if (fgets(temp, 1000, fp) == NULL)
		valid = 0;
	else
	{
		line = 1;
		j = 0;
		fseek(fp, 0, SEEK_SET);
		while (line != 10)
		{
			fgets(temp, 1000, fp);
			if (line % 9 == 2 || line % 9 == 3 || line % 9 == 4)
			{
				tempword = strtok(temp, "\n");
				strcpy(WordList[j], tempword);
				j++;
			}
			else
			{
				tempword = strtok(temp, " \n");
				while (tempword != NULL)
				{
					strcpy(WordList[j], tempword);
					tempword = strtok(NULL, " \n");
					j++;
				}
			}
			line++;
		}
		
		valid = 1;
		*nUsers = j / 15;
		
		for (i = 0, j = 0; i < *nUsers; i++)
			for (x = 0; x < 15; x++, j++)
				switch(j % 15)
				{
					case 0:
						num = atoi(WordList[j]);
						Users[0].userID = num;
						break;
					case 1:
						strcpy(Users[i].password, WordList[j]);
						break;
					case 2:
						strcpy(Users[i].name, WordList[j]);
						break;
					case 3:
						strcpy(Users[i].address, WordList[j]);
						break;
					case 4:
						strcpy(Users[i].contact, WordList[j]);
						break;
					case 5:
						strcpy(Users[i].sex, WordList[j]);
						break;
					case 6:
						strcpy(Users[i].dose1loc, WordList[j]);
						break;
					case 7:
						strcpy(Users[i].dose1date, WordList[j]);
						break;
					case 8:
						strcpy(Users[i].dose1vax, WordList[j]);
						break;
					case 9:
						strcpy(Users[i].dose2loc, WordList[j]);
						break;
					case 10:
						strcpy(Users[i].dose2date, WordList[j]);
						break;
					case 11:
						strcpy(Users[i].dose2vax, WordList[j]);
						break;
					case 12:
						strcpy(Users[i].boosterloc, WordList[j]);
						break;
					case 13:
						strcpy(Users[i].boosterdate, WordList[j]);
						break;
					case 14:
						strcpy(Users[i].boostervax, WordList[j]);
						break;
				}
	}		
	for (i = 0; i < 1000; i++)
		free(WordList[i]);
		
	free(temp);
	fclose(fp);
	
	return valid;	
}

int main ()
{
	UR_Array Users;
	VA_Array App;
	VA_Array newApp;
	char *Question[1000];
	char *Answer[1000];
	int i, menu, *nUsers = 0, *nApp = 0, *nQuestion = 0, *nAnswer = 0, Admin, User_File, App_File, Chat_File;
    
    nUsers = malloc(sizeof(int));
    nApp = malloc(sizeof(int));
    nQuestion = malloc(sizeof(int));
    nAnswer = malloc(sizeof(int));
    
    Admin = Read_Admin(Users, nUsers);
    
    // Troubleshoot
    
//	printf("Chat_File: %d\n", Chat_File);
//	
//		for (int i = 0; i < *nQuestion; i++) {
//            printf("Question %d: %s\n", i+1, Question[i]);
//            printf("Answer %d: %s\n", i+1, Answer[i]);
//        }
//       
//	printf("  Administrator:\n");
//  	printf("  UserID: %d\n", Users[0].userID);
//	printf("  Pass: %s\n", Users[0].password);
//	printf("  Name: %s\n", Users[0].name);
//	printf("  Address: %s\n", Users[0].address);
//	printf("  Contact Number: %s\n", Users[0].contact);
//	printf("  Sex: %s\n", Users[0].sex);
//	printf("  Dose 1 Date: %s\n", Users[0].dose1date);
//	printf("  Dose 1 Vax: %s\n", Users[0].dose1vax);
//	printf("  Dose 1 Location: %s\n", Users[0].dose1loc);
//	printf("  Dose 2 Date: %s\n", Users[0].dose2date);
//	printf("  Dose 2 Vax: %s\n", Users[0].dose2vax);
//	printf("  Dose 2 Location: %s\n", Users[0].dose2loc);
//	printf("  Booster Date: %s\n", Users[0].boosterdate);
//	printf("  Booster Vax: %s\n", Users[0].boostervax);
//	printf("  Booster Location: %s\n\n", Users[0].boosterloc);
//	printf("  nUsers: %d", *nUsers);
//	getch();
	
	do
	{
	
//		printf("nQuestion: %d\n", *nQuestion);
//        printf("nAnswer: %d\n", *nAnswer);
//        getch();
		system("cls");
		displayMainMenu(&menu);
		
		switch (menu)
		{
			case 1:
				system("cls");
				VaxRegMenu(Users, nUsers, App, nApp, newApp, Question, Answer, nQuestion, nAnswer);
				break;
			case 2:
				system("cls");
				DataManagement(Users, nUsers, App, nApp, newApp, Question, Answer, nQuestion, nAnswer);
				break;
			case 3:
				system("cls");
        			printf("==============================================================================\n");
  					printf ("                  Thank you for using the Animo Vax Program!                 \n");
  					printf ("                          Stay safe and God bless!                           \n");
  					printf("==============================================================================\n");
        			system("pause");
				break;
			default:
				system("cls");
	            printf("==============================================================================\n");
  				printf ("                      Error: Please input a valid option                     \n");
  				printf("==============================================================================\n");
	            system("pause");
		
		}
	} while (menu != 3);
	
	return 0;
}
