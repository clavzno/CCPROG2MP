/* LIBRARIES, DEFINE DIRECTIVES */

#include <stdio.h>
#include <stdlib.h> //for system("cls")
#include <string.h>
#include <unistd.h> //Required for the sleep() function, alternate is <windows.h>
#define MAX_USERS 100
#define MAX_QUESTIONS 10
#define MAX_ANSWERS 10
#define MAX_APPOINTMENTS 10
#define MAX_USERLINES 8 * MAX_USERS
#define MAX_APPTLINES 8 * MAX_APPOINTMENTS

/* Added after submission */
#include <ctype.h>

/* TYPEDEFs */

typedef char Str6[7];   // 6 characters + null terminator
typedef char Str10[11]; // 10 characters + null terminator
typedef char Str20[21]; // 20 characters + null terminator
typedef char Str30[31]; // 30 characters + null terminator
typedef char QnA[81];   // 80 characters + null terminator

/* UI COLORS */

// \e == (Esc)ape code, [ for ANSI code, m for end of ANSI code

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
  Str10 appID;
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
  Str10 userID;
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
      j = a;
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
      j = a;
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

// Checks for an empty profile in the memory
int checkEmptyIndex(struct user *userProfilesptr)
{
  int i;
  for (i = 0; i < MAX_USERS; i++)
  {
    if (strlen(userProfilesptr[i].userID) == 0) // if userID is empty
    {
      return i; // return index of non-empty profile
    }
  }
}

// Checks if the ID is already taken
int checkID(struct user *userProfilesptr, char userID[11])
{
  int i;
  for (i = 0; i < MAX_USERS; i++)
  {
    if (strcmp(userProfilesptr[i].userID, userID) == 0)
    {
      return 1; // found a matching id (therefore unavailable)
    }
  }
  return 0; // no matching id found (available)
}

// looks for the index based on ID
int checkIDIndex(struct user *userProfilesptr, char userID[11])
{
  int i;
  for (i = 0; i < MAX_USERS; i++)
  {
    if (strcmp(userProfilesptr[i].userID, userID) == 0)
    {
      return i; // found a matching id
    }
  }
  return 0; // no matching id found
}

// checks if id exists in all appointments
int checkAID(struct user *userProfilesptr, char tempid[11])
{
  int i, j;
  for (i = 0; i < MAX_USERS; i++)          // check every user
    for (j = 0; j < MAX_APPOINTMENTS; j++) // check every appt per user
    {
      if (strcmp(userProfilesptr[i].appdetails[j].appID, tempid) == 0)
      {
        return 1; // matching id found
      }
    }
  return 0; // no matching id found
}

// checks for an empty appointment slot per user
int checkAIDIndex(struct user *userProfilesptr, int userIndex)
{
  int j;
  for (j = 0; j < MAX_APPOINTMENTS; j++) // check every appt per user
  {
    if (strcmp(userProfilesptr[userIndex].appdetails[j].appID, "\0") == 0)
    {
      return j; // empty found
    }
  }
  return 0; // no matching id found
}

// looks for the profile index based on app ID
int checkAIDUserIndex(struct user *userProfilesptr, char tempid[11])
{
  int i, j;
  for (i = 0; i < MAX_USERS; i++)          // check every user
    for (j = 0; j < MAX_APPOINTMENTS; j++) // check every appt per user
    {
      if (strcmp(userProfilesptr[i].appdetails[j].appID, tempid) == 0)
      {
        return i; // matching id found
      }
    }
  return 0; // no matching id found
}

/* File Functions */
int file_countLines(FILE *file)
{
  int count = 0;
  if (file == NULL)
  {
    printf("Error opening file!");
    return -1;
  }

  int c;
  while ((c = fgetc(file)) != EOF)
  {
    if (c == '\n')
    {
      count++;
    }
  }
  return count + 1; //+1 because we want to include the first line
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
// int mainmenu(struct user *userProfilesptr);
// int submainmenu(struct user *userProfilesptr)
int mainmenu(struct user *userProfilesptr);
int submainmenu(struct user *userProfilesptr);

/************************************************************/
// [1] VACCINATION REGISTRATION

// subfunction to save user data to file
void file_reg_User(struct user *userProfilesptr, int userIndex, FILE *userfile)
{
  // write to file
  // lines per user: 8 + 1 (blank line)
  fprintf(userfile, "%s %s\n", userProfilesptr[userIndex].userID, userProfilesptr[userIndex].password);
  fprintf(userfile, "%s\n", userProfilesptr[userIndex].name);
  fprintf(userfile, "%s\n", userProfilesptr[userIndex].address);
  fprintf(userfile, "%s\n", userProfilesptr[userIndex].contact);
  fprintf(userfile, "%s\n", userProfilesptr[userIndex].sex);
  fprintf(userfile, "%s %s %s\n", userProfilesptr[userIndex].dose1_loc, userProfilesptr[userIndex].dose1_date, userProfilesptr[userIndex].dose1_type);
  fprintf(userfile, "%s %s %s\n", userProfilesptr[userIndex].dose2_loc, userProfilesptr[userIndex].dose2_date, userProfilesptr[userIndex].dose2_type);
  fprintf(userfile, "%s %s %s\n\n", userProfilesptr[userIndex].dose3_loc, userProfilesptr[userIndex].dose3_date, userProfilesptr[userIndex].dose3_type);
}

// 1.1 User Registration
void reg_User(struct user *userProfilesptr)
{
  FILE *userfile = fopen("Users.txt", "a");
  FILE *idlist = fopen("IDlist.txt", "a+");

  if (userfile == NULL)
  {
    printf("Error: Unable to open file.\n");
    return;
  }

  if (idlist == NULL)
  {
    printf("Error: Unable to open file.\n");
    return;
  }

  // variable declarations
  int idcheck = 0, userIndex;
  char firstname[11], lastname[11], tempid[11];
  int secondDose, thirdDose;

  userIndex = checkEmptyIndex(userProfilesptr);
  printf("Empty profile found at index %d\n", userIndex);

  printf("User Registration\n" ANSI_BLUE "Please input the requested data.\n\n" ANSI_OFF);

  // char userID
  do
  {
    fflush(stdin);
    printf("Enter User ID: ");
    fgets(tempid, sizeof(tempid), stdin);
    tempid[strcspn(tempid, "\n")] = '\0';
    idcheck = checkID(userProfilesptr, tempid);

    if (idcheck > 0)
    {
      printf(ANSI_RED "Error: ID already taken.\n" ANSI_OFF);
    }

  } while (idcheck > 0);

  printf(ANSI_GREEN "Success: ID available\n" ANSI_OFF);
  strcpy(userProfilesptr[userIndex].userID, tempid);
  printf("User ID: %s\n", userProfilesptr[userIndex].userID);

  // save id to id list file
  fprintf(idlist, "%s\n", userProfilesptr[userIndex].userID);

  // char password[11]
  char tempPass[11];
  char confirmPass[11];
  char hiddenPass[11];
  do
  {
    fflush(stdin);
    printf("Enter your password: ");
    fgets(tempPass, sizeof(tempPass), stdin);
    tempPass[strcspn(tempPass, "\n")] = '\0'; // remove newline character
    fflush(stdin);
    printf("Please confirm your password: ");
    fgets(confirmPass, sizeof(confirmPass), stdin);
    confirmPass[strcspn(confirmPass, "\n")] = '\0'; // remove newline character
    if (strcmp(tempPass, confirmPass) != 0)
    {
      printf(ANSI_RED "Error: Passwords do not match.\n" ANSI_OFF);
    }
    else
    {
      strcpy(userProfilesptr[userIndex].password, tempPass);
      printf(ANSI_GREEN "Success: Passwords match.\n" ANSI_OFF);
    }
  } while (strcmp(tempPass, confirmPass) != 0);

  displayPassword_ast(tempPass);
  strcpy(hiddenPass, tempPass);
  printf("Confirmed Password: %s\n", hiddenPass);

  // str20 name
  fflush(stdin);
  printf("Enter your first name: ");
  fgets(firstname, 11, stdin);
  firstname[strlen(firstname) - 1] = '\0'; // remove newline character
  fflush(stdin);
  printf("\r\r");
  printf("Enter your last name: ");
  fgets(lastname, 11, stdin);
  lastname[strlen(lastname) - 1] = '\0'; // remove newline character
  fflush(stdin);
  strcat(userProfilesptr[userIndex].name, firstname); // add first name
  strcat(userProfilesptr[userIndex].name, " ");       // add space
  strcat(userProfilesptr[userIndex].name, lastname);  // add last name
  printf("Name: %s\n", userProfilesptr[userIndex].name);
  fflush(stdin); // clears the buffer because of the newline character

  // int contact
  fflush(stdin);
  printf("Enter your contact number: ");
  fgets(userProfilesptr[userIndex].contact, 12, stdin);
  userProfilesptr[userIndex].contact[strcspn(userProfilesptr[userIndex].contact, "\n")] = '\0'; // remove newline character
  fflush(stdin);
  printf("Number: %s\n", userProfilesptr[userIndex].contact);

  // str30 address
  fflush(stdin);
  printf("Enter your address: ");
  fgets(userProfilesptr[userIndex].address, 31, stdin);
  fflush(stdin);
  printf("Address: %s\n", userProfilesptr[userIndex].address);

  // str10 sex [Male/Female]
  printf("Enter your sex " ANSI_BLUE "[Male/Female]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].sex, 11, stdin);
  userProfilesptr[userIndex].sex[strcspn(userProfilesptr[userIndex].sex, "\n")] = '\0'; // remove newline character
  fflush(stdin);
  printf("Sex: %s\n", userProfilesptr[userIndex].sex);

  // str10 dose date
  fflush(stdin);
  printf("Enter date of first dose" ANSI_BLUE " [YYYY-MM-DD]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].dose1_date, 11, stdin);
  userProfilesptr[userIndex].dose1_date[strcspn(userProfilesptr[userIndex].dose1_date, "\n")] = '\0'; // remove newline character
  fflush(stdin);
  printf("First Dose Date: %s\n", userProfilesptr[userIndex].dose1_date);

  // str10 dose type
  fflush(stdin);
  printf("Enter First Dose Vaccine brand " ANSI_BLUE "[Sinovac/Moderna/Pfizer/etc]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].dose1_type, 11, stdin);
  userProfilesptr[userIndex].dose1_type[strcspn(userProfilesptr[userIndex].dose1_type, "\n")] = '\0'; // remove newline character
  fflush(stdin);
  printf("First Dose Brand: %s\n", userProfilesptr[userIndex].dose1_type);

  // str01 dose location
  fflush(stdin);
  printf("Enter location of first dose: ");
  fgets(userProfilesptr[userIndex].dose1_loc, 11, stdin);
  userProfilesptr[userIndex].dose1_loc[strcspn(userProfilesptr[userIndex].dose1_loc, "\n")] = '\0'; // remove newline character
  fflush(stdin);
  printf("First Dose Location: %s\n", userProfilesptr[userIndex].dose1_loc);

  // prompt for second and third dose
  printf("Do you have a second dose? " ANSI_BLUE "[1/0]: " ANSI_OFF);
  scanf("%d", &secondDose);
  fflush(stdin);
  printf("\nSecond Dose Choice: %d\n", secondDose);

  if (secondDose == 1)
  {
    // str10 dose date
    fflush(stdin);
    printf("Enter date of second dose" ANSI_BLUE " [YYYY-MM-DD]: " ANSI_OFF);
    fgets(userProfilesptr[userIndex].dose2_date, 11, stdin);
    userProfilesptr[userIndex].dose2_date[strcspn(userProfilesptr[userIndex].dose2_date, "\n")] = '\0'; // remove newline character
    fflush(stdin);
    printf("Second Dose Date: %s\n", userProfilesptr[userIndex].dose2_date);
    // str10 dose type
    fflush(stdin);
    printf("Enter Second Dose Vaccine brand " ANSI_BLUE "[Sinovac/Moderna/Pfizer/etc]: " ANSI_OFF);
    fgets(userProfilesptr[userIndex].dose2_type, 11, stdin);
    userProfilesptr[userIndex].dose2_type[strcspn(userProfilesptr[userIndex].dose2_type, "\n")] = '\0'; // remove newline character
    fflush(stdin);
    printf("Second Dose Brand: %s\n", userProfilesptr[userIndex].dose2_type);
    // str10 dose location
    fflush(stdin);
    printf("Enter location of Second dose: ");
    fgets(userProfilesptr[userIndex].dose2_loc, 11, stdin);
    userProfilesptr[userIndex].dose2_loc[strcspn(userProfilesptr[userIndex].dose2_loc, "\n")] = '\0'; // remove newline character
    fflush(stdin);
    printf("Second Dose Location: %s\n", userProfilesptr[userIndex].dose2_loc);

    // prompt for third dose
    printf("Do you have a third dose? " ANSI_BLUE "[1/0]: " ANSI_OFF);
    scanf("%d", &thirdDose);
    fflush(stdin);
    printf("\nThird Dose Choice: %d", thirdDose);

    if (thirdDose == 1)
    {
      // str10 dose date
      fflush(stdin);
      printf("Enter date of third dose" ANSI_BLUE " [YYYY-MM-DD]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose3_date, 11, stdin);
      userProfilesptr[userIndex].dose3_date[strcspn(userProfilesptr[userIndex].dose3_date, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Third Dose Date: %s\n", userProfilesptr[userIndex].dose3_date);
      // str10 dose type
      fflush(stdin);
      printf("Enter Third Dose Vaccine brand " ANSI_BLUE "[Sinovac/Moderna/Pfizer/etc]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose3_type, 11, stdin);
      userProfilesptr[userIndex].dose3_type[strcspn(userProfilesptr[userIndex].dose3_type, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Third Dose Brand: %s\n", userProfilesptr[userIndex].dose3_type);
      // str10 dose location
      fflush(stdin);
      printf("Enter location of Third dose: ");
      fgets(userProfilesptr[userIndex].dose3_loc, 11, stdin);
      userProfilesptr[userIndex].dose3_loc[strcspn(userProfilesptr[userIndex].dose3_loc, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Third Dose Location: %s\n", userProfilesptr[userIndex].dose3_loc);
    }
    else
    {
      // set third dose to null
      memset(userProfilesptr[userIndex].dose3_date, 0, sizeof(userProfilesptr[userIndex].dose3_date));
      printf("Third Dose Date: %s\n", userProfilesptr[userIndex].dose3_date);
      memset(userProfilesptr[userIndex].dose3_type, 0, sizeof(userProfilesptr[userIndex].dose3_type));
      printf("Third Dose Type: %s\n", userProfilesptr[userIndex].dose3_type);
      memset(userProfilesptr[userIndex].dose3_loc, 0, sizeof(userProfilesptr[userIndex].dose3_loc));
      printf("Third Dose Location: %s\n", userProfilesptr[userIndex].dose3_loc);
    }
  }

  else
  {
    // set second dose and third dose to null
    memset(userProfilesptr[userIndex].dose2_date, 0, sizeof(userProfilesptr[userIndex].dose2_date));
    printf("Second Dose Date: %s\n", userProfilesptr[userIndex].dose2_date);
    memset(userProfilesptr[userIndex].dose2_type, 0, sizeof(userProfilesptr[userIndex].dose2_type));
    printf("Second Dose Type: %s\n", userProfilesptr[userIndex].dose2_type);
    memset(userProfilesptr[userIndex].dose2_loc, 0, sizeof(userProfilesptr[userIndex].dose2_loc));
    printf("Second Dose Location: %s\n", userProfilesptr[userIndex].dose2_loc);
    memset(userProfilesptr[userIndex].dose3_date, 0, sizeof(userProfilesptr[userIndex].dose3_date));
    printf("Third Dose Date: %s\n", userProfilesptr[userIndex].dose3_date);
    memset(userProfilesptr[userIndex].dose3_type, 0, sizeof(userProfilesptr[userIndex].dose3_type));
    printf("Third Dose Type: %s\n", userProfilesptr[userIndex].dose3_type);
    memset(userProfilesptr[userIndex].dose3_loc, 0, sizeof(userProfilesptr[userIndex].dose3_loc));
    printf("Third Dose Location: %s\n", userProfilesptr[userIndex].dose3_loc);
  }

  // write data to file
  file_reg_User(userProfilesptr, userIndex, userfile);
  // close file and end registration
  system("cls");
  printf("User Registration Complete!\n");
  fclose(userfile);
  fclose(idlist);
}

// 1.2 Vaccination Appointment Registration (Appt Req)
void file_reg_Appt(struct user *userProfilesptr, int userIndex, FILE *apptfile, int apptIndex)
{
  // write to file
  // lines per user: 7 + 1 (blank line)
  fprintf(apptfile, "%s %s\n", userProfilesptr[userIndex].appdetails[apptIndex].appID, userProfilesptr[userIndex].userID);
  fprintf(apptfile, "%s\n", userProfilesptr[userIndex].name);
  fprintf(apptfile, "%s\n", userProfilesptr[userIndex].appdetails[apptIndex].location);
  fprintf(apptfile, "%s\n", userProfilesptr[userIndex].appdetails[apptIndex].vaccine);
  fprintf(apptfile, "%s \n", userProfilesptr[userIndex].appdetails[apptIndex].date);
  fprintf(apptfile, "%s\n", userProfilesptr[userIndex].appdetails[apptIndex].time);
  fprintf(apptfile, "%s\n\n", userProfilesptr[userIndex].appdetails[apptIndex].dose);
}

void reg_Appt(struct user *userProfilesptr)
{
  FILE *apptfile = fopen("Appointment.txt", "a");

  if (apptfile == NULL)
  {
    printf("Error: Unable to open file.\n");
    return;
  }

  // variable declarations
  int userExists = 0;
  int userIndex;
  char tempid[11];

  printf("Appointment Registration\n" ANSI_BLUE "Please input the requested data.\n\n" ANSI_OFF);

  // login: find existing user
  do
  {
    fflush(stdin);
    printf(ANSI_BLUE "You have to log in first.\n" ANSI_OFF);
    printf("Enter User ID: ");
    fgets(tempid, sizeof(tempid), stdin);
    tempid[strcspn(tempid, "\n")] = '\0';

    // check if user exists
    userExists = checkID(userProfilesptr, tempid);
    if (userExists == 0)
    {
      printf(ANSI_RED "Error: User does not exist. Enter a valid user ID number.\n" ANSI_OFF);
    }
  } while (userExists == 0);

  printf(ANSI_GREEN "Success: User exists.\n" ANSI_OFF);
  userIndex = checkIDIndex(userProfilesptr, tempid);
  printf("User ID: %s in index %d\n", userProfilesptr[userIndex].userID, userIndex);

  // login: prompt for correct password
  char tempPass[11];
  do
  {
    printf("Enter Password: ");
    scanf("%s", tempPass);
    tempPass[strcspn(tempPass, "\n")] = '\0';
    if (strcmp(tempPass, userProfilesptr[userIndex].password) != 0)
    {
      printf(ANSI_RED "Error: Incorrect password.\n" ANSI_OFF);
      memset(tempPass, 0, sizeof(tempPass));
    }
  } while (strcmp(tempPass, userProfilesptr[userIndex].password) != 0);

  printf(ANSI_GREEN "Login Successful!\n" ANSI_OFF);

  // find empty appointment slot based on userindex
  int apptIndex;

  apptIndex = checkAIDIndex(userProfilesptr, userIndex);
  printf("Empty appointment slot found at index %d\n", apptIndex);

  // int appID
  char tempAID[11];
  do
  {
    fflush(stdin);
    printf("Enter Appointment ID: ");
    fgets(tempAID, sizeof(tempAID), stdin);
    tempAID[strcspn(tempAID, "\n")] = '\0';
    if (checkAID(userProfilesptr, tempAID) == 1)
    {
      printf(ANSI_RED "Error: Appointment ID already exists. Enter a valid appointment ID number.\n" ANSI_OFF);
    }
  } while (checkAID(userProfilesptr, tempAID) == 1);
  fflush(stdin);

  printf(ANSI_GREEN "Success: Appointment ID available.\n" ANSI_OFF);
  strcpy(userProfilesptr[userIndex].appdetails[apptIndex].appID, tempAID);

  // str20 location
  fflush(stdin);
  printf("Enter Location: ");
  fgets(userProfilesptr[userIndex].appdetails[apptIndex].location, 21, stdin);
  userProfilesptr[userIndex].appdetails[apptIndex].location[strlen(userProfilesptr[userIndex].appdetails[apptIndex].location) - 1] = '\0';
  fflush(stdin);

  // str10 vaccine
  fflush(stdin);
  printf("Enter Vaccine brand " ANSI_BLUE "[Sinovac/Moderna/Pfizer/etc]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].appdetails[apptIndex].vaccine, 11, stdin);
  userProfilesptr[userIndex].appdetails[apptIndex].vaccine[strlen(userProfilesptr[userIndex].appdetails[apptIndex].vaccine) - 1] = '\0';
  fflush(stdin);

  // str10 date
  printf("Enter Date of Appointment " ANSI_BLUE "[YYYY-MM-DD]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].appdetails[apptIndex].date, 11, stdin);
  userProfilesptr[userIndex].appdetails[apptIndex].date[strlen(userProfilesptr[userIndex].appdetails[apptIndex].date) - 1] = '\0';
  fflush(stdin);

  // str10 dose
  fflush(stdin);
  printf("Enter Dose " ANSI_BLUE "[Second/Third]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].appdetails[apptIndex].dose, 11, stdin);
  userProfilesptr[userIndex].appdetails[apptIndex].dose[strlen(userProfilesptr[userIndex].appdetails[apptIndex].dose) - 1] = '\0';
  fflush(stdin);

  // str6 time
  fflush(stdin);
  printf("Enter Time of Appointment " ANSI_BLUE "[24HR Format]: " ANSI_OFF);
  fgets(userProfilesptr[userIndex].appdetails[apptIndex].time, 7, stdin);
  userProfilesptr[userIndex].appdetails[apptIndex].time[strlen(userProfilesptr[userIndex].appdetails[apptIndex].time) - 1] = '\0';
  fflush(stdin);

  // CHECKING / PRINT EVERYTHING
  printf("\nEVERYTHING\n");
  printf("Appointment ID: %s\n", userProfilesptr[userIndex].appdetails[apptIndex].appID);
  printf("User ID: %s\n", userProfilesptr[userIndex].userID);
  printf("Location: %s\n", userProfilesptr[userIndex].appdetails[apptIndex].location);
  printf("Vaccine: %s\n", userProfilesptr[userIndex].appdetails[apptIndex].vaccine);
  printf("Date: %s\n", userProfilesptr[userIndex].appdetails[apptIndex].date);
  printf("Time: %s\n", userProfilesptr[userIndex].appdetails[apptIndex].time);
  printf("Dose: %s\n", userProfilesptr[userIndex].appdetails[apptIndex].dose);

  // write to file
  file_reg_Appt(userProfilesptr, userIndex, apptfile, apptIndex);
  printf(ANSI_GREEN "Success: Appointment registered.\n" ANSI_OFF);
  // close file
  fclose(apptfile);
}

/************************************************************/
// [2] CHATBOT/FAQS

// 2.1 Chatbot function
/* int reg_Chat(struct user *userProfilesptr, int )
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
} */

/************************************************************/
// [3] ADMIN/DATA MANAGEMENT

// MAIN MENU FOR ADMIN
// to grant access to the module, the user must log in using the userID and password (hidden)
// user is granted 3 attempts to log in, otherwise terminate program
int management(struct user *userProfilesptr);

// 3.1 USER DATA MENU (in cdg.c)
int mng_User(struct user *userProfilesptr);

// User Data > [1] Add new user
void mng_User_Add(struct user *userProfilesptr)
{
  int choice;
  do
  {
    reg_User(userProfilesptr);
    printf("Add another user? [1/0]: ");
    scanf("%d", &choice);
  } while (choice != 0);
}

// User Data > [3] Edit user details
int mng_User_Edit(struct user *userProfilesptr)
{
  int choice, userIndex, detail, userExists;
  char tempid[11];
  FILE *userfile = fopen("Users.txt", "r+");

  // check if file exists
  if (userfile == NULL)
  {
    printf("Error! Users.txt File not found.\n");
    exit(1);
  }

  // begin edit
  do
  {

    do // userid
    {
      // enter an id
      fflush(stdin);
      printf("Enter user ID to edit: ");
      fgets(tempid, sizeof(tempid), stdin);
      tempid[strcspn(tempid, "\n")] = '\0';

      // check if id exists
      userExists = checkID(userProfilesptr, tempid);
      if (userExists == 0)
      {
        printf("Error: User ID not found.\n");
        memset(tempid, 0, sizeof(tempid));
      }
    } while (userExists == 0);

    // find user index
    userIndex = checkIDIndex(userProfilesptr, tempid);
    printf(ANSI_GREEN "User ID found at index %d.\n\n" ANSI_OFF, userIndex);

    // display all details
    printf("User Details:\n"
           "[1] UserID: %s\n"
           "[2] Password: %s\n"
           "[3] Name: %s\n"
           "[4] Contact: %s\n"
           "[5] Address: %s\n"
           "[6] Sex: %s\n"
           "[7] First Dose Date: %s\n"
           "[8] First Dose Vaccine: %s\n"
           "[9] First Dose Location: %s\n"
           "[10] Second Dose Date: %s\n"
           "[11] Second Dose Vaccine: %s\n"
           "[12] Second Dose Location: %s\n"
           "[13] Third Dose Date: %s\n"
           "[14] Third Dose Vaccine: %s\n"
           "[15] Third Dose Location: %s\n"
           "[16] Exit\n",
           userProfilesptr[userIndex].userID,
           userProfilesptr[userIndex].password,
           userProfilesptr[userIndex].name,
           userProfilesptr[userIndex].contact,
           userProfilesptr[userIndex].address,
           userProfilesptr[userIndex].sex,
           userProfilesptr[userIndex].dose1_date,
           userProfilesptr[userIndex].dose1_type,
           userProfilesptr[userIndex].dose1_loc,
           userProfilesptr[userIndex].dose2_date,
           userProfilesptr[userIndex].dose2_type,
           userProfilesptr[userIndex].dose2_loc,
           userProfilesptr[userIndex].dose3_date,
           userProfilesptr[userIndex].dose3_type,
           userProfilesptr[userIndex].dose3_loc);

    // choose which one to edit
    printf("Enter the number of the detail you want to edit: ");
    scanf("%d", &detail);

    // edit
    switch (detail)
    {
    case 1: // edit user ID
    {
      char tempid[11];
      char oldID[11];
      // keep old id for file
      strcpy(oldID, userProfilesptr[userIndex].userID);
      do
      {
        printf("OLD ID: %s\n", oldID);
        // overwrite new id
        fflush(stdin);
        printf("Enter new user ID: ");
        fgets(tempid, sizeof(tempid), stdin);
        tempid[strcspn(tempid, "\n")] = '\0'; // remove newline character

        // check if id exists
        if (checkID(userProfilesptr, tempid) != 0)
        {
          printf(ANSI_RED "Error: User ID already exists.\n" ANSI_OFF);
          memset(tempid, 0, sizeof(tempid));
        }

      } while (checkID(userProfilesptr, tempid) != 0);

      // assign new id
      strcpy(userProfilesptr[userIndex].userID, tempid);
      break;
    }
    case 2: // edit password
    {
      memset(userProfilesptr[userIndex].password, 0, sizeof(userProfilesptr[userIndex].password));
      char tempPass[11];
      char confirmPass[11];
      do
      {
        fflush(stdin);
        printf("Enter new password: ");
        fgets(tempPass, sizeof(tempPass), stdin);
        tempPass[strcspn(tempPass, "\n")] = '\0'; // remove newline character
        fflush(stdin);
        printf("Please confirm new password: ");
        fgets(confirmPass, sizeof(confirmPass), stdin);
        confirmPass[strcspn(confirmPass, "\n")] = '\0'; // remove newline character
        if (strcmp(tempPass, confirmPass) != 0)
        {
          printf(ANSI_RED "Error: Passwords do not match.\n" ANSI_OFF);
        }
        else
        {
          strcpy(userProfilesptr[userIndex].password, tempPass);
          printf(ANSI_GREEN "Success: Passwords match.\n" ANSI_OFF);
        }
      } while (strcmp(tempPass, confirmPass) != 0);
      break;
    }
    case 3: // edit name
    {
      memset(userProfilesptr[userIndex].name, 0, sizeof(userProfilesptr[userIndex].name));
      // str20 name
      char firstname[11], lastname[11];
      fflush(stdin);
      printf("Enter first name: ");
      fgets(firstname, 11, stdin);
      firstname[strlen(firstname) - 1] = '\0'; // remove newline character
      fflush(stdin);
      printf("\r\r");
      printf("Enter last name: ");
      fgets(lastname, 11, stdin);
      lastname[strlen(lastname) - 1] = '\0'; // remove newline character
      fflush(stdin);
      strcat(userProfilesptr[userIndex].name, firstname); // add first name
      strcat(userProfilesptr[userIndex].name, " ");       // add space
      strcat(userProfilesptr[userIndex].name, lastname);  // add last name
      printf("Name: %s\n", userProfilesptr[userIndex].name);
      fflush(stdin); // clears the buffer because of the newline character
      break;
    }
    case 4: // edit contact
    {
      memset(userProfilesptr[userIndex].contact, 0, sizeof(userProfilesptr[userIndex].contact));
      // int contact
      fflush(stdin);
      printf("Enter new contact number: ");
      fgets(userProfilesptr[userIndex].contact, 12, stdin);
      userProfilesptr[userIndex].contact[strcspn(userProfilesptr[userIndex].contact, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Number: %s\n", userProfilesptr[userIndex].contact);
      break;
    }
    case 5: // edit address
    {
      memset(userProfilesptr[userIndex].address, 0, sizeof(userProfilesptr[userIndex].address));
      // str30 address
      fflush(stdin);
      printf("Enter new address: ");
      fgets(userProfilesptr[userIndex].address, 31, stdin);
      fflush(stdin);
      printf("Address: %s\n", userProfilesptr[userIndex].address);
      break;
    }
    case 6: // edit sex
    {
      memset(userProfilesptr[userIndex].sex, 0, sizeof(userProfilesptr[userIndex].sex));
      // str10 sex [Male/Female]
      fflush(stdin);
      printf("Enter your sex " ANSI_BLUE "[Male/Female]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].sex, 11, stdin);
      userProfilesptr[userIndex].sex[strcspn(userProfilesptr[userIndex].sex, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Sex: %s\n", userProfilesptr[userIndex].sex);
      break;
    }
    case 7: // edit dose1 date
    {
      memset(userProfilesptr[userIndex].dose1_date, 0, sizeof(userProfilesptr[userIndex].dose1_date));
      // str10 dose date
      fflush(stdin);
      printf("Enter date of first dose" ANSI_BLUE " [YYYY-MM-DD]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose1_date, 11, stdin);
      userProfilesptr[userIndex].dose1_date[strcspn(userProfilesptr[userIndex].dose1_date, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("First Dose Date: %s\n", userProfilesptr[userIndex].dose1_date);
      break;
    }
    case 8: // edit dose1 type
    {
      memset(userProfilesptr[userIndex].dose1_type, 0, sizeof(userProfilesptr[userIndex].dose1_type));
      // str10 dose type
      fflush(stdin);
      printf("Enter type of first dose brand: " ANSI_BLUE "[Sinovac/Moderna]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose1_type, 11, stdin);
      userProfilesptr[userIndex].dose1_type[strcspn(userProfilesptr[userIndex].dose1_type, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("First Dose Type: %s\n", userProfilesptr[userIndex].dose1_type);
      break;
    }
    case 9: // edit dose1 location
    {
      memset(userProfilesptr[userIndex].dose1_loc, 0, sizeof(userProfilesptr[userIndex].dose1_loc));
      // str01 dose location
      fflush(stdin);
      printf("Enter location of first dose: ");
      fgets(userProfilesptr[userIndex].dose1_loc, 11, stdin);
      userProfilesptr[userIndex].dose1_loc[strcspn(userProfilesptr[userIndex].dose1_loc, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("First Dose Location: %s\n", userProfilesptr[userIndex].dose1_loc);
      break;
    }
    case 10: // edit dose2 date
    {
      memset(userProfilesptr[userIndex].dose2_date, 0, sizeof(userProfilesptr[userIndex].dose2_date));
      // str10 dose date
      fflush(stdin);
      printf("Enter date of second dose" ANSI_BLUE " [YYYY-MM-DD]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose2_date, 11, stdin);
      userProfilesptr[userIndex].dose2_date[strcspn(userProfilesptr[userIndex].dose2_date, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Second Dose Date: %s\n", userProfilesptr[userIndex].dose2_date);
      break;
    }
    case 11: // edit dose2 type
    {
      memset(userProfilesptr[userIndex].dose2_type, 0, sizeof(userProfilesptr[userIndex].dose2_type));
      // str10 dose type
      fflush(stdin);
      printf("Enter type of Second dose brand: " ANSI_BLUE "[Sinovac/Moderna]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose2_type, 11, stdin);
      userProfilesptr[userIndex].dose2_type[strcspn(userProfilesptr[userIndex].dose2_type, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Second Dose Type: %s\n", userProfilesptr[userIndex].dose2_type);
      break;
    }
    case 12: // edit dose2 location
    {
      memset(userProfilesptr[userIndex].dose2_loc, 0, sizeof(userProfilesptr[userIndex].dose2_loc));
      fflush(stdin);
      printf("Enter location of Second dose: ");
      fgets(userProfilesptr[userIndex].dose2_loc, 11, stdin);
      userProfilesptr[userIndex].dose2_loc[strcspn(userProfilesptr[userIndex].dose2_loc, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Second Dose Location: %s\n", userProfilesptr[userIndex].dose2_loc);
      break;
    }
    case 13: // edit dose3 date
    {
      memset(userProfilesptr[userIndex].dose3_date, 0, sizeof(userProfilesptr[userIndex].dose3_date));
      // str10 dose date
      fflush(stdin);
      printf("Enter date of third dose" ANSI_BLUE " [YYYY-MM-DD]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose3_date, 11, stdin);
      userProfilesptr[userIndex].dose3_date[strcspn(userProfilesptr[userIndex].dose3_date, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Third Dose Date: %s\n", userProfilesptr[userIndex].dose3_date);
      break;
    }
    case 14: // edit dose3 type
    {
      memset(userProfilesptr[userIndex].dose3_type, 0, sizeof(userProfilesptr[userIndex].dose3_type));
      // str10 dose type
      fflush(stdin);
      printf("Enter type of Third dose brand: " ANSI_BLUE "[Sinovac/Moderna]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].dose3_type, 11, stdin);
      userProfilesptr[userIndex].dose3_type[strcspn(userProfilesptr[userIndex].dose3_type, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Third Dose Type: %s\n", userProfilesptr[userIndex].dose3_type);
      break;
    }
    case 15: // edit dose3 location
    {
      memset(userProfilesptr[userIndex].dose3_loc, 0, sizeof(userProfilesptr[userIndex].dose3_loc));
      // str10 dose location
      fflush(stdin);
      printf("Enter location of Third dose: ");
      fgets(userProfilesptr[userIndex].dose3_loc, 11, stdin);
      userProfilesptr[userIndex].dose3_loc[strcspn(userProfilesptr[userIndex].dose3_loc, "\n")] = '\0'; // remove newline character
      fflush(stdin);
      printf("Third Dose Location: %s\n", userProfilesptr[userIndex].dose3_loc);
      break;
    }
    case 16: // exit
    {
      break;
    }
    } // end switch
    // display all details
    printf("Updated User Details:\n"
           "[1] UserID: %d\n"
           "[2] Password: %s\n"
           "[3] Name: %s\n"
           "[4] Contact: %s\n"
           "[5] Address: %s\n"
           "[6] Sex: %s\n"
           "[7] First Dose Date: %s\n"
           "[8] First Dose Vaccine: %s\n"
           "[9] First Dose Location: %s\n"
           "[10] Second Dose Date: %s\n"
           "[11] Second Dose Vaccine: %s\n"
           "[12] Second Dose Location: %s\n"
           "[13] Third Dose Date: %s\n"
           "[14] Third Dose Vaccine: %s\n"
           "[15] Third Dose Location: %s\n"
           "[16] Exit\n",
           userProfilesptr[userIndex].userID,
           userProfilesptr[userIndex].password,
           userProfilesptr[userIndex].name,
           userProfilesptr[userIndex].contact,
           userProfilesptr[userIndex].address,
           userProfilesptr[userIndex].sex,
           userProfilesptr[userIndex].dose1_date,
           userProfilesptr[userIndex].dose1_type,
           userProfilesptr[userIndex].dose1_loc,
           userProfilesptr[userIndex].dose2_date,
           userProfilesptr[userIndex].dose2_type,
           userProfilesptr[userIndex].dose2_loc,
           userProfilesptr[userIndex].dose3_date,
           userProfilesptr[userIndex].dose3_type,
           userProfilesptr[userIndex].dose3_loc);
    // update Users.txt with new details of specific user
    char target[11];
    strcpy(target, userProfilesptr[userIndex].userID);
    char maxline[31];
    while (fgets(maxline, sizeof(maxline), userfile))
    {
      if (strstr(maxline, target))
      {
        fseek(userfile, -strlen(maxline), SEEK_CUR);
        file_reg_User(userProfilesptr, userIndex, userfile);
      }
    }
    //  prompt for next change
    printf("Edit details of another user? [1/0]: ");
    scanf("%d", &choice);
    fflush(stdin);
  } while (choice != 0);
  fclose(userfile);
}

// User Data > [2] View All User Details (calls mng_userEdit)
int mng_UserView(struct user *userProfilesptr)
{
  int i, editchoice;
  printf("Printing User Details...\n");
  for (i = 0; i < MAX_USERS; i++)
  {
    if (strcmp(userProfilesptr[i].userID, "") == 0)
    {
      printf(ANSI_BLUE "Index: %d is empty\n" ANSI_OFF, i);
    }
    else
    {
      printf(ANSI_BLUE "Index: %d\n" ANSI_OFF, i);
      printf("User Details:\n"
             "[1] UserID: %s\n"
             "[2] Password: %s\n"
             "[3] Name: %s\n"
             "[4] Contact: %s\n"
             "[5] Address: %s\n"
             "[6] Sex: %s\n"
             "[7] First Dose Date: %s\n"
             "[8] First Dose Vaccine: %s\n"
             "[9] First Dose Location: %s\n"
             "[10] Second Dose Date: %s\n"
             "[11] Second Dose Vaccine: %s\n"
             "[12] Second Dose Location: %s\n"
             "[13] Third Dose Date: %s\n"
             "[14] Third Dose Vaccine: %s\n"
             "[15] Third Dose Location: %s\n",
             userProfilesptr[i].userID,
             userProfilesptr[i].password,
             userProfilesptr[i].name,
             userProfilesptr[i].contact,
             userProfilesptr[i].address,
             userProfilesptr[i].sex,
             userProfilesptr[i].dose1_date,
             userProfilesptr[i].dose1_type,
             userProfilesptr[i].dose1_loc,
             userProfilesptr[i].dose2_date,
             userProfilesptr[i].dose2_type,
             userProfilesptr[i].dose2_loc,
             userProfilesptr[i].dose3_date,
             userProfilesptr[i].dose3_type,
             userProfilesptr[i].dose3_loc);
    }
  }
  printf(ANSI_RED "End of User Database\n" ANSI_OFF);
  printf("Edit user details? [1/0]: ");
  scanf("%d", &editchoice);
  if (editchoice == 1)
  {
    mng_User_Edit(userProfilesptr);
  }
  else if (editchoice == 0)
  {
    return 0;
  }
}

// User Data > [4] Delete user/s
int mng_User_Delete(struct user *userProfilesptr)
{
  return 0;
}
// User data > [5] Return to Data Management
// Recursive function back to management instead

// 3.2 APPOINTMENT DATA MENU (in cdg.c)
int mng_Appt(struct user *userProfilesptr);

// Appt Data > [1] Add appointment
void mng_Appt_Add(struct user *userProfilesptr)
{
  int choice;
  do
  {
    reg_Appt(userProfilesptr);
    printf("Add another appointment? [1/0]: ");
    scanf("%d", &choice);
  } while (choice != 0);
}

// Appt Data > [3] Edit appointment details
int mng_Appt_Edit(struct user *userProfilesptr)
{
  int choice, apptExists, apptIndex, detail, userIndex;
  char tempid[11];
  FILE *apptfile = fopen("Appointment.txt", "r+");

  // check if file exists
  if (apptfile == NULL)
  {
    printf("Error! File not found\n");
    exit(1);
  }

  // begin edit
  do // choice
  {
    do // apptExists
    {
      fflush(stdin);
      printf("Enter appointment ID to edit: ");
      fgets(tempid, sizeof(tempid), stdin);
      tempid[strcspn(tempid, "\n")] = '\0';

      // check if appointment exists
      apptExists = checkAID(userProfilesptr, tempid);
      if (apptExists == 0)
      {
        printf("Appointment does not exist!\n");
        return 0;
      }
    } while (apptExists == 0);

    // get appointment index
    userIndex = checkAIDUserIndex(userProfilesptr, tempid);
    apptIndex = checkAIDIndex(userProfilesptr, userIndex);
    printf(ANSI_GREEN "Appointment ID found at profile index %d index %d.\n\n" ANSI_OFF, userIndex, apptIndex);

    // display all details of appointment
    printf("Appointment Details:\n"
           "[1] Appointment ID: %s\n"
           "User ID: %s\n"
           "[2] Date: %s\n"
           "[3] Time: %s\n"
           "[4] Vaccine Type: %s\n"
           "[5] Location: %s\n"
           "[6] Exit\n",
           userProfilesptr[userIndex].appdetails[apptIndex].appID,
           userProfilesptr[userIndex].appdetails[apptIndex].date,
           userProfilesptr[userIndex].appdetails[apptIndex].time,
           userProfilesptr[userIndex].appdetails[apptIndex].vaccine,
           userProfilesptr[userIndex].appdetails[apptIndex].location);

    // choose which one to edit
    printf("Which detail would you like to edit?: ");
    scanf("%d", &detail);

    // edit
    switch (detail)
    {
    case 1:
    {
      char tempappID[11];
      char oldappID[11];
      // keep old id for file
      strcpy(oldappID, userProfilesptr[userIndex].appdetails[apptIndex].appID);
      do
      {
        printf("OLD ID: %s", oldappID);
        fflush(stdin);
        printf("Enter new appointment ID: ");
        fgets(tempappID, sizeof(tempappID), stdin);
        tempappID[strcspn(tempappID, "\n")] = '\0';

        // check if appointment id exists
        if (checkAID(userProfilesptr, tempappID) == 1)
        {
          printf(ANSI_RED "Error: Appointment ID already exists!\n" ANSI_OFF);
        }

      } while (checkAID(userProfilesptr, tempappID) == 1);

      // assign new id
      strcpy(userProfilesptr[userIndex].appdetails[apptIndex].appID, tempappID);
      printf("New Appointment ID: %s", userProfilesptr[userIndex].appdetails[apptIndex].appID);
      break;
    }
    case 2: // edit date
    {
      memset(userProfilesptr[userIndex].appdetails[apptIndex].date, 0, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].date));
      fflush(stdin);
      printf("Enter date of appointment" ANSI_BLUE " [YYYY-MM-DD]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].appdetails[apptIndex].date, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].date), stdin);
      userProfilesptr[userIndex].appdetails[apptIndex].date[strcspn(userProfilesptr[userIndex].appdetails[apptIndex].date, "\n")] = '\0';
      printf("New date: %s", userProfilesptr[userIndex].appdetails[apptIndex].date);
      break;
    }
    case 3: // edit time
    {
      memset(userProfilesptr[userIndex].appdetails[apptIndex].time, 0, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].time));
      fflush(stdin);
      printf("Enter time of appointment" ANSI_BLUE " [HH:MM]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].appdetails[apptIndex].time, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].time), stdin);
      userProfilesptr[userIndex].appdetails[apptIndex].time[strcspn(userProfilesptr[userIndex].appdetails[apptIndex].time, "\n")] = '\0';
      printf("New time: %s", userProfilesptr[userIndex].appdetails[apptIndex].time);
      break;
    }
    case 4: // edit vaccine
    {
      memset(userProfilesptr[userIndex].appdetails[apptIndex].vaccine, 0, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].vaccine));
      fflush(stdin);
      printf("Enter type of vaccine brand: " ANSI_BLUE "[Sinovac/Moderna]: " ANSI_OFF);
      fgets(userProfilesptr[userIndex].appdetails[apptIndex].vaccine, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].vaccine), stdin);
      userProfilesptr[userIndex].appdetails[apptIndex].vaccine[strcspn(userProfilesptr[userIndex].appdetails[apptIndex].vaccine, "\n")] = '\0';
      printf("New vaccine: %s", userProfilesptr[userIndex].appdetails[apptIndex].vaccine);
      break;
    }
    case 5: // edit location
    {
      memset(userProfilesptr[userIndex].appdetails[apptIndex].location, 0, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].location));
      fflush(stdin);
      printf("Enter location of appointment:" ANSI_OFF);
      fgets(userProfilesptr[userIndex].appdetails[apptIndex].location, sizeof(userProfilesptr[userIndex].appdetails[apptIndex].location), stdin);
      userProfilesptr[userIndex].appdetails[apptIndex].location[strcspn(userProfilesptr[userIndex].appdetails[apptIndex].location, "\n")] = '\0';
      printf("New location: %s", userProfilesptr[userIndex].appdetails[apptIndex].location);
      break;
    }
    case 6:
    {
      break;
    }
    } // end switch
    // display all details
    printf("Updated User Details:\n"
           "[1] Appointment ID: %s\n"
           "User ID: %s\n"
           "[2] Date: %s\n"
           "[3] Time: %s\n"
           "[4] Vaccine: %s\n"
           "[5] Location: %s\n",
           userProfilesptr[userIndex].appdetails[apptIndex].appID,
           userProfilesptr[userIndex].userID,
           userProfilesptr[userIndex].appdetails[apptIndex].date,
           userProfilesptr[userIndex].appdetails[apptIndex].time,
           userProfilesptr[userIndex].appdetails[apptIndex].vaccine,
           userProfilesptr[userIndex].appdetails[apptIndex].location);

    // update Appointment.txt with new details
    char target[11];
    strcpy(target, userProfilesptr[userIndex].appdetails[apptIndex].appID);
    char maxline[21];
    while (fgets(maxline, sizeof(maxline), apptfile))
    {
      if (strstr(maxline, target))
      {
        fseek(apptfile, -strlen(maxline), SEEK_CUR);
        file_reg_Appt(userProfilesptr, userIndex, apptfile, apptIndex);
      }
      // prompt for next change
      printf("Edit another appointment? [1/0]: ");
      scanf("%d", &choice);
      fflush(stdin);
    }

  } while (choice != 0);

  // update Appointment.txt with new details

  fclose(apptfile);
}

// Appt Data > [2] View all appointments (calls mng_Appt_Edit)
int mng_Appt_View(struct user *userProfilesptr)
{
  int i, j, editchoice;
  printf("Printing Appointment Details...\n");

  for (i = 0; i < MAX_APPOINTMENTS; i++)
    for (j = 0; j < MAX_APPOINTMENTS; j++)
    {
      if (strcmp(userProfilesptr[i].appdetails[j].appID, "") == 0)
      {
        printf(ANSI_BLUE "Index: %d Appointment %d is empty\n" ANSI_OFF, i, j);
      }
      else
      {
        printf(ANSI_BLUE " Profile %d Appointment Index: %d\n" ANSI_OFF, i, j);
        printf("[1] User ID: %s\n", userProfilesptr[i].userID);
        printf("User Appointment ID: %s\n", userProfilesptr[i].appdetails[j].appID);
        printf("User name: %s", userProfilesptr[i].name);
        printf("User Appointment Date: %s\n", userProfilesptr[i].appdetails[j].date);
        printf("User Appointment Time: %s\n", userProfilesptr[i].appdetails[j].time);
        printf("User Appointment Location: %s\n", userProfilesptr[i].appdetails[j].location);
        printf("User Appointment Vaccine Type: %s\n", userProfilesptr[i].appdetails[j].vaccine);
        printf("User Appointment Dose Number: %s\n", userProfilesptr[i].appdetails[j].dose);
      }
    }

  printf(ANSI_RED "End of Appointment Database\n" ANSI_OFF);
  printf("Edit Appointment details? [1/0]: ");
  scanf("%d", &editchoice);
  if (editchoice == 1)
  {
    mng_Appt_Edit(userProfilesptr);
  }
  else if (editchoice == 0)
  {
    return 0;
  }
}

// Appt Data > [4] Delete appointment
int mng_Appt_Delete(struct user *userProfilesptr)
{
  return 0;
}

// Appt Data > [5] Return to Data Management

// 3.3 CHATBOT DATA MENU (in cdg.c)
// Data Management Menu [Admin]
int mng_Chat(struct user *userProfilesptr);

// Chatbot Data > [1] Add chatbot data
int mng_Chat_Add()
{
  FILE *fp = fopen("chatbot.txt", "a");
  char question[81], answer[81];

  fflush(stdin);
  printf("Enter question: ");
  fgets(question, 81, stdin);
  question[strcspn(question, "\n")] = '\0';
  fprintf(fp, "\n%s\n", question);

  printf("Enter answer: ");
  fflush(stdin);
  fgets(answer, 81, stdin);
  answer[strcspn(answer, "\n")] = '\0';
  fprintf(fp, "%s", answer);

  fclose(fp);
}

// Chatbot Data > [3] Edit chatbot data
// Chatbot Data > [3] Edit chatbot data
int mng_Chat_Edit()
{
  printf("This function still has bugs. Please use the text editor to edit the chatbot.txt file.\n");
  int choice;
  FILE *fp = fopen("chatbot.txt", "r+");
  char question[81], answer[81];
  int line_number = 0; // Keep track of the current line number

  while (fgets(question, 80, fp) != NULL)
  {
    // If the current line is a question (odd numbered line), store it in the question variable
    if (line_number % 2 == 0)
    {
      printf("[%d] Question: %s", line_number, question);
    }
    // If the current line is an answer (even numbered line), store it in the answer variable and print it
    else
    {
      printf("[%d] Answer: %s", line_number, question);
    }

    line_number++; // Increment the line number counter
  }

  printf("\nEnter the line number of the answer you want to edit: ");
  scanf("%d", &choice);

  // Move the file pointer to the chosen line number
  fseek(fp, (choice * 2 - 2) * 81, SEEK_SET);

  // Get the current question and answer
  fgets(question, 81, fp);
  fgets(answer, 81, fp);

  // Print the current question and answer
  printf("Current question: %s\n", question);
  printf("Current answer: %s\n", answer);

  // Edit the question and answer
  fflush(stdin);
  printf("Enter new question: ");
  fgets(question, 81, stdin);
  question[strcspn(question, "\n")] = '\0';

  fflush(stdin);
  printf("Enter new answer: ");
  fgets(answer, 81, stdin);
  answer[strcspn(answer, "\n")] = '\0';

  // Move the file pointer back to the chosen line number and overwrite the old data with the new data
  fseek(fp, (choice * 2 - 2) * 81, SEEK_CUR);
  fprintf(fp, "%s\n%s\n", question, answer);

  fclose(fp);
}

// Chatbot Data > [2] View all chatbot data (calls mng_Chat_Edit)
int mng_Chat_View()
{
  int choice;
  FILE *fp = fopen("chatbot.txt", "r");
  char question[81], answer[81];
  int line_number = 0; // Keep track of the current line number

  while (fgets(question, 80, fp) != NULL)
  {
    // If the current line is a question (odd numbered line), store it in the question variable
    if (line_number % 2 == 0)
    {
      printf("Question: %s", question);
    }
    // If the current line is an answer (even numbered line), store it in the answer variable and print it
    else
    {
      printf("Answer: %s", question);
    }

    line_number++; // Increment the line number counter
  }

  fclose(fp);

  printf("\nEdit chatbot data? [1/0]:");
  scanf("%d", &choice);
  fflush(stdin);
  if (choice == 1)
  {
    mng_Chat_Edit();
  }
  else if (choice == 0)
  {
    return 0;
  }
}

// Chatbot Data > [4] Delete chatbot data
int mng_Chat_Delete()
{
  FILE *fp = fopen("chatbot.txt", "r");
  FILE *temp = fopen("temp.txt", "w");
  char question[81], answer[81];
  int line_amount = 0, line_number = 0, delete_line = 0; // Keep track of the current line number and the one to be deleted

  while (fgets(question, 80, fp) != NULL)
  {
    // If the current line is a question (odd numbered line), store it in the question variable
    if (line_number % 2 == 0)
    {
      printf("[%d] Question: %s", line_number, question);
    }
    // If the current line is an answer (even numbered line), store it in the answer variable and print it
    else
    {
      printf("[%d] Answer: %s", line_number, question);
    }

    line_number++; // Increment the line number counter
  }

  printf("\nHow many line numbers would you want to delete? ");
  scanf("%d", line_amount);

  for (int i = 0; i < line_amount; i++)
  {
    printf("Enter the line number (question - even, answer - odd) you want to delete: ");
    scanf("%d", &delete_line);

    while (fgets(question, 80, fp) != NULL)
    {
      if (line_number == delete_line * 2 - 2)
      {
        // Skip the question that needs to be deleted
        fgets(answer, 80, fp); // Read and discard the corresponding answer line
      }
      else if (line_number == delete_line * 2 - 1)
      {
        // Skip the answer that needs to be deleted
        fgets(question, 80, fp); // Read and discard the corresponding question line
      }
      else
      {
        // Write the remaining lines to the temporary file
        fputs(question, temp);
        fputs(answer, temp);
      }
    }

    line_number++; // Increment the line number counter
  }

  fclose(fp);
  fclose(temp);

  // Replace the original file with the temporary file
  remove("chatbot.txt");
  rename("temp.txt", "chatbot.txt");
}

// 3.4 DATA FILES MENU (in cdg.c)
int mng_ChoosePort(struct user *userProfilesptr);

// Import/Export Data > [1] Import data
void mng_Import(struct user *userProfilesptr)
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
  while (fscanf(fp, "%s %s\n%s\n%s\n%s\n%s\n%s %s %s\n%s %s %s\n %s %s %s\n",
                userProfilesptr[i].userID,
                userProfilesptr[i].password,
                userProfilesptr[i].name,
                userProfilesptr[i].address,
                userProfilesptr[i].contact,
                userProfilesptr[i].sex,
                userProfilesptr[i].dose1_loc, userProfilesptr[i].dose1_date, userProfilesptr[i].dose1_type,
                userProfilesptr[i].dose2_loc, userProfilesptr[i].dose2_date, userProfilesptr[i].dose2_type,
                userProfilesptr[i].dose3_loc, userProfilesptr[i].dose3_date, userProfilesptr[i].dose3_type) == 15)
  {
    i++;
  }

  // Close the file
  fclose(fp);
}

// Import/Export Data > [2] Export data
void mng_Export(struct user *userProfilesptr)
{
  FILE *fp;
  char filename[30];
  int i;

  printf("Enter filename: ");
  scanf("%s", filename);

  while (strlen(filename) > 30)
  {
    printf("Filename is too long, shorten it to less than 30: ");
    scanf("%s", filename);
  }

  fp = fopen(filename, "w");

  if (fp == NULL)
  {
    printf("Error: Unable to create file.\n");
    return;
  }

  // Write user profiles to file
  for (i = 0; i < MAX_USERS; i++)
  {
    fprintf(fp, "%s %s\n%s\n%s\n%s\n%s\n%s %s %s\n%s %s %s\n %s %s %s\n",
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
// int mng_SaveExit(struct user *userProfilesptr);