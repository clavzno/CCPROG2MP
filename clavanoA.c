/*************
CCPROG2 S18 GROUP <NUMBER>
Name: Clavano, Angelica Therese I.
Date created: 2023-02-22
Last modified: 2023-02-23

Notes: (1) won't run in Repl.it console, (2) vsCode Terminal won't show flashing colors, (3) Win11 Terminal shows no difference between bold and non-bold colors.
(4) exe file crashes when manually selected. (5) runs when F11 in devc++
*************/

#include <stdio.h>
#include <string.h>
#include <unistd.h> //Required for the display_loading function, alternate is <windows.h>

/* Define directives for cosmetic purposes in the program such as the
main menu and headers when under a certain module. */
// \e == (Esc)ape code, [ for ANSI code, m for end of ANSI code
#define ANSI_FLASH_RED "\e[0;6;31m"
#define ANSI_FLASH_BLUE "\e[0;6;34m"
#define ANSI_FLASH_WHITE "\e[0;6;1m"
#define ANSI_RED "\e[0;31m"
#define ANSI_BLUE "\e[0;34m"
#define ANSI_WHITE "\e[0;1m"
#define ANSI_YELLOW "\e[0;93m" // menu 1: vaccination registration
#define ANSI_GREEN "\e[0;92m"  // menu 2: data management
#define ANSI_CYAN "\e[0;96m"   // menu 3: settings
#define ANSI_OFF "\e[0m"	   // removes ANSI code and restores to default text
// COLOR_OFF to end command; 1 = bold, 5 = slow blink, X = color, m = end of ANSI code
#define ANSI_

/* Define directives for max users since dynamic memory allocation is hard */
#define MAX_USERS 100

/* Struct delcaration format of user */
struct user
{
	int userID;
	int contact;
	char password[11];
	char name[21];
	char address[31];
	char sex[11];
	char dose1_date[11];
	char dose1_type[11];
	char dose1_loc[11];
	// Optional
	/* note: prompt user if they have more than 1 dose, if 0, set all to N/A */
	char dose2_date[11];
	char dose2_type[11];
	char dose2_loc[11];
	char dose3_date[11];
	char dose3_type[11];
	char dose3_loc[11];
};

struct settings
{
	int remove_blinking;
	int language;
	int bg_color;
};

/* Extra: Loading Screen Simulation */
/* requires <unistd.h>/<windows.h> for sleep */
void display_loading()
{
	int i, j, a;

	printf("Loading");

	for (i = 0; i <= 6; i++)
	{
		for (j = 0; sleep(1); j++) // sleep delays the printing of "." for 1sec
			j = a;
		printf(".");
	}
	printf("\n");

	system("cls"); // clears the screen
}
/* Below are subfunctions/menus to be called to preserve code readability. The
programmer is aware of the amount of pointer variables to be passed within these
subfunctions. */
/* Checks if the ID entered was taken */
int vaxreg_userreg_checkID(struct user *Profiles, int *num_usersptr, int tempid)
{
    for (int i = 0; i < *num_usersptr; i++) {
        if (Profiles[i].userID == tempid) {
            return 1; // ID is taken
        }
    }
    return 0; // ID is not taken	
}

/* Iterates through profiles and checks if userID = 0, if true, return i to be used for profile */
int vaxreg_userreg_checkifempty(struct user *Profiles, int *num_usersptr)
{
    for (int i = 0; i < *num_usersptr; i++) {
        if (Profiles[i].userID == 0) {
            return i; // return index of empty profile
        }
    }
    return -1; // no empty profile found	
}

/* Main vax registration */
void vaxreg_useregistration(struct user *Profiles, int *num_usersptr)
{
	int more_than_one_dose;
	int more_than_two_doses;
	char firstname[11];
	char lastname[11];
	int addnewuser;
	int i, j; // for iteration
	int n = 0; // for iteration
	int id = 0; // for checking if userID is already taken
	printf("You are in User Registration.\n");

	// if addnewuser == 1, then add new user
	// iterate through the array of structs and check if userID is already taken
	// if userID is already taken, prompt user to enter a new userID
	// if userID is not taken, then add new user
	// if addnewuser == 0, then exit to main menu

	printf("Add new user? (1 for yes, 0 for no): ");
	scanf("%d", &addnewuser);

	do
	{
		if (*num_usersptr < MAX_USERS) // if number of users is less than 100
		{
			for (i = n; i < MAX_USERS; i++) // if there are enough users, iterate through the array of structs
			{
				if (Profiles[i].userID != 0) // if profile userID has data
				{
					printf("Profile %d has data. Moving to next profile...\n", i);
					n++;
				}

				else if (Profiles[i].userID == 0) // if profile userID is empty
				{
					for (i = n; i < *num_usersptr; i++) // iterate through the array of structs
					{
						// prompt user for input and store it in the struct
						printf("Empty profile %d found. Adding new user...\n", i);
						printf(ANSI_BLUE "Enter user data:\n" ANSI_OFF);

						// entering userID 
						while (id == 0)
						{
							printf("Enter userID: ");
							scanf("%d", &Profiles[i].userID);

							//check if userID was already taken by checking each profile
							for (int j = 0; j < i; j++)
							{
								if (Profiles[i].userID == Profiles[j].userID) // if userID is already taken
								{
									printf(ANSI_RED "Error: userID already taken.\n" ANSI_OFF);
									Profiles[i].userID = 0; // reset userID to 0
									id = 0;
								}
								else
								{
									printf(ANSI_BLUE "User ID added successfully.\n" ANSI_OFF);
									id = 1;
								}
							}
						}

						printf("Enter contact number: ");
						scanf("%d", &Profiles[i].contact);
						printf("Enter password:" ANSI_BLUE " 10 characters max" ANSI_OFF);
						scanf("%s", Profiles[i].password);
						// Entering full name
						printf("Enter your first name: ");
						scanf("%s", firstname);
						printf("Enter your last name: ");
						scanf("%s", lastname);
						strcat(Profiles[i].name, firstname);
						strcat(Profiles[i].name, " ");
						strcat(Profiles[i].name, lastname);
						fflush(stdin); // clears the buffer because of the newline character
						// Entering address
						printf("Enter address: ");
						// Note: skips fgets() and goes straight to scanf() if you enter a space
						fgets(Profiles[i].address, 31, stdin); // fgets is used to read strings with spaces
						printf("Enter sex [M/F]: ");
						scanf("%s", Profiles[i].sex);
						printf("Enter date of your first dose: ");
						printf(ANSI_BLUE "Date format: 2023-03-16 " ANSI_OFF);
						scanf("%s", Profiles[i].dose1_date);
						printf("Enter brand of vaccine: ");
						scanf("%s", Profiles[i].dose1_type);
						printf("Enter location of first dose: ");
						scanf("%s", Profiles[i].dose1_loc);
						printf("Do you have more than 1 dose? (1 for yes, 0 for no): ");
						scanf("%d", &more_than_one_dose);

						if (more_than_one_dose == 1)
						{
							printf("Enter date of your second dose: ");
							printf(ANSI_BLUE "Date format: 2023-03-16 " ANSI_OFF);
							scanf("%s", Profiles[i].dose2_date);
							printf("Enter brand of vaccine: ");
							scanf("%s", Profiles[i].dose2_type);
							printf("Enter location of second dose: ");
							scanf("%s", Profiles[i].dose2_loc);
							printf("Do you have more than 2 doses? (0/1): ");
							scanf("%d", &more_than_two_doses);

							if (more_than_two_doses == 1)
							{
								printf("Enter date of your third dose: ");
								printf(ANSI_BLUE "\nDate format: 2023-03-16 " ANSI_OFF);
								scanf("%s", Profiles[i].dose3_date);
								printf("Enter brand of vaccine: ");
								scanf("%s", Profiles[i].dose3_type);
								printf("Enter location of second dose: ");
								scanf("%s", Profiles[i].dose3_loc);
							}
							else
							{
								// set dose3 fields to "N/A"
								strcpy(Profiles[i].dose3_date, "N/A");
								strcpy(Profiles[i].dose3_type, "N/A");
								strcpy(Profiles[i].dose3_loc, "N/A");
							}
						}
						else
						{
							// set dose2 and dose3 fields to "N/A"
							strcpy(Profiles[i].dose2_date, "N/A");
							strcpy(Profiles[i].dose2_type, "N/A");
							strcpy(Profiles[i].dose2_loc, "N/A");
							strcpy(Profiles[i].dose3_date, "N/A");
							strcpy(Profiles[i].dose3_type, "N/A");
							strcpy(Profiles[i].dose3_loc, "N/A");
						}

						/* if (Profiles.userID || Profiles.contact ||
						Profiles.password || Profiles.name || Profiles.address || Profiles.sex || Profiles.dose1_date || Profiles.dose1_type || Profiles.dose1_loc == "exit" || "Exit")
						{
							printf(ANSI_FLASH_RED "User profile incomplete. Please try again.\n" ANSI_OFF);
							(*num_usersptr)--;
							printf("Number of users %d", *num_usersptr);
						} */
					} // end for

					(*num_usersptr)++;
					printf("Add new user? (1 for yes, 0 for no): ");
					scanf("%d", &addnewuser);
				}
			}
		}
	} while (addnewuser == 1); // while addnewuser is 1
}

void vaxreg_vaxappointment(struct user *Profiles, int *num_usersptr)
{
	printf("You are in Vaccination Appointment.\n");
}
void vaxreg_faqs(struct user *Profiles, int *num_usersptr)
{
	printf("You are in FAQs.\n");
}
int vaxreg_exit(struct user *Profiles, int *num_usersptr)
{
	system("cls");
	return 0;
}

/* Called when "Vaccination Registration" option is chosen by user */
void menu_vaxregistration(struct user *Profiles, int *num_usersptr)
{
	int choice;
	printf("**************************\n");
	printf("\n");
	printf(ANSI_YELLOW "Vaccination Registration\n" ANSI_OFF);
	printf("\n");
	printf("Select Option:\n");
	printf("[1] User Registration\n");
	printf("[2] Create Vaccine Appointment\n");
	printf("[3] FAQs\n");
	printf("[4] Exit\n");
	printf("\n");
	printf("**************************\n");
	printf("\n");
	printf("Enter choice: ");
	scanf("%d", &choice);
	printf("\n");

	switch (choice)
	{
	case 1: // user registration
		vaxreg_useregistration(Profiles, num_usersptr);
		break;
	case 2: // vaccine appointment
		vaxreg_vaxappointment(Profiles, num_usersptr);
		break;
	case 3: // FAQs
		vaxreg_faqs(Profiles, num_usersptr);
		break;
	case 4: // exit
		vaxreg_exit(Profiles, num_usersptr);
		break;
	default:
		printf("Invalid input. Please try again.\n");
	}
}

/* During Vaccination Registration and Data Management, the values in selected
user and appointment files are saved, preserved, and can be edited. Every chatbot
interaction including questions and answers are saved and preserved. */
void generate_userfile(struct user *Profiles)
{
	printf("Added to user file.\n");
}
void generate_appointmentfile(struct user *Profiles)
{
	printf("Added to appointment file.\n");
}
void generate_chatfile(struct user *Profiles)
{
	printf("Conversation has been added to chat file.");
}

/* Called when "Manage Data" option is chosen by the user */
void menu_datamanagement(struct user *Profiles, int *num_usersptr)
{
	printf("You are in Data Management.\n");
}
/* Below are subfunctions/menus to be called to preserve code readability. The
programmer is aware of the amount of pointer variables to be passed within these
subfunctions. */
void data_user() {}
void data_appt() {}
void data_chatbot() {}
void data_export() {}
void data_import() {}
void data_exit() {}

/* Extra: Called when "Accessibility" option is chosen by the user */
void menu_accessibilty() {} // allows for options to remove
/* Below are subfunctions/menus to be called to preserve code readability. The
programmer is aware of the amount of pointer variables to be passed within these
subfunctions. */
void acc_removeblinking() {} // allows user to remove flashing colors
void acc_language() {}		 // allows user to choose between english and filipino
void acc_bgcolor() {}		 // allows user to choose between darkmode and lightmode for the terminal

/* Displays main menu offering 2 options: Vaccination Registration Menu
("Vaccination Registration") and Data Management Menu ("Manage Data") */
int menu_main(struct user *Profiles, int *num_usersptr, struct settings *setptr)
{
	int choice;
	printf("**************************\n");
	printf("\n");
	printf(ANSI_WHITE "Welcome to" ANSI_OFF ANSI_FLASH_RED " Vax" ANSI_OFF ANSI_FLASH_BLUE "Bot" ANSI_OFF ANSI_FLASH_WHITE "PH!" ANSI_OFF "\n");
	printf("\n");
	printf("Select Menu:\n");
	printf("[1] Vaccination Registration\n");
	printf("[2] Manage Data\n");
	printf("[3] Accessibility\n");
	printf("[4] Exit\n");
	printf("\n");
	printf("**************************\n");
	printf("\n");
	printf("Enter choice: ");
	scanf("%d", &choice);
	printf("\n");

	switch (choice)
	{
	case 1: // vax registration
		menu_vaxregistration(Profiles, num_usersptr);
		break;
	case 2: // manage data
		menu_datamanagement(Profiles, num_usersptr);
		break;
	case 3: // accessibility
		menu_accessibilty(setptr);
		break;
	case 4: // exit
		break;
	default:
		printf("Invalid input. Please try again.\n");
	}
}

/***********************************************************************/
/* Driver code */
int main()
{
	struct user Profiles[MAX_USERS]; // array of user profiles
	struct user *ptr = Profiles;	 // pointer to Profiles to access values
	struct settings Settings;
	struct settings *setptr = &Settings; // pointer to Settings to access values

	int num_users = 0;				// we know the max size but we don't know the number of users
	int *num_usersptr = &num_users; // pointer to num_users to access value of users thus far

	// note use malloc to add new user space?
	// display_loading();
	menu_main(ptr, num_usersptr, setptr);
	return 0;
}