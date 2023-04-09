/* LIBRARIES, DEFINE DIRECTIVES */
#include <stdio.h>
#include <stdlib.h> //for system("cls")
#include <string.h>
#include <unistd.h> //Required for the sleep() function, alternate is <windows.h>
#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_ANSWERS 10
#define MAX_APPOINTMENTS 10

/* TYPEDEFs */
typedef char Str6[7]; // 6 characters + null terminator
typedef char Str10[11]; // 10 characters + null terminator
typedef char Str20[21]; // 20 characters + null terminator
typedef char Str30[31]; // 30 characters + null terminator
typedef char QnA[81]; // 80 characters + null terminator

/* UI COLORS */
// \e == (Esc)ape code, [ for ANSI code, m for end of ANSI code
#define ANSI_WHITE "\e[0;1m"   // default
#define ANSI_RED "\e[0;31m"    // FOR ERRORS
#define ANSI_BLUE "\e[0;34m"   // FOR TIPS
#define ANSI_YELLOW "\e[0;93m" // menu 1: vaccination registration
#define ANSI_GREEN "\e[0;92m"  // menu 2: data management
#define ANSI_CYAN "\e[0;96m"   // menu 3: settings
#define ANSI_OFF "\e[0m"       // removes ANSI code and restores to default text

/* STRUCTS */
// stores appointment details per user
struct appointment
{
  int appID;
  Str20 location;
  Str10 vaccine, date, dose;
  Str6 time;
};

// stores chathistory per user
struct faq
{
  QnA question;
  QnA answer;
};

// main user profiles - structured by order of registration
struct user
{
  int userID;
  Str10 password;
  Str20 name;
  char contact[12];
  Str30 address;
  Str10 sex;
  Str10 dose1_date, dose1_type, dose1_loc;
  Str10 dose2_date, dose2_type, dose2_loc;
  Str10 dose3_date, dose3_type, dose3_loc;

  struct appointment appdetails[MAX_APPOINTMENTS];
  struct faq chathistory;
};

// empty struct
struct empty_struct
{
  int userID;
  Str10 password;
  Str20 name;
  char contact[12];
  Str30 address;
  Str10 sex;
  Str10 dose1_date, dose1_type, dose1_loc;
  Str10 dose2_date, dose2_type, dose2_loc;
  Str10 dose3_date, dose3_type, dose3_loc;

  struct appointment appdetails[MAX_APPOINTMENTS];
  struct faq chathistory;
};    

/************************************************************/

/* DISPLAY FUNCTIONS*/

/* requires <unistd.h>/<windows.h> for sleep */

void displayLoading()
{
  int i, j, a;

  printf("Loading program");

  for (i = 0; i <= 6; i++)
  {
    for (j = 0; sleep(1); j++) // sleep delays the printing of "." for 1sec
      // j = a;
      printf(".");
  }
  printf("\n");

  // clears the screen
}

void displayExit()
{
  int i, j, a;

  printf("Exiting program");

  for (i = 0; i <= 6; i++)
  {
    for (j = 0; sleep(1); j++) // sleep delays the printing of "." for 1sec
      // j = a; 
      printf(".");
  }
  printf("\n");

  // clears the screen
}

void displayExit_Admin()
{
  int i, j, a;

  printf("Saving your progress");

  for (i = 0; i <= 6; i++)
  {
    for (j = 0; sleep(1); j++) // sleep delays the printing of "." for 1sec
      j = a;
    printf(".");
  }
  printf("\n");

  // clears the screen
}

void displayLine_ast()
{
  printf("**********************************************************\n\n");
} // 58 characters

// Password Asterisk Function (hides password input)
void displayPassword_ast(Str10 password)
{
  int len = strlen(password);

  for (int i = 0; i < len; i++)
  {
    if (password[i] != ' ' && password[i] != '\n')
    {
      password[i] = '*';
    }
  }
}

/************************************************************/

/* Check Functions */

// Checks for iteration where there is an empty profile, returns index

int checkEmptyIndex(struct user *userProfilesptr, int *userAmountptr)
{
  int i;
  for (i = 0; i < *userAmountptr; i++)
  {
    if (userProfilesptr[i].userID == -1)
    {
      return i; // return index of non-empty profile
    }
  }
}

// Checks if entered ID is available, returns 1 if available, 0 if not - Note: each ID has to be unique
int checkID(struct user *userProfilesptr, int *userAmountptr, int tempid)
{
  int i;
  for (i = 0; i < *userAmountptr; i++)
  {
    if (userProfilesptr[i].userID == tempid)
    {
      return 1; // found a matching id (therefore unavailable)
    }
  }
  return 0; // no matching id found
}

int checkAIDIndex(struct user *userProfilesptr, int *userAmountptr, int tempid)
{
  int i;
  for (i = 0; i < *userAmountptr; i++)
  {
    if (userProfilesptr[i].userID == tempid)
    {
      return i; // found a matching id
    }
  }
  return -1; // no matching id found
}

// Appointment ID Check Function
int checkAID(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr, int tempid)
{
  int i, j;
  for (i = 0; i < *userAmountptr; i++)
    for (j = 0; j < *apptAmountptr; j++)
    {
      if (userProfilesptr[i].appdetails[j].appID == tempid)
      {
        return 1; // found a matching id
      }
    }
  return 0; // no matching id found
}

// Password Check Function (wip)
int checkPassword(char *password, char *confirmPass)
{
  if (strcmp(password, confirmPass) == 0)
  {
    return 1; // passwords match
  }
  else
  {
    printf(ANSI_RED "Error: Passwords do not match.\n" ANSI_OFF);
    // set confirmPass to null
    memset(password, 0, sizeof(password));
    memset(confirmPass, 0, sizeof(confirmPass));
    return 0; // passwords do not match
  }
}

// Erase all data (wip)
/* to check: can it be replaced with struct = empty_struct */
void setNull(struct user *userProfilesptr, int *userAmountptr)
{
  int i;
  for (i = 0; i < *userAmountptr; i++)
  {
    userProfilesptr[i].userID = 0;
    strcpy(userProfilesptr[i].password, "");
    strcpy(userProfilesptr[i].name, "");
    strcpy(userProfilesptr[i].contact, "");
    strcpy(userProfilesptr[i].address, "");
    strcpy(userProfilesptr[i].sex, "");
    strcpy(userProfilesptr[i].dose1_date, "");
    strcpy(userProfilesptr[i].dose1_type, "");
    strcpy(userProfilesptr[i].dose1_loc, "");
    strcpy(userProfilesptr[i].dose2_date, "");
    strcpy(userProfilesptr[i].dose2_type, "");
    strcpy(userProfilesptr[i].dose2_loc, "");
    strcpy(userProfilesptr[i].dose3_date, "");
    strcpy(userProfilesptr[i].dose3_type, "");
    strcpy(userProfilesptr[i].dose3_loc, "");
    memset(&userProfilesptr[i].appdetails, 0, sizeof(struct appointment));
    memset(&userProfilesptr[i].chathistory, 0, sizeof(struct faq));
  }
}

// Erase only appointment data (wip)
/* void clearAppointments(struct user *userProfile, int userID)
{
  int i;
  for (i = 0; i < MAX_APPOINTMENTS; i++)
  {
    userProfile[userID].appdetails->date[i] = NULL;
    strcpy(userProfile[userID].appdetails->time[i], "");
    strcpy(userProfile[userID].appdetails->location[i], "");
  }
  userProfile[userID].appdetails->numAppointments = 0;
} */

// Erase only chathistory (wip)
/*void clearChatHistory(struct user *userProfile, int userID)
{
  int i;
  for (i = 0; i < MAX_FAQ; i++)
  {
    strcpy(userProfile[userID].chathistory.question[i], "");
    strcpy(userProfile[userID].chathistory.answer[i], "");
  }
  userProfile[userID].chathistory.numFAQs = 0;
} */

/************************************************************/

/* FUNCTION PROTOTYPES */

// [0] MAIN MENU (in cdc.c)
//int mainmenu(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr);

/************************************************************/
// [1] VACCINATION REGISTRATION

// 1.1 User Registration
void reg_User(struct user *userProfilesptr, int *userAmountptr)
{

  // variable declarations
  int tempid = 0, idcheck = 0, passcheck = 0, userIndex;
  char firstname[11], lastname[11];
  int secondDose, thirdDose;
  char confirmPass[11];

  userIndex = checkEmptyIndex(userProfilesptr, userAmountptr);
  printf("Empty profile found at index %d\n", userIndex);

  printf("User Registration\n"
         "Please input the requested data.\n\n");

  // int userID
  do
  {
    printf("Enter User ID: ");
    scanf("%d", &tempid);
    idcheck = checkID(userProfilesptr, userAmountptr, tempid);

    if (idcheck > 0)
    {
      printf(ANSI_RED "Error: ID already taken.\n" ANSI_OFF);
    }
  } while (idcheck > 0);

  printf(ANSI_GREEN "Success: ID available\n" ANSI_OFF);
  userProfilesptr[userIndex].userID = tempid;
  printf("User ID: %d\n", userProfilesptr[userIndex].userID);

  // char password[11]
  
  do {
    printf("Enter your password: ");
    fgets(userProfilesptr[userIndex].password, 11, stdin);
    while(getchar() != '\n');
	
    printf("Please confirm your password: ");
    fgets(confirmPass, 11, stdin);
	while(getchar() != '\n');
	
    passcheck = checkPassword(userProfilesptr[userIndex].password, confirmPass);

    if (passcheck == 0)
    {
      printf(ANSI_RED "Error: Passwords do not match.\n" ANSI_OFF);
    }
	
  } while (passcheck == 0);

  printf(ANSI_GREEN "Success: Passwords match.\n" ANSI_OFF);
  printf("Confirmed Password: %s", userProfilesptr[userIndex].password);

  // str20 name
  printf("Enter your first name: ");
  fgets(firstname, 11, stdin);
  firstname[strlen(firstname) - 1] = '\0'; // remove newline character
  fflush(stdin);
  printf("\r\r");
  printf("Enter your last name: ");
  fgets(lastname, 11, stdin);
  lastname[strlen(lastname) - 1] = '\0'; // remove newline character
  fflush(stdin);
  printf("\r\r");
  strcat(userProfilesptr[userIndex].name, firstname); // add first name
  strcat(userProfilesptr[userIndex].name, " ");       // add space
  strcat(userProfilesptr[userIndex].name, lastname);  // add last name
  printf("Name: %s\n", userProfilesptr[userIndex].name);
  fflush(stdin); // clears the buffer because of the newline character

  // int contact
  printf("Enter your contact number:\n");
  fgets(userProfilesptr[userIndex].contact, 12, stdin);
  fflush(stdin);
  printf("Number: %s", userProfilesptr[userIndex].contact);

  // str30 address
  printf("Enter your address:\n");
  fgets(userProfilesptr[userIndex].address, 31, stdin);
  fflush(stdin);
  printf("\nAddress: %s", userProfilesptr[userIndex].address);

  // str10 sex [Male/Female]
  printf("Enter your sex " ANSI_BLUE "[Male/Female]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].sex, 11, stdin);
  fflush(stdin);
  printf("\nSex: %s", userProfilesptr[userIndex].sex);

  // str10 dose date
  printf("Enter date of first dose:\n");
  fgets(userProfilesptr[userIndex].dose1_date, 11, stdin);
  fflush(stdin);
  printf("\nFirst Dose Date: %s", userProfilesptr[userIndex].dose1_date);
  // str10 dose type
  printf("Enter type of first dose:\n");
  fgets(userProfilesptr[userIndex].dose1_type, 11, stdin);
  fflush(stdin);
  printf("First Dose Type: %s", userProfilesptr[userIndex].dose1_type);
  // str01 dose location
  printf("Enter location of first dose:\n");
  fgets(userProfilesptr[userIndex].dose1_loc, 11, stdin);
  fflush(stdin);
  printf("\nFirst Dose Location: %s", userProfilesptr[userIndex].dose1_loc);

  // prompt for second and third dose
  printf("Do you have a second dose? " ANSI_BLUE "[1/0]: " ANSI_OFF);
  scanf("%d", &secondDose);
  fflush(stdin);
  printf("\nSecond Dose Choice: %d", secondDose);

  if (secondDose == 1)
  {
    printf("Enter date of second dose:\n");
    fgets(userProfilesptr[userIndex].dose2_date, 11, stdin);
    fflush(stdin);
    printf("\nSecond Dose Date: %s", userProfilesptr[userIndex].dose2_date);

    // str10 dose type
    printf("Enter type of second dose:\n");
    fgets(userProfilesptr[userIndex].dose2_type, 11, stdin);
    fflush(stdin);
    printf("\nSecond Dose Type: %s", userProfilesptr[userIndex].dose2_type);
    // str10 dose location
    printf("Enter location of second dose:\n");
    fgets(userProfilesptr[userIndex].dose2_loc, 11, stdin);
    fflush(stdin);
    printf("\nSecond Dose Location: %s", userProfilesptr[userIndex].dose2_loc);

    // prompt for third dose
    printf("Do you have a third dose? " ANSI_BLUE "[1/0]: " ANSI_OFF);
    scanf("%d", &thirdDose);
    fflush(stdin);
    printf("\nThird Dose Choice: %d", thirdDose);

    if (thirdDose == 1)
    {
      printf("Enter date of third dose:\n");
      fgets(userProfilesptr[userIndex].dose3_date, 11, stdin);
      fflush(stdin);
      printf("\nThird Dose Date: %s", userProfilesptr[userIndex].dose3_date);
      // str10 dose type
      printf("Enter type of third dose:\n");
      fgets(userProfilesptr[userIndex].dose3_type, 11, stdin);
      fflush(stdin);
      printf("\nThird Dose Type: %s", userProfilesptr[userIndex].dose3_type);
      // str10 dose location
      printf("Enter location of third dose:\n");
      fgets(userProfilesptr[userIndex].dose3_loc, 11, stdin);
      fflush(stdin);
      printf("\nThird Dose Location: %s", userProfilesptr[userIndex].dose3_loc);
    }
    else
    {
      // set third dose to null
      memset(userProfilesptr[userIndex].dose3_date, 0, sizeof(userProfilesptr[userIndex].dose3_date));
      printf("\nThird Dose Date: %s", userProfilesptr[userIndex].dose3_date);
      memset(userProfilesptr[userIndex].dose3_type, 0, sizeof(userProfilesptr[userIndex].dose3_type));
      printf("\nThird Dose Type: %s", userProfilesptr[userIndex].dose3_type);
      memset(userProfilesptr[userIndex].dose3_loc, 0, sizeof(userProfilesptr[userIndex].dose3_loc));
      printf("\nThird Dose Location: %s", userProfilesptr[userIndex].dose3_loc);
    }
  }

  else
  {
    // set second dose to null
    memset(userProfilesptr[userIndex].dose2_date, 0, sizeof(userProfilesptr[userIndex].dose2_date));
    printf("\nSecond Dose Date: %s", userProfilesptr[userIndex].dose2_date);
    memset(userProfilesptr[userIndex].dose2_type, 0, sizeof(userProfilesptr[userIndex].dose2_type));
    printf("\nSecond Dose Type: %s", userProfilesptr[userIndex].dose2_type);
    memset(userProfilesptr[userIndex].dose2_loc, 0, sizeof(userProfilesptr[userIndex].dose2_loc));
    printf("\nSecond Dose Location: %s", userProfilesptr[userIndex].dose2_loc);
    memset(userProfilesptr[userIndex].dose3_date, 0, sizeof(userProfilesptr[userIndex].dose3_date));
    printf("\nThird Dose Date: %s", userProfilesptr[userIndex].dose3_date);
    memset(userProfilesptr[userIndex].dose3_type, 0, sizeof(userProfilesptr[userIndex].dose3_type));
    printf("\nThird Dose Type: %s", userProfilesptr[userIndex].dose3_type);
    memset(userProfilesptr[userIndex].dose3_loc, 0, sizeof(userProfilesptr[userIndex].dose3_loc));
    printf("\nThird Dose Location: %s", userProfilesptr[userIndex].dose3_loc);
  }
  userAmountptr++;
}

// 1.2 Vaccination Appointment Registration
void reg_Appt(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{
  fflush(stdin);
    
  // variable declarations
  int validID, validAID, tempID, tempAID;

  printf("Vaccine Appointment Registration\n"
         "Please input the requested data.\n"
         "Enter User ID:\n\n");

  // look for empty profile display index
  while (validID < 0)
  {
    printf("Enter your User ID below:\n> ");
    scanf("%d", &tempID);
    fflush(stdin);
    validID = checkAIDIndex(userProfilesptr, userAmountptr, tempID);

    if (validID < 0)
    {
      printf(ANSI_RED "Error: User does not exist. Enter a valid user ID "
                      "number.\n" ANSI_OFF);
    }
  }

  printf(ANSI_GREEN "Success: User exists." ANSI_OFF);

  // prompt for appointment ID
  while (validAID > 0)
  {
    printf("Enter your Appointment ID below:\n> ");
    scanf("%d", &tempAID);
    fflush(stdin);
    validAID = checkAID(userProfilesptr, userAmountptr, apptAmountptr, tempAID);

    if (validAID > 0)
    {
      printf(ANSI_RED "Error: Application ID already exists. Enter a valid appointment ID number.\n" ANSI_OFF);
    }
  }

  printf(ANSI_GREEN "Success: Application ID available." ANSI_OFF);
  userProfilesptr[validID].appdetails->appID = tempAID;

  // prompt for name, location, vaxx, date, time & dose. system cls and such WIP

  printf("\nEnter Location: ");
  scanf("%s", &userProfilesptr[validID].appdetails->location);
  fflush(stdin);
  printf("Location: %s", userProfilesptr[validID].appdetails->location);

  printf("\nEnter Vaccine: ");
  scanf("%s", &userProfilesptr[validID].appdetails->vaccine);
  fflush(stdin);
  printf("Vaccine: %s", userProfilesptr[validID].appdetails->vaccine);

  printf("\nEnter Date (YYYY-MM-DD): ");
  scanf("%s", &userProfilesptr[validID].appdetails->date);
  fflush(stdin);
  printf("Date: %s", userProfilesptr[validID].appdetails->date);

  printf("\nEnter Time (24HR Format): ");
  // COMMENT we could add a converter for 24hr format here
  scanf("%s", &userProfilesptr[validID].appdetails->time);
  fflush(stdin);
  printf("Time: %s", userProfilesptr[validID].appdetails->time);

  printf("\nEnter Dose [1st/2nd/3rd]: ");
  scanf("%s", &userProfilesptr[validID].appdetails->dose);
  fflush(stdin);
  printf("Dose: %s", userProfilesptr[validID].appdetails->dose);
}

/************************************************************/
// [2] CHATBOT/FAQS

// Sub function for printf questions
void chat_printquestions()
{
  printf("[1] Is Vaccination necessary?\n");
  printf("[2] What are the possible side effects of vaccination?\n");
  printf("[3] Am I still fully vaccinated if I don't have a third dose?\n");
  printf("[4] Do boosters use the same ingredients as the vaccine?\n");
  printf("[5] How do vaccines work?\n");
  printf("[6] Exit\n");
}

// Sub function for fprintf questions
void file_printquestions(FILE *fp)
{
  fprintf(fp, "[1] Is Vaccination necessary?\n");
  fprintf(fp, "[2] What are the possible side effects of vaccination?\n");
  fprintf(fp, "[3] Am I still fully vaccinated if I don't have a third dose?\n");
  fprintf(fp, "[4] Do boosters use the same ingredients as the vaccine?\n");
  fprintf(fp, "[5] How do vaccines work?\n");
  fprintf(fp, "[6] Exit\n");
}

// 2.1 Chatbot function
int reg_Chat(struct user *userProfilesptr, int *userAmountptr)
{
  FILE *fp;
  fp = fopen("chatlog.txt", "w");
  int choice;

  if (fp == NULL)
  {
    printf("Error opening file!\n");
    return 1;
  }

  fprintf(fp, "Welcome to the Chat Room!\n");
  printf("Welcome to the Chat Room!\n");
  fprintf(fp, "[Assistivax]: Hello, how may I help you today?\n\n");
  printf("[Assistivax]: Hello, how may I help you today?\n\n");
  chat_printquestions();
  file_printquestions(fp);

  scanf("%d", &choice);

  while (choice != 6)
  {
    switch (choice)
    {
    case 1:
    {
      printf("[You]: Is Vaccination necessary?\n");
      fprintf(fp, "[You]: Is Vaccination necessary?\n");
      printf("[Assistivax]: No, vaccination is not mandatory. But the government highly encourages the public to get vaccinated and be protected against preventable disease.\n");
      fprintf(fp, "[Assistivax]: No, vaccination is not mandatory. But the government highly encourages the public to get vaccinated and be protected against preventable disease.\n");
    }
    case 2:
    {
      printf("[You]: What are the possible side effects of vaccination?\n");
      fprintf(fp, "[You]: What are the possible side effects of vaccination?\n");
      printf("[Assistivax]: The possible side effects of a vaccine include pain, redness, itchiness or swelling at the injection site; fever; feeling of weakness or fatigue; headache; dizziness; diarrhea; or nausea. Consult the nearest healthcare professional if you experience any of these side effects.\n");
      fprintf(fp, "[Assistivax]: The possible side effects of a vaccine include pain, redness, itchiness or swelling at the injection site; fever; feeling of weakness or fatigue; headache; dizziness; diarrhea; or nausea. Consult the nearest healthcare professional if you experience any of these side effects.\n");
    }
    case 3:
    {
      printf("[You]: Am I still fully vaccinated if I don't have a third dose?\n");
      fprintf(fp, "[You]: Am I still fully vaccinated if I don't have a third dose?\n");
    }
    case 4:
    {
      printf("[You]: Do boosters use the same ingredients as the vaccine?\n");
      fprintf(fp, "[You]: Do boosters use the same ingredients as the vaccine?\n");
    }
    case 5:
    {
      printf("[You]: How do vaccines work?\n");
      fprintf(fp, "[You]: How do vaccines work?\n");
    }
    case 6:
    {
      printf("[You]: Exit\n");
      fprintf(fp, "[You]: Exit\n");
      return 0;
    }
    } // end switch
  }   // end while

  fclose(fp);
}

/************************************************************/
// [3] ADMIN/DATA MANAGEMENT

// MAIN MENU FOR ADMIN
// to grant access to the module, the user must log in using the userID and password (hidden)
// user is granted 3 attempts to log in, otherwise terminate program
int management(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr);



// 3.1 USER DATA MENU (in cdg.c)
//int mng_User(struct user *userProfilesptr, int *userAmountptr);

// Sub function: View User ID List
void mng_userView(struct user *userProfilesptr, int *userAmountptr)
{
  int i;
  printf("User ID List\n\n");
  for (i = 0; i < *userAmountptr; i++)
  {
    printf("User ID: %d\n", userProfilesptr[i].userID);
  }
}

// Sub function: Find Profile Iteration via User ID
int mng_userFind(struct user *userProfilesptr, int *userAmountptr, int ID)
{
  int i;
  for (i = 0; i < *userAmountptr; i++)
  {
    if (userProfilesptr[i].userID == ID)
    {
      return i;
    }
    else
    {
      printf(ANSI_RED "Error: User ID not found\n" ANSI_OFF);
      return 0;
    }
  }
}

// User Data > [1] Add new user
void mng_User_Add(struct user *userProfilesptr, int *userAmountptr)
{
  // variable declarations
  int tempid = 0, idcheck = 0, passcheck = 0, userIndex;
  char firstname[11], lastname[11];
  int secondDose, thirdDose;
  char confirmPass[11];

  userIndex = checkEmptyIndex(userProfilesptr, userAmountptr);
  printf("Empty profile found at index %d\n", userIndex);

  // int userID
  do
  {
    printf("Enter User ID:\n\n");
    scanf("%d", &tempid);
    idcheck = checkID(userProfilesptr, userAmountptr, tempid);

    if (idcheck > 0)
    {
      printf(ANSI_RED "Error: ID already taken.\n" ANSI_OFF);
    }
  } while (idcheck > 0);

  printf(ANSI_GREEN "Success: ID available\n" ANSI_OFF);
  userProfilesptr[userIndex].userID = tempid;
  printf("User ID: %d\n", userProfilesptr[userIndex].userID);

  // char password[11]
  
  while (passcheck == 0) 
  {
    printf("Enter user password:\n");
    fgets(userProfilesptr[userIndex].password, 11, stdin);
    userProfilesptr[userIndex].password[strcspn(userProfilesptr[userIndex].password, "\n")] = 0;
    
	printf("Please confirm user password: ");
    fgets(confirmPass, 11, stdin);
	confirmPass[strcspn(confirmPass, "\n")] = 0;	
	
    passcheck = checkPassword(userProfilesptr[userIndex].password, confirmPass);
  
  }

  printf(ANSI_GREEN "Success: Passwords match.\n" ANSI_OFF);
  printf("Confirmed Password: %s", userProfilesptr[userIndex].password);

  // str20 name
  printf("Enter your first name: ");
  fgets(firstname, 11, stdin);
  firstname[strlen(firstname) - 1] = '\0'; // remove newline character
  fflush(stdin);
  printf("\r\r");
  printf("Enter your last name: ");
  fgets(lastname, 11, stdin);
  lastname[strlen(lastname) - 1] = '\0'; // remove newline character
  fflush(stdin);
  printf("\r\r");
  strcat(userProfilesptr[userIndex].name, firstname); // add first name
  strcat(userProfilesptr[userIndex].name, " ");       // add space
  strcat(userProfilesptr[userIndex].name, lastname);  // add last name
  printf("Name: %s\n", userProfilesptr[userIndex].name);
  fflush(stdin); // clears the buffer because of the newline character

  // int contact
  printf("Enter your contact number:\n");
  fgets(userProfilesptr[userIndex].contact, 12, stdin);
  fflush(stdin);
  printf("Number: %s", userProfilesptr[userIndex].contact);

  // str30 address
  printf("Enter your address:\n");
  fgets(userProfilesptr[userIndex].address, 31, stdin);
  fflush(stdin);
  printf("\nAddress: %s", userProfilesptr[userIndex].address);

  // str10 sex [Male/Female]
  printf("Enter your sex " ANSI_BLUE "[Male/Female]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].sex, 11, stdin);
  fflush(stdin);
  printf("\nSex: %s", userProfilesptr[userIndex].sex);

  // str10 dose date
  printf("Enter date of first dose:\n");
  fgets(userProfilesptr[userIndex].dose1_date, 11, stdin);
  fflush(stdin);
  printf("\nFirst Dose Date: %s", userProfilesptr[userIndex].dose1_date);
  // str10 dose type
  printf("Enter type of first dose:\n");
  fgets(userProfilesptr[userIndex].dose1_type, 11, stdin);
  fflush(stdin);
  printf("First Dose Type: %s", userProfilesptr[userIndex].dose1_type);
  // str01 dose location
  printf("Enter location of first dose:\n");
  fgets(userProfilesptr[userIndex].dose1_loc, 11, stdin);
  fflush(stdin);
  printf("\nFirst Dose Location: %s", userProfilesptr[userIndex].dose1_loc);

  // prompt for second and third dose
  printf("Do you have a second dose? " ANSI_BLUE "[1/0]: " ANSI_OFF);
  scanf("%d", &secondDose);
  fflush(stdin);
  printf("\nSecond Dose Choice: %d", secondDose);

  if (secondDose = 1)
  {
    printf("Enter date of second dose:\n");
    fgets(userProfilesptr[userIndex].dose2_date, 11, stdin);
    fflush(stdin);
    printf("\nSecond Dose Date: %s", userProfilesptr[userIndex].dose2_date);

    // str10 dose type
    printf("Enter type of second dose:\n");
    fgets(userProfilesptr[userIndex].dose2_type, 11, stdin);
    fflush(stdin);
    printf("\nSecond Dose Type: %s", userProfilesptr[userIndex].dose2_type);
    // str10 dose location
    printf("Enter location of second dose:\n");
    fgets(userProfilesptr[userIndex].dose2_loc, 11, stdin);
    fflush(stdin);
    printf("\nSecond Dose Location: %s", userProfilesptr[userIndex].dose2_loc);

    // prompt for third dose
    printf("Do you have a third dose? " ANSI_BLUE "[1/0]: " ANSI_OFF);
    scanf("%d", &thirdDose);
    fflush(stdin);
    printf("\nThird Dose Choice: %d", thirdDose);

    if (thirdDose == 1)
    {
      printf("Enter date of third dose:\n");
      fgets(userProfilesptr[userIndex].dose3_date, 11, stdin);
      fflush(stdin);
      printf("\nThird Dose Date: %s", userProfilesptr[userIndex].dose3_date);
      // str10 dose type
      printf("Enter type of third dose:\n");
      fgets(userProfilesptr[userIndex].dose3_type, 11, stdin);
      fflush(stdin);
      printf("\nThird Dose Type: %s", userProfilesptr[userIndex].dose3_type);
      // str10 dose location
      printf("Enter location of third dose:\n");
      fgets(userProfilesptr[userIndex].dose3_loc, 11, stdin);
      fflush(stdin);
      printf("\nThird Dose Location: %s", userProfilesptr[userIndex].dose3_loc);
    }
    else
    {
      // set third dose to null
      memset(userProfilesptr[userIndex].dose3_date, 0, sizeof(userProfilesptr[userIndex].dose3_date));
      printf("\nThird Dose Date: %s", userProfilesptr[userIndex].dose3_date);
      memset(userProfilesptr[userIndex].dose3_type, 0, sizeof(userProfilesptr[userIndex].dose3_type));
      printf("\nThird Dose Type: %s", userProfilesptr[userIndex].dose3_type);
      memset(userProfilesptr[userIndex].dose3_loc, 0, sizeof(userProfilesptr[userIndex].dose3_loc));
      printf("\nThird Dose Location: %s", userProfilesptr[userIndex].dose3_loc);
    }
  }

  else
  {
    // set second dose to null
    memset(userProfilesptr[userIndex].dose2_date, 0, sizeof(userProfilesptr[userIndex].dose2_date));
    printf("\nSecond Dose Date: %s", userProfilesptr[userIndex].dose2_date);
    memset(userProfilesptr[userIndex].dose2_type, 0, sizeof(userProfilesptr[userIndex].dose2_type));
    printf("\nSecond Dose Type: %s", userProfilesptr[userIndex].dose2_type);
    memset(userProfilesptr[userIndex].dose2_loc, 0, sizeof(userProfilesptr[userIndex].dose2_loc));
    printf("\nSecond Dose Location: %s", userProfilesptr[userIndex].dose2_loc);
    memset(userProfilesptr[userIndex].dose3_date, 0, sizeof(userProfilesptr[userIndex].dose3_date));
    printf("\nThird Dose Date: %s", userProfilesptr[userIndex].dose3_date);
    memset(userProfilesptr[userIndex].dose3_type, 0, sizeof(userProfilesptr[userIndex].dose3_type));
    printf("\nThird Dose Type: %s", userProfilesptr[userIndex].dose3_type);
    memset(userProfilesptr[userIndex].dose3_loc, 0, sizeof(userProfilesptr[userIndex].dose3_loc));
    printf("\nThird Dose Location: %s", userProfilesptr[userIndex].dose3_loc);
  }
  userAmountptr++;
}

// User Data > [2] View all users
void mng_User_View(struct user *userProfilesptr, int *userAmountptr)
{
  int i;
  printf("User ID List\n\n");
  for (i = 0; i < *userAmountptr; i++)
  {
    printf("User ID: %d\n", userProfilesptr[i].userID);
    printf("User Name: %s\n", userProfilesptr[i].name);
    printf("User Password: %s\n", userProfilesptr[i].password);
    printf("User Contact: %s\n", userProfilesptr[i].contact);
    printf("User Address: %s\n", userProfilesptr[i].address);
    printf("User Sex: %s\n", userProfilesptr[i].sex);
    printf("First Dose Date: %s\n", userProfilesptr[i].dose1_date);
    printf("First Dose Type: %s\n", userProfilesptr[i].dose1_type);
    printf("First Dose Location: %s\n", userProfilesptr[i].dose1_loc);
    printf("Second Dose Date: %s\n", userProfilesptr[i].dose2_date);
    printf("Second Dose Type: %s\n", userProfilesptr[i].dose2_type);
    printf("Second Dose Location: %s\n", userProfilesptr[i].dose2_loc);
    printf("Third Dose Date: %s\n", userProfilesptr[i].dose3_date);
    printf("Third Dose Type: %s\n", userProfilesptr[i].dose3_type);
    printf("Third Dose Location: %s\n", userProfilesptr[i].dose3_loc);
  }
}

// User Data > [3] Edit user details
void mng_User_Edit(struct user *userProfilesptr, int *userAmountptr)
{
  int viewIDs, userID, userIndex;
  printf("User Data\n\n");
  printf("View all user IDs?");
  scanf("%d", &viewIDs);

  if (viewIDs == 1)
  {
    mng_userView(userProfilesptr, userAmountptr);
  }

  printf("Enter ID of user to edit: ");
  scanf("%d", &userID);
  userIndex = mng_userFind(userProfilesptr, userAmountptr, userID);

  printf("You are editing Profile %d with ID %d\n", userIndex, userID);
  printf("Choose ");
}

// User Data > [4] Delete user/s
// User data > [5] Return to Data Management
int mng_User_Delete(struct user *userProfilesptr, int *userAmountptr)
{
  int userID, userIndex = 0, choice, confirmchoice, i;
  struct user emptystruct = {0};

  printf("[1] Clear user data\n"
         "[2] Clear all user data\n"
         "[3] Exit\n\n");
  scanf("%d", &choice);

  if (choice == 1)
  {
    printf("Enter user ID to delete: ");
    scanf("%d", &userID);
    userIndex = mng_userFind(userProfilesptr, userAmountptr, userID);
    printf("Are you sure you want to delete user %d? (1 = yes, 2 = no)\n", userID);
    scanf("%d", &confirmchoice);

    if (confirmchoice == 1)
    {
      userProfilesptr[userIndex] = emptystruct;
    }
    else
    {
      printf("User delete aborted.");
      confirmchoice = 0;
    }
  }
  else if (choice == 2)
  {
    printf("Are you sure you want to delete all user data? (1 = yes, 2 = no)\n");
    scanf("%d", &confirmchoice);

    if (confirmchoice == 1)
    {
      for (i = 0; i < *userAmountptr; i++)
      {
        userProfilesptr[i] = emptystruct;
      }
    }
    else
    {
      printf("User database delete aborted.");
      confirmchoice = 0;
    }
  }
  else if (choice == 3)
  {
    printf("Bringing you back to the management data menu...");
    return 0;
  }
}






// 3.2 APPOINTMENT DATA MENU (in cdg.c)
//int mng_Appt(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr);

// Appt Data > [1] Add appointment
void mng_Appt_Add(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{
  int userIndex, tempID, tempAID, validAID;

  printf("Enter user ID to add appointment to: ");
  scanf("%d", &tempID);
  userIndex = mng_userFind(userProfilesptr, userAmountptr, tempID);

  printf("You are adding an appointment to Profile %d with ID %d\n", userIndex, tempID);

  // prompt for appointment ID
  do
  {
    printf("Enter your Appointment ID below:\n> ");
    scanf("%d", &tempAID);
    fflush(stdin);
    validAID = checkAID(userProfilesptr, userAmountptr, apptAmountptr, tempAID);

    if (validAID > 0)
    {
      printf(ANSI_RED "Error: Application ID already exists. Enter a valid appointment ID number.\n" ANSI_OFF);
    }
  } while (validAID > 0);

  printf(ANSI_GREEN "Success: Application ID available.\n" ANSI_OFF);
  userProfilesptr[userIndex].appdetails->appID = tempAID;

  printf("User Name: %s", userProfilesptr[userIndex].name);
  printf("Enter your Appointment Date: ");
  scanf("%s", userProfilesptr[userIndex].appdetails->date);
  printf("Enter your Appointment Time: ");
  scanf("%s", userProfilesptr[userIndex].appdetails->time);
  printf("Enter your Appointment Location: ");
  scanf("%s", userProfilesptr[userIndex].appdetails->location);
  printf("Enter your Appointment Vaccine Type: ");
  scanf("%s", userProfilesptr[userIndex].appdetails->vaccine);
  printf("Enter your Appointment Dose Number: ");
  scanf("%s", userProfilesptr[userIndex].appdetails->dose);

  apptAmountptr++;
}

// Appt Data > [2] View all appointments
void mng_Appt_View(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{
  int i, j;
  printf("Appointment ID List\n\n");
  for (i = 0; i < *userAmountptr; i++)
    for (j = 0; j < *apptAmountptr; j++)
    {
      printf("User ID: %d\n", userProfilesptr[i].userID);
      printf("User Appointment ID: %d\n", userProfilesptr[i].appdetails->appID);
      printf("User name: %s", userProfilesptr[i].name);
      printf("User Appointment Date: %s\n", userProfilesptr[i].appdetails->date);
      printf("User Appointment Time: %s\n", userProfilesptr[i].appdetails->time);
      printf("User Appointment Location: %s\n", userProfilesptr[i].appdetails->location);
      printf("User Appointment Vaccine Type: %s\n", userProfilesptr[i].appdetails->vaccine);
      printf("User Appointment Dose Number: %s\n", userProfilesptr[i].appdetails->dose);
    }
}

// Appt Data > [3] Edit appointment details
void mng_Appt_Edit(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{
  int userIndex, tempID, tempAID, validAID;
  int choice;

  printf("Enter user ID to add appointment to: ");
  scanf("%d", &tempID);
  userIndex = mng_userFind(userProfilesptr, userAmountptr, tempID);

  printf("You are editing an appointment to Profile %d with ID %d\n", userIndex, tempID);
  printf("Choose which to edit: \n");

  // print out all appt details
  printf("User Name: %s", userProfilesptr[userIndex].name);
  printf("[User ID: %d\n", userProfilesptr[userIndex].userID);
  printf("[1] User Appointment ID: %d\n", userProfilesptr[userIndex].appdetails->appID);
  printf("[2] User Appointment Date: %s\n", userProfilesptr[userIndex].appdetails->date);
  printf("[3] User Appointment Time: %s\n", userProfilesptr[userIndex].appdetails->time);
  printf("[4] User Appointment Location: %s\n", userProfilesptr[userIndex].appdetails->location);
  printf("[5] User Appointment Vaccine Type: %s\n", userProfilesptr[userIndex].appdetails->vaccine);
  printf("[6] User Appointment Dose Number: %s\n", userProfilesptr[userIndex].appdetails->dose);
  scanf("choice: %d", &choice);

  switch (choice)
  {
  case 1:
  {
    printf("Enter new appointment ID:");
    scanf("%d", &tempAID);
    validAID = checkAID(userProfilesptr, userAmountptr, apptAmountptr, tempAID);

    if (validAID > 0)
    {
      printf(ANSI_RED "Error: Application ID already exists. Enter a valid appointment ID number.\n" ANSI_OFF);
    }
    else
    {
      printf(ANSI_GREEN "Success: Application ID available.\n" ANSI_OFF);
      userProfilesptr[userIndex].appdetails->appID = 0;
      userProfilesptr[userIndex].appdetails->appID = tempAID;
    }
  }
  case 2:
  {
    memset(userProfilesptr[userIndex].appdetails->date, 0, sizeof(userProfilesptr[userIndex].appdetails->date));
    printf("Enter new appointment date:");
    scanf("%s", userProfilesptr[userIndex].appdetails->date);
  }
  case 3:
  {
    memset(userProfilesptr[userIndex].appdetails->time, 0, sizeof(userProfilesptr[userIndex].appdetails->time));
    printf("Enter new appointment time:");
    scanf("%s", userProfilesptr[userIndex].appdetails->time);
  }
  case 4:
  {
    memset(userProfilesptr[userIndex].appdetails->location, 0, sizeof(userProfilesptr[userIndex].appdetails->location));
    printf("Enter new appointment location:");
    scanf("%s", userProfilesptr[userIndex].appdetails->location);
  }
  case 5:
  {
    memset(userProfilesptr[userIndex].appdetails->vaccine, 0, sizeof(userProfilesptr[userIndex].appdetails->vaccine));
    printf("Enter new appointment vaccine type:");
    scanf("%s", userProfilesptr[userIndex].appdetails->vaccine);
  }
  case 6:
  {
    memset(userProfilesptr[userIndex].appdetails->dose, 0, sizeof(userProfilesptr[userIndex].appdetails->dose));
    printf("Enter new appointment dose (first/second/third):");
    scanf("%s", userProfilesptr[userIndex].appdetails->dose);
  }
  }

  printf("Appointment edited successfully.\n");
  printf("new appointment details for Profile %d with ID %d\n", userIndex, tempID);
  printf("User Name: %s", userProfilesptr[userIndex].name);
  printf("[User ID: %d\n", userProfilesptr[userIndex].userID);
  printf("[1] User Appointment ID: %d\n", userProfilesptr[userIndex].appdetails->appID);
  printf("[2] User Appointment Date: %s\n", userProfilesptr[userIndex].appdetails->date);
  printf("[3] User Appointment Time: %s\n", userProfilesptr[userIndex].appdetails->time);
  printf("[4] User Appointment Location: %s\n", userProfilesptr[userIndex].appdetails->location);
  printf("[5] User Appointment Vaccine Type: %s\n", userProfilesptr[userIndex].appdetails->vaccine);
  printf("[6] User Appointment Dose Number: %d\n", userProfilesptr[userIndex].appdetails->dose);
}

// Appt Data > [4] Delete appointment/s
void mng_Appt_Delete(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr)
{
  int apptID, apptIndex = 0, choice, confirmchoice;
  //struct appointment emptystruct = {0};
  printf("Enter appointment ID to delete: ");
  scanf("%d", &apptID);
  apptIndex = mng_userFind(userProfilesptr, userAmountptr, apptID);

  printf("You are deleting appointment ID %d\n", apptID);
  printf("Confirm deletion? [1] Yes [2] No\n");
  scanf("%d", &confirmchoice);

  if (confirmchoice == 1)
  {
    userProfilesptr[apptIndex].appdetails;
    printf("Appointment deleted successfully.\n");
  }
  else
  {
    printf("Appointment deletion cancelled.\n");
  }
}

// Appt Data > [5] Return to Data Management
int mng_Appt_Exit();





// 3.3 CHATBOT DATA MENU (in cdg.c)
//int mng_Chat(struct user *userProfilesptr, int *userAmountptr);

// Chatbot Data > [1] Add chatbot data
int mng_Chat_Add();
// Chatbot Data > [2] View all chatbot data
int mng_Chat_View();
// Chatbot Data > [3] Edit chatbot data
int mng_Chat_Edit();
// Chatbot Data > [4] Delete chatbot data
int mng_Chat_Delete();






// 3.4 DATA FILES MENU (in cdg.c)
//int mng_ChoosePort(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr);

// Import/Export Data > [1] Import data
void mng_Import(struct user *userProfilesptr, int *userAmountptr)
{
  FILE *fp;
  char filename[100];
  int i;
  printf("Enter filename: ");
  scanf("%s", filename);
  fp = fopen(filename, "r");

  if (fp == NULL)
  {
    printf("Error: File not found.\n");
  }

  // Read user profiles from file
  while (fscanf(fp, "%d %s %s %s %s %s %s %s %s %s %s %s %s", 
            &userProfilesptr[i].userID,
            userProfilesptr[i].password,
            userProfilesptr[i].name,
            userProfilesptr[i].contact,
            userProfilesptr[i].address,
            userProfilesptr[i].sex, 
            userProfilesptr[i].dose1_date, userProfilesptr[i].dose1_type, userProfilesptr[i].dose1_loc,
            userProfilesptr[i].dose2_date, userProfilesptr[i].dose2_type, userProfilesptr[i].dose2_loc,
            userProfilesptr[i].dose3_date, userProfilesptr[i].dose3_type, userProfilesptr[i].dose3_loc) == 15)
  {
    i++;
  }

  // Update user amount
  *userAmountptr = i;

  // Close the file
  fclose(fp);
}

// Import/Export Data > [2] Export data
void mng_Export(struct user *userProfilesptr, int *userAmountptr)
{
  FILE *fp;
  char filename[100];
  int i;

  printf("Enter filename: ");
  scanf("%s", filename);
  fp = fopen(filename, "w");

  if (fp == NULL)
  {
    printf("Error: Unable to create file.\n");
    return;
  }

  // Write user profiles to file
  for (i = 0; i < *userAmountptr; i++)
  {
    fprintf(fp, "%d %s\n%s\n%s\n%s\n%s\n%s %s %s\n%s %s %s\n%s %s %s\n\n",
            userProfilesptr[i].userID,
            userProfilesptr[i].password,
            userProfilesptr[i].name,
            userProfilesptr[i].address,
            userProfilesptr[i].contact,
            userProfilesptr[i].sex,
            userProfilesptr[i].dose1_loc, userProfilesptr[i].dose1_date, userProfilesptr[i].dose1_type,
            userProfilesptr[i].dose2_loc, userProfilesptr[i].dose2_date, userProfilesptr[i].dose2_type,
            userProfilesptr[i].dose3_loc, userProfilesptr[i].dose3_date, userProfilesptr[i].dose3_type);
  }

  // Close the file
  fclose(fp);
}


// 3.5 SAVE AND EXIT
int mng_SaveExit(struct user *userProfilesptr, int *userAmountptr, int *apptAmountptr);