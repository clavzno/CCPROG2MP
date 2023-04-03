/* Library declarations */
#include <stdio.h>
#include <string.h>
#include <unistd.h> //Required for the display_loading function, alternate is <windows.h>

/* Define directives for max users since dynamic memory allocation is hard */
#define MAX_USERS 100

/* Necessary Typedef declarations */
typedef char Str6[7];
typedef char Str10[11];
typedef char Str20[21];
typedef char Str30[31];
typedef char QnA[81]; // for faq

/* Struct Declarations */
struct appointment {
  int appID;
  int userID;
  Str20 name;
  Str20 location;
  Str10 vaccine;
  Str10 date;
  Str6 time;
  Str10 dose;
};

struct faq {
  QnA question;
  QnA answer;
};

struct user {
  int userID;
  int contact;
  Str10 password;
  Str20 name;
  Str30 address;
  Str10 sex;
  Str10 dose1_date;
  Str10 dose1_type;
  Str10 dose1_loc;
  // Optional
  /* note: prompt user if they have more than 1 dose, if 0, set all to N/A */
  Str10 dose2_date;
  Str10 dose2_type;
  Str10 dose2_loc;
  Str10 dose3_date;
  Str10 dose3_type;
  Str10 dose3_loc;

  struct appointmentdetails appointments;
  struct chathistory faq;
};

/* UI Functions and define directives */
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
// COLOR_OFF to end command; 1 = bold, 5 = slow blink, X = color, m = end of
// ANSI code
#define ANSI_PREVLINE "\e[1A" // moves cursor to previous line

/**********************************************/
/*Display Functions*/

/* requires <unistd.h>/<windows.h> for sleep */
void displayLoading() {
  int i, j, a;

  printf("Loading");

  for (i = 0; i <= 6; i++) {
    for (j = 0; sleep(1); j++) // sleep delays the printing of "." for 1sec
      j = a;
    printf(".");
  }
  printf("\n");

  system("cls"); // clears the screen
}

void displayLine_ast() { printf("**************************\n"); }

void displayLine_dash() {
  printf("\n------------------------------------------\n");
}

/**********************************************/

/* Function Prototypes */
void checkEmpty(); // checks for empty profile and returns iteration for direct
                   // manipulation of that index
void checkID();       // checks for any repeated IDs
void checkPassword(); // makes the user confirm their entered password

// I. Main Menu:
void mainmenu(struct *userProfilesptr, struct *userAmountptr);
  // Vaccination Registration Menu
  void registration(struct *userProfilesptr);
    // 1. User Registration
    void reg_User();
    // 2. Vaccination Appointment
    void reg_Appt();
    // 3. Chatbot FAQs
    void reg_Chat();
    // 4. Exit      
    void reg_Exit();
  // II. Data Management Menu
  void management();
    // 1.0 User
    void mng_User();
      // 1.1 Add new user
      void mng_User_Add();
      // 1.2 View all users
      void mng_User_View();
      // 1.3 Edit User details
      void mng_User_Edit();
      // 1.4 Delete User
      void mng_User_Delete();
      // 1.5 Exit (goes back to data management menu)
      void mng_User_Exit();
    // 2.0 Appointment
    void mng_appointment();
      // Add new appt (redundant with register?)
      // void mng_Appt_add()
      // View all appts
      void mng_Appt_View();
      // Edit Appt
      void mng_Appt_Edit();
      // Delete Appt
      void mng_Appt_Delete();
      // Exit (goes back to data management menu)
      void mng_Appt_Exit();
  //[Admin]Chatbot
  void mng_Chat();
    // Add New QnA
    // View all QnA
    // Delete QnA
    // Exit (goes back to data management menu)
  // Export
  void mng_Export();
  // Import
  void mng_Import();
  // Exit (saves all updates and terminates program)
  void mng_Exit();