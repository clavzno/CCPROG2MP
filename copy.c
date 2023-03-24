/*************
CCPROG2 S18 GROUP <NUMBER>
Name: Clavano, Angelica Therese I.
Date created: 2023-02-22
Last modified: 2023-03-20

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
#define ANSI_RED "\e[0;31m"  // FOR ERRORS
#define ANSI_BLUE "\e[0;34m" // FOR TIPS
#define ANSI_WHITE "\e[0;1m"
#define ANSI_YELLOW "\e[0;93m" // menu 1: vaccination registration
#define ANSI_GREEN "\e[0;92m"  // menu 2: data management
#define ANSI_CYAN "\e[0;96m"   // menu 3: settings
#define ANSI_OFF "\e[0m"       // removes ANSI code and restores to default text
// COLOR_OFF to end command; 1 = bold, 5 = slow blink, X = color, m = end of ANSI code
#define ANSI_PREVLINE "\e[1A" // moves cursor to previous line

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
    int i;
    for (i = 0; i < *num_usersptr; i++)
    {
        if (Profiles[i].userID == tempid)
        {
            return 1; // found a matching id
        }
    }
    return 0; // no matching id found
}

/* Iterates through profiles and checks if userID = 0, if true, return index */
int vaxreg_userreg_checkifempty(struct user *Profiles, int *num_usersptr)
{
    int i;
    for (i = 0; i <= *num_usersptr; i++)
    {
        if (Profiles[i].userID == 0)
        {
            return i; // return index of empty profile
        }
    }
    return -1; // no empty profile found
}

int vaxreg_userreg_checkpasswordlen(char *password)
{
    int i;
    for (i = 0; i < 11; i++)
    {
        if (password[i] == '\0')
        {
            return i; // return length of password
        }
    }
    return 11; // password is too long
}

/* Main vax registration */
int vaxreg_useregistration(struct user *Profiles, int *num_usersptr)
{
    int second_dose, third_dose;
    char firstname[11];
    char lastname[11];
    /* Temporary variables to be used in the function */
    int tempid = 0;       // used in vaxreg_userreg_checkID
    int addnewuser = 0;   // stores the user's choice to add a new user
    int emptyprofile = 0; // stores the return value of vaxreg_userreg_checkifempty
    int idcheck = 0;      // stores the return value of vaxreg_userreg_checkID
    int passcheck = 0;
    printf("You are in User Registration.\n");
    fflush(stdin);

    if (*num_usersptr < MAX_USERS)
    {
        printf("There are %d users.\n", *num_usersptr);
        printf("Add new user? (1 for yes, 0 for no):");
        scanf("%d", &addnewuser);

        if (addnewuser == 1)
        {
            emptyprofile = vaxreg_userreg_checkifempty(Profiles, num_usersptr);

            if (emptyprofile < 0)
            {
                printf("No empty profile found.\n");
                return 0;
            }

            else
            {
                printf(ANSI_GREEN "Empty profile found at index %d.\n" ANSI_OFF, emptyprofile);

                /* int userID */
                printf("Enter user ID: ");
                scanf("%d", &tempid);
                idcheck = vaxreg_userreg_checkID(Profiles, num_usersptr, tempid);

                while (idcheck > 0)
                {
                    printf(ANSI_RED "Error: userID already taken in Profile %d.\n" ANSI_OFF, idcheck);
                    tempid = 0;
                    printf("Enter user ID: ");
                    scanf("%d", &tempid);
                    idcheck = vaxreg_userreg_checkID(Profiles, num_usersptr, tempid);
                }

                printf(ANSI_GREEN "userID is available.\n" ANSI_OFF);
                Profiles[emptyprofile].userID = tempid;

                /* int contact */
                printf("Enter contact number: ");
                scanf("%d", &Profiles[emptyprofile].contact);

                do
                {
                    printf("Enter password:" ANSI_BLUE " 10 characters max " ANSI_OFF);
                    scanf("%s", Profiles[emptyprofile].password);
                    passcheck = vaxreg_userreg_checkpasswordlen(Profiles[emptyprofile].password);

                    if (passcheck > 10)
                        printf(ANSI_RED "Error: Password is too long.\n" ANSI_OFF);

                } while (passcheck > 10);

                printf(ANSI_GREEN "Password is valid." ANSI_OFF);
                sleep(2);
                printf("\r");

                /* char name [21] */
                printf("Enter your first name: ");
                scanf("%s", firstname);
                firstname[strcspn(firstname, "\n")] = '\0'; // remove newline character
                printf("Enter your last name: ");
                scanf("%s", lastname);
                lastname[strcspn(lastname, "\n")] = '\0'; // remove newline character
                strcat(Profiles[emptyprofile].name, firstname);
                strcat(Profiles[emptyprofile].name, " ");
                strcat(Profiles[emptyprofile].name, lastname);
                fflush(stdin); // clears the buffer because of the newline character

                /* char address[31] */

                /* char sex[11] */

                /* char dose1_date[11] */

                /* char dose1_type[11] */

                /* char dose1_loc[11] */

                /* PROMPT FOR MORE DOSES */
            }
        }
        else
            return 0;
    }

    else if (*num_usersptr == MAX_USERS)
    {
        printf("There are %d users.\n", *num_usersptr);
        printf("Maximum number of users reached.\n");
        return 0;
    }
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
void acc_language() {}       // allows user to choose between english and filipino
void acc_bgcolor() {}        // allows user to choose between darkmode and lightmode for the terminal

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
            system("cls");
            menu_vaxregistration(Profiles, num_usersptr);
            break;
        case 2: // manage data
            system("cls");
            menu_datamanagement(Profiles, num_usersptr);
            break;
        case 3: // accessibility
            system("cls");
            menu_accessibilty(setptr);
            break;
        case 4: // exit
            break;
        default:
            system("cls");
            printf("Invalid input. Please try again.\n");
        }
}

/***********************************************************************/
/* Driver code */
int main()
{
    struct user Profiles[MAX_USERS]; // array of user profiles
    struct user *ptr = Profiles;     // pointer to Profiles to access values
    struct settings Settings;
    struct settings *setptr = &Settings; // pointer to Settings to access values

    int num_users = 0;              // we know the max size but we don't know the number of users
    int *num_usersptr = &num_users; // pointer to num_users to access value of users thus far

    // note use malloc to add new user space?
    // display_loading();
    menu_main(ptr, num_usersptr, setptr);
    return 0;
}