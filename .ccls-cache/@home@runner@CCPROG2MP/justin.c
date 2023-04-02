/***************************************************************************

CCPROG2 Machine Project - Vaccination Registration Application with Chatbot

Description: // WIP //

Programmed by: Justin Patrick M. De Grano - S18B
Last modified: 3-22-2022
Version: V0.2C

***************************************************************************/

// library and other variable declarations

#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef char stg6[7];
typedef char stg10[11];
typedef char stg20[21];
typedef char stg30[31];

/* These are display functions which serve more as a display guide
   & decoration part for the program to the end-user. */

void displayLine() { printf("\n------------------------------------------\n"); }

// Printed introductory menu

void displayIntro() {

  displayLine();

  printf("\nVaxDB Introduction\n");

  displayLine();

  printf("\nOh why, hello there! Welcome to the VaxDB Program!\n");

  printf("\nThis program is designed for your best convenience in\n");
  printf("your vaccine facilitation in registration, scheduling,\n");
  printf("inquiries and all sorts of data management.\n");

  printf(
      "\nWith no further delay, you may now proceed forward in the program.\n");

  displayLine();
}

// Printed display menu (before option A and B)

void displayMenu() {

  displayLine();

  printf("\nVaxDB Primary Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) Vaccine Registration\n");
  printf("(B) Data/Settings Management\n");
  printf("(X) Exit the Program\n");

  displayLine();
}

// Printed display menu (option A - vaxreg)

void displayMenu_A() {

  displayLine();

  printf("\nVaxDB Vaccine Registration Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) User Registration\n");
  printf("(B) Vaccine Appointment\n");
  printf("(C) Chat with AssistiVax (FAQs)\n");
  printf("(X) Go Back to the Primary Menu\n");

  displayLine();
}

// Printed display menu (option B - datamanag)

void displayMenu_B() {

  displayLine();

  printf("\nVaxDB Data Management Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) User Management\n");
  printf("(B) Appointment Management\n");
  printf("(C) AssistiVax Management\n");
  printf("(D) Export Data\n");
  printf("(E) Import Data\n");
  printf("(X) Exit the Program\n");

  displayLine();
}

/* These are the structures to be used for the program. */

struct userStats {
  int userID, contactNum;
  stg10 password;

  stg20 userNameF, userNameL;
  stg30 address;
  stg10 sex;

  stg10 dose1, dose1Vaxx, dose1Loc;

  stg10 dose2, dose2Vaxx, dose2Loc;

  stg10 dose3, dose3Vaxx, dose3Loc;
};

struct vappStats {
  int appID;
  stg20 name;
  stg10 location, vaxx, date, dose;
  stg6 time;
};
// struct chatStats {}

/* These are the functions to be made for the menu options,
   arranged from top-to-bottom - the same way it was ordered
   on function displayMenu. */

/* If the user selects vaccine registration, they would be forwarded
   to choose choices in between.

   user registration (User) - heads the user straight
   their data to be registered

   vaccine appointment (Vapp) - heads the user straight to
   input their schedule for vaccinations

   chat with assistivax (Chat) - heads the user straight to
   frequently asked questions

   back to menu - heads the user straight to the main menu */

void menuReg_User(struct userStats *uProfPT, struct vappStats *vProfPT,
                  int userAmount, int vappAmount) {

  int tempRegDecs =
      0; // variable for determining whether the user wants to register or not
  int tempRegAmount =
      0; // variable for how many users is to be registered in the prompt
  int tempDoseMult =
      0; // variable for whether or not the user did multiple vaxx doses
  int tempUID = userAmount; // refers to the new registered user to be made

  displayLine();

  printf("\nVaxDB User Registration\n");

  displayLine();

  printf("\nWould You Like to Register User(s) (0 for No, 1 for Yes)?\n");
  scanf("%d", &tempRegDecs);

  if (tempRegDecs == 1) {

    printf("\nIf So, How Many?\n");
    scanf("%d", &tempRegAmount);

    for (int i = 0; i < tempRegAmount; i++)

    {

      displayLine();

      printf("\nPlease Input your User Data for ID#%d\n", tempUID);

      displayLine();

      printf("\nEnter UserID: ");
      scanf("%d", &uProfPT[tempUID].userID);
      printf("\nEnter Contact Number: ");
      scanf("%d", &uProfPT[tempUID].contactNum);
      printf("\nEnter Password: ");
      scanf("%d", &uProfPT[tempUID].password);

      displayLine();

      printf("\nEnter First Name: ");
      scanf("%s", &uProfPT[tempUID].userNameF);
      printf("\nEnter Last Name): ");
      scanf("%s", &uProfPT[tempUID].userNameL);
      printf("\nEnter Address: ");
      scanf(" %s", &uProfPT[tempUID].address);
      printf("\nEnter Sex: ");
      scanf("%s", &uProfPT[tempUID].sex);

      displayLine();

      printf("\nEnter Date of First Vaccination: ");
      scanf("%s", &uProfPT[tempUID].dose1);
      printf("\nEnter Brand of First Vaccine: ");
      scanf("%s", &uProfPT[tempUID].dose1Vaxx);
      printf("\nEnter Location of First Vaccination: ");
      scanf("%s", &uProfPT[tempUID].dose1Loc);

      displayLine();

      printf("\nAnswer Simply with '1' (None), '2' (Two Doses), '3' (Three "
             "Doses)\n");
      printf("\nEnter Amount of Booster Doses: ");
      scanf("%d", &tempDoseMult);

      do {
        switch (tempDoseMult) {
        case 1:
          strcpy(uProfPT[tempUID].dose2, "N/A");
          strcpy(uProfPT[tempUID].dose2Vaxx, "N/A");
          strcpy(uProfPT[tempUID].dose2Loc, "N/A");
          strcpy(uProfPT[tempUID].dose3, "N/A");
          strcpy(uProfPT[tempUID].dose3Vaxx, "N/A");
          strcpy(uProfPT[tempUID].dose3Loc, "N/A");
          break;
        case 2:
          printf("\nEnter Date of Second Vaccination: ");
          scanf("%s", &uProfPT[tempUID].dose2);
          printf("\nEnter Brand of Second Vaccine: ");
          scanf("%s", &uProfPT[tempUID].dose2Vaxx);
          printf("\nEnter Location of Third Vaccination: ");
          scanf("%s", &uProfPT[tempUID].dose2Loc);
          strcpy(uProfPT[tempUID].dose3, "N/A");
          strcpy(uProfPT[tempUID].dose3Vaxx, "N/A");
          strcpy(uProfPT[tempUID].dose3Loc, "N/A");
          break;
        case 3:
          printf("\nEnter Date of Second Vaccination: ");
          scanf("%s", &uProfPT[tempUID].dose2);
          printf("\nEnter Brand of Second Vaccine: ");
          scanf("%s", &uProfPT[tempUID].dose2Vaxx);
          printf("\nEnter Location of Second Vaccination: ");
          scanf("%s", &uProfPT[tempUID].dose2Loc);
          printf("\nEnter Date of Third Vaccination: ");
          scanf("%s", &uProfPT[tempUID].dose3);
          printf("\nEnter Brand of Third Vaccine: ");
          scanf("%s", &uProfPT[tempUID].dose3Vaxx);
          printf("\nEnter Location of Third Vaccination: ");
          scanf("%s", &uProfPT[tempUID].dose3Loc);
          break;
        default:
          printf("\nInvalid Input, Please Read the Instructions Carefully.\n");
        }
      } while (tempDoseMult != 1 && tempDoseMult != 2 && tempDoseMult != 3);

      tempUID++;
    }

    userAmount = tempUID; // amount of users registered will be assigned as the
                          // amount of users assigned.
    menuReg(uProfPT, vProfPT, userAmount,
            vappAmount); // brings back the user to vaxx reg menu.

  } else {
    printf("\nInput is Either Invalid or 0. Bringing You Back to the Vaxx "
           "Registration Menu.\n");
    menuReg(uProfPT, vProfPT, userAmount,
            vappAmount); // brings back the user to vaxx reg menu.
  }
}

void menuReg_Vapp(struct userStats *uProfPT, struct vappStats *vProfPT,
                  int userAmount, int vappAmount) {

  int tempRegDecs =
      0; // variable for determining whether the user wants to register or not
  int tempRegAmount =
      0; // variable for how many users is to be registered in the prompt
  int tempDoseMult =
      0; // variable for whether or not the user did multiple vaxx doses
  int tempUID = vappAmount; // refers to the new registered user to be made

  displayLine();

  printf("\nVaxDB Vaccine Appointment\n");

  displayLine();

  printf("\nWould You Like to Register Vaccine Appointment(s) (0 for No, 1 for "
         "Yes)?\n");
  scanf("%d", &tempRegDecs);

  struct vappStats {
    int appID;
    stg20 name;
    stg10 date, location, vaxx, dose;
    stg6 time;
  };

  if (tempRegDecs == 1) {

    printf("\nIf So, How Many?\n");
    scanf("%d", &tempRegAmount);

    for (int i = 0; i < tempRegAmount; i++)

    {

      displayLine();

      printf("\nPlease Input your User Data for ID#%d\n", tempUID);

      displayLine();

      printf("\nEnter Appointment ID: ");
      scanf("%d", &vProfPT[tempUID].appID);

      displayLine();

      printf("\nEnter Name: ");
      scanf("%s", &vProfPT[tempUID].name);

      printf("\nEnter Location: ");
      scanf("%s", &vProfPT[tempUID].location);

      printf("\nEnter Vaccine: ");
      scanf("%s", &vProfPT[tempUID].vaxx);

      printf("\nEnter Date (YYYY-MM-DD): ");
      scanf("%s", &vProfPT[tempUID].date);

      printf("\nEnter Time (24HR Format): ");
      scanf("%s", &vProfPT[tempUID].time);

      printf("\nEnter Dose (1st/2nd/3rd): ");
      scanf("%s", &vProfPT[tempUID].dose);

      tempUID++;
    }

    vappAmount = tempUID; // amount of users registered will be assigned as the
                          // amount of users assigned.
    menuReg(uProfPT, vProfPT, userAmount,
            vappAmount); // brings back the user to vaxx reg menu.

  } else {
    printf("\nInput is Either Invalid or 0. Bringing You Back to the Vaxx "
           "Registration Menu.\n");
    menuReg(uProfPT, vProfPT, userAmount,
            vappAmount); // brings back the user to vaxx reg menu.
  }
}

void menuReg_Chat() {}

void menuReg_Exit() {}

void menuReg(struct userStats *uProfPT, struct vappStats *vProfPT,
             int userAmount, int vappAmount) {

  displayMenu_A();

  char cOpt;

  printf("\nEnter Choice: ");
  scanf(" %c", &cOpt);

  switch (cOpt) {
  case 'A':
  case 'a':
    menuReg_User(uProfPT, vProfPT, userAmount, vappAmount);
    break;
  case 'B':
  case 'b':
    menuReg_Vapp(uProfPT, vProfPT, userAmount, vappAmount);
    break;
  case 'C':
  case 'c':
    menuReg_Chat();
    break;
  case 'X':
  case 'x':
    menuReg_Exit();
    break;
  default:
    printf("\nInvalid input, please only use what's indicated.\n");
  }
}

/* file generation - here are the functions necessary for the
   saving and preservation of data that would be activated once
   the user has finished inputting their specified registered data,
   that can be accessed/managed later in the program */

void genUser() {}

void genVapp() {}

void genChat() {}

/* On the other hand, if the user decides to choose the latter choice of
   manage data & settings, they can choose to access & manage either
   their data (both their registration, vax appointment & chat logs)
   as necessary. It also includes an export & import data function as well.*/

void menuMng_User(struct userStats *uProfPT, struct vappStats *vProfPT,
                  int userAmount, int vappAmount) {

  int userIDComp;
  struct userStats empty_struct = {0};

  displayLine();

  printf("\nVaxDB User Data Management Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) Edit User Details\n");
  printf("(B) Delete User Record\n");
  printf("(C) Display User Entries\n");
  printf("(X) Go Back to the Primary Menu\n");

  displayLine();

  char cOpt;

  printf("\nEnter Choice: ");
  scanf(" %c", &cOpt);

  switch (cOpt) {
  case 'A':
  case 'a':
    printf("\nWhich User ID Would You Like to Modify: ");
    scanf("%d", &userIDComp);
    break;
  case 'B':
  case 'b':
    printf("\nWhich User Record ID Would You Like to Delete: ");
    scanf("%d", &userIDComp);
    if (userIDComp < userAmount)
      uProfPT[userIDComp] = empty_struct;
    break;
  case 'C':
  case 'c':
    for (int i = 0; i <= userAmount; i++) {
      printf("Name: %s %s", uProfPT[i].userNameF, uProfPT[i].userNameL);
      printf("Address: %s", uProfPT[i].address);
      printf("Sex : %s %s", uProfPT[i].sex);
      // Work in Progress
    }
    menuReg_Chat();
    break;
  case 'X':
  case 'x':
    menuReg_Exit();
    break;
  default:
    printf("\nInvalid input, please only use what's indicated.\n");
  }
}

void menuMng_Vapp(struct userStats *uProfPT, struct vappStats *vProfPT,
                  int userAmount, int vappAmount) {}

void menuMng_Chat() {}

void menuMng_Export() {}

void menuMng_Import() {}

void menuMng_Exit() {}

void menuMng(struct userStats *uProfPT, struct vappStats *vProfPT,
             int userAmount, int vappAmount) {

  displayMenu_B();

  char cOpt;

  printf("\nEnter Choice: ");
  scanf(" %c", &cOpt);

  switch (cOpt) {
  case 'A':
  case 'a':
    menuMng_User(uProfPT, vProfPT, userAmount, vappAmount);
    break;
  case 'B':
  case 'b':
    menuMng_Vapp(uProfPT, vProfPT, userAmount, vappAmount);
    break;
  case 'C':
  case 'c':
    menuMng_Chat();
    break;
  case 'D':
  case 'd':
    menuMng_Export();
    break;
  case 'E':
  case 'e':
    menuMng_Import();
    break;
  case 'X':
  case 'x':
    menuMng_Exit();
    break;
  default:
    printf("\nInvalid input, please only use what's indicated.\n");
  }
}

/* The main menu that the user will be at initially. */

void menuMain(struct userStats *uProfPT, struct vappStats *vProfPT,
              int userAmount, int vappAmount) {

  displayMenu();

  char cOpt;

  printf("\nEnter Choice: ");
  scanf(" %c", &cOpt);

  switch (cOpt) {
  case 'A':
  case 'a':
    menuReg(uProfPT, vProfPT, userAmount, vappAmount);
    break;
  case 'B':
  case 'b':
    menuMng(uProfPT, vProfPT, userAmount, vappAmount);
    break;
  case 'X':
  case 'x':
    break;
  default:
    printf("\nInvalid input, please only use what's indicated.\n");
  }
};

/* Here lies the function main. */

int main() {

  /* variable declaration */

  int userAmount = 0; // refers to the amount of users that inputted in the
                      // program, initially starts with 0
  struct userStats
      uProf[MAX_USERS]; // structural array for users in the program
  struct userStats *uProfPT = uProf; // pointers for uProf to access values

  int vappAmount = 0;
  struct vappStats
      vProf[MAX_USERS]; // structural array for users in the program
  struct vappStats *vProfPT = vProf; // pointers for uProf to access values

  /* program introduction */

  displayIntro();

  /* main project menu output */

  menuMain(uProfPT, vProfPT, userAmount, vappAmount);

  return 0;
}
