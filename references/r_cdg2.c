/***************
CCPROG2 S18 GRP <NUMBER>
Clavano, Angelica Therese
De Grano, Justin Patrick

Date Created: 2023-03-22
Date Merged: 2023-04-02
***************/

#include "cdg.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void reg_User(struct user *userProfilesptr, int *userAmountptr)
{
    int checkid = 0, checkpass = 0;
    int tempid;
    int emptyprofile = checkEmpty(userProfilesptr, userAmountptr);
    printf(ANSI_GREEN "Empty profile found at index %d\n" ANSI_OFF, emptyprofile);
    sleep(1);
    printf(ANSI_PREVLINE);
    // look for empty profile display index
    // prompt for id
    displayLine_ast();
    printf("User Registration\n" ANSI_BLUE "Please input the requested data.\n\n" ANSI_OFF "Enter User ID:\n\n");
    displayLine_ast();

    while (checkid > 0)
    {
        printf("Enter your choice below:\n> ");
        scanf("%d", &tempid);
        checkid = checkID(userProfilesptr, userAmountptr, tempid);

        if (checkid > 0)
        {
            printf(ANSI_RED "Error: ID already taken.\n" ANSI_OFF);
            printf(ANSI_REPEATCHOICE);
        }
    }

    printf(ANSI_GREEN "userID is available." ANSI_OFF);
    userProfilesptr[emptyprofile].userID = tempid;
    // check if id is taken
    // prompt for password
    // make user enter password twice
    // check if password is valid
    // prompt for first name and append to name
    // prompt for last name and append to name
    // prompt for contact number
    // prompt for address
    // prompt for sex [Male/Female]
    // prompt for first dose date
    // prompt for first dose type
    // prompt for first dose location
    // prompt for more than 1 dose

    // display all data ask for changes
    //  if yes, prompt for which data to change
    //  edit data
}

void reg_Appt(struct user *userProfilesptr, int *userAmountptr)
{
    printf("You are in regappt\n");
    // prompt for id
    // prompt for name
    // prompt for location
    // prompt for vaccine
    // prompt for date
    // prompt for time
    // prompt for dose
}

void reg_Chat(struct user *userProfilesptr, int *userAmountptr)
{
    printf("You are in regchat\n");
    // display questions
    // prompt for choice
    // display answers
    // display questions
}

void management(struct user *userProfilesptr, int *userAmountptr)
{
    printf("welcome admin\n");
}

int mainmenu(struct user *userProfilesptr, int *userAmountptr)
{
    int choice = 0;

    // do {
    displayLine_ast();

    printf("Welcome to " ANSI_RED "Assisti" ANSI_BLUE "VAX!" ANSI_OFF
           " Your Personal Vaccination Assistant\n\n");
    printf("Choose your option:\n[1] User Registration\n[2] Schedule an "
           "Appointment\n[3] Talk with AssistiVAX\n[4] Exit\n" ANSI_BLUE
           "[5] Admin Data Management" ANSI_OFF "\n\n");

    displayLine_ast();

    printf("Enter your choice below:\n> ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
    {
        system("cls");
        reg_User(userProfilesptr, userAmountptr);
        break;
    }
    case 2:
    {
        system("cls");
        reg_Appt(userProfilesptr, userAmountptr);
        break;
    }
    case 3:
    {
        system("cls");
        reg_Chat(userProfilesptr, userAmountptr);
        break;
    }
    case 4:
    {
        system("cls");
        return 0;
    }
    case 5:
    {
        system("cls");
        management(userProfilesptr, userAmountptr);
        break;
    }
    default:
    {
        printf(ANSI_REPEATCHOICE);
        printf(ANSI_RED "Error: Invalid Choice\n" ANSI_OFF);
        sleep(2);
        system("cls");
        break;
    }
    }
    //} while (choice != 4);

    fflush(stdin);
    return 0;
}

int main()
{
    struct user userProfiles[MAX_USERS];
    struct user *userProfilesptr = userProfiles;
    int userAmount = 0;
    int *userAmountptr = &userAmount; // to ensure access bc c is weird

    // displayLoading();
    system("cls");
    // display menu
    mainmenu(userProfilesptr, userAmountptr);
    // when menu exit, display exit
    displayExit();
    return 0;
}