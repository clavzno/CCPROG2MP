/***************************************************************************

CCPROG2 Machine Project - Vaccination Registration Application with Chatbot

Description: // WIP //

Programmed by: Justin Patrick M. De Grano - S18B
Last modified: 2-23-2022
Version: V0.1C

***************************************************************************/

#include <stdio.h>
#include <string.h>

/* These are display functions which serve more as a display guide
   & decoration part for the program to the end-user. */

void displayLine() { printf("\n------------------------------------------\n"); }

void // Printed display menu
displayMenu() {

  displayLine();

  printf("\nVaxDB Primary Menu\n");

  displayLine();

  printf("\nInput your Next Course of Action: \n\n");

  printf("(A) Vaccine Registration\n");
  printf("(B) Data/Settings Management\n");
  printf("(X) Exit the Program\n");

  displayLine();
}

void // Printed display menu (option A - vaxreg)
displayMenu_A() {

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

void // Printed display menu (option B - )
displayMenu_B() {

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

void menuReg() {}

void menuReg_User() {}

void menuReg_Vapp() {}

void menuReg_Chat() {}

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

void menuMng() {}

void menuMng_User() {}

void menuMng_Vapp() {}

void menuMng_Chat() {}

void menuMng_Export() {}

void menuMng_Import() {}

void menuMng_Exit() {}

    /* Function for choosing options and validation check. */

int menuOpt_Check() {}

char menuOpt() {}

/* Here lies the function main. */

int main() {
  displayMenu();
  return 0;
}
