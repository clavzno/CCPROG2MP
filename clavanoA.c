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
#define ANSI_OFF "\e[0m" //removes ANSI code and restores to default text
// COLOR_OFF to end command; 1 = bold, 5 = slow blink, X = color, m = end of ANSI code

/* Define directives for max users since dynamic memory allocation is hard */
#define MAX_USERS 100

/* Extra: Loading Screen Simulation */
/* requires <unistd.h>/<windows.h> for sleep */
void
display_loading()
{
	int i, j, a;

	printf("Loading");
 
	for (i = 0; i <= 6; i++)
	{
		for (j = 0; sleep(1); j++) //sleep delays the printing of "." for 1sec
			j = a;
		printf(".");
	}
	printf("\n");

    system("cls"); //clears the screen
}




/* Called when "Vaccination Registration" option is chosen by user */
void
menu_vaxregistration(struct User Profiles)
{
	printf("You are in Vaccination Registrsation and Data Management.\n");
}
/* Below are subfunctions/menus to be called to preserve code readability. The
programmer is aware of the amount of pointer variables to be passed within these
subfunctions. */
void
vaxreg_useregistration(struct User Profiles) {
	printf("You are in User Registration.\n");
}
void
vaxreg_vaxappointment(struct User Profiles) {
	printf("You are in Vaccination Appointment.\n");
}
void
vaxreg_faqs(struct User Profiles) {
	printf("You are in FAQs.\n");
}
void
vaxreg_exit(struct User Profiles) {
	system("cls");
	menu_main();
}



/* During Vaccination Registration and Data Management, the values in selected
user and appointment files are saved, preserved, and can be edited. Every chatbot
interaction including questions and answers are saved and preserved. */
void
generate_userfile(struct User Profiles) {
	printf("Added to user file.\n");
}
void
generate_appointmentfile(struct User Profiles) {
	printf("Added to appointment file.\n");
}
void
generate_chatfile(struct User Profiles) {
	printf("Conversation has been added to chat file.");
}




/* Called when "Manage Data" option is chosen by the user */
void
menu_datamanagement(struct User Profiles)
{
	printf("You are in Data Management.\n");
}
/* Below are subfunctions/menus to be called to preserve code readability. The
programmer is aware of the amount of pointer variables to be passed within these
subfunctions. */
void
data_user() {}
void
data_appt() {}
void
data_chatbot() {}
void
data_export() {}
void
data_import() {}
void
data_exit() {}




/* Extra: Called when "Accessibility" option is chosen by the user */
void 
menu_accessibilty() {} //allows for options to remove
/* Below are subfunctions/menus to be called to preserve code readability. The
programmer is aware of the amount of pointer variables to be passed within these
subfunctions. */
void acc_removeblinking() {} //allows user to remove flashing colors
void acc_language() {} //allows user to choose between english and filipino
void acc_bgcolor() {} //allows user to choose between darkmode and lightmode for the terminal

/* Displays main menu offering 2 options: Vaccination Registration Menu
("Vaccination Registration") and Data Management Menu ("Manage Data") */
int
menu_main(struct User Profiles)
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
		case 1:
			menu_vaxregistration(Profiles);
			break;
		case 2:
			menu_datamanagement(Profiles);
			break;
		case 3:
			menu_accessibilty(Profiles);
			break;
		case 4:
			//exit(0); //NOTE: EXIT IS NOT ALLOWED
			return 0;
			break;
		default:
			printf("Invalid input. Please try again.\n");
	}
}


/***********************************************************************/
/* Driver code */
int
main()
{
	struct user
	{
		int userID, contact;
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

	struct user Profiles[MAX_USERS];

	/* int userID, contact;
		int *userIDptr = &userID;
		int *contactptr = &contact;
	char password[11];
		char *passwordptr;
	char name[21];
		char *namePtr = &name;
	char address[31];
		char *addressptr = &address;
	char sex[11];
		char *sexptr = &sex;
	char dose1_date[11];
		char *dose1_dateptr = &dose1_date;
	char dose1_type[11];
		char *dose1_typeptr = &dose1_type;
	char dose1_loc[11];
		char *dose1_locptr = &dose1_loc;
	char dose2_date[11];
	char dose2_type[11];
	char dose2_loc[11];
	char dose3_date[11];
	char dose3_type[11];
	char dose3_loc[11]; */

	// note use malloc to add new user space?
	display_loading();
	menu_main(Profiles);
	return 0;
}