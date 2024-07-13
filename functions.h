#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h> // for system("cls"), dynamic memory allocation
#include <string.h>
#include "structs.h"

/**
 * @brief Finds the index of the first empty user profile in the array.
 * @param userFilePtr Pointer to the array of user profiles.
 * @return The index of the first empty user profile in the array, assuming empty profiles have userID = 0.\
 * If no empty profiles are found, returns -1, an invalid index.
 */
int findEmptyUserIndex(struct userFile *userFilePtr) {
    int top = -1;
    for (int i = 0; i < sizeof(userFilePtr) / sizeof(userFilePtr[0]); i++) {
        if (userFilePtr[i].userID = 0) {
            top = i;
        }
        else
            top = -1;
    }
    return top;
}

int regmenu(struct userFile *userFilePtr) {
    int choice;
    int userID;
    char fullName[21], password[11], address[50], contactNumber[12], sex, firstDoseDate[10], firstDoseVaccine[11], firstDoseLocation[11];
    char secondDoseDate[10], secondDoseVaccine[11], secondDoseLocation[11], firstBoosterDate[10], firstBoosterVaccine[11], firstBoosterLocation[12], secondBoosterDate[10], secondBoosterVaccine[11], secondBoosterLocation[11];

    do {
    printf("--User Registration--\n");
    
    //find empty array index
    int emptyIndex = findEmptyUserIndex(userFilePtr);
    if (emptyIndex == -1) {
        printf("No more empty user profiles.\n");
        break;
    }

    //begin prompting user for input here
    int userID = emptyIndex + 1;
    printf("User ID: %d\n", userID);
    printf("Enter full name: ");
    scanf("%s", fullName);
    printf("Enter password: ");

    printf("Add another user?\n"
           "[1] Yes\n"
           "[0] No\n");
    scanf("%d", &choice);
    } while (choice!= 0);
    return 0;
}

int apptmenu(struct userFile *userFilePtr) {
    printf("In Progress\n");
    return 0;
}
int chatbotmenu(struct userFile *userFilePtr) {
    printf("In Progress\n");
    return 0;
}

int adminmenu(struct userFile *userFilePtr) {
    int choice;
    do {
        printf("---Admin Controls---\n"); // data management menu
        printf("[1] User Profiles\n"
               "[2] Vaccine Appointments\n"
               "[3] Chatbot\n"
               "[4] Import/Export Data\n"
               "[0] Exit Admin Menu\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1: {
                printf("[1] Add New User\n"
                       "[2] Edit User\n"
                       "[3] Delete User\n"
                       "[4] View All Users\n"
                       "[0] Exit Admin: User Profiles Menu\n");
                break;
            }
            case 2: {
                printf("[1] Add New Appointment\n"
                        "[2] Edit Appointment\n"
                        "[3] Delete Appointment\n"
                        "[4] View All Appointments\n"
                        "[0] Exit Admin: Vaccine Appointments Menu\n");
                break;
            }
            case 3: {
                printf("[1] Add New Question and Answer\n"
                        "[2] Edit Question and Answer\n"
                        "[3] Delete Question and Answer\n"
                        "[4] View All Questions and Answers\n"
                        "[0] Exit Admin: Chatbot Menu\n");
                break;
            }
            case 4: {
                printf("[1] Import Data\n"
                        "[2] Export Data\n"
                        "[0] Exit Admin: Import/Export Data Menu\n");
                break;
            }
            case 0: {
                break;
            }
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
    
    return 0;
}

int mainmenu(struct userFile *userFilePtr) {
    int choice;
    do {
        printf("\n---Main Menu---\n");
        printf("[1] Registration\n"
               "[2] Add Appointment\n"
               "[3] Talk to Chatbot\n"
               "[4] Admin Controls\n"
               "[0] Exit Program\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        fflush(stdin);

        switch (choice) {
            case 1: {
                regmenu(userFilePtr);
                break;
            }
            case 2: {
                apptmenu(userFilePtr);
                break;
            }
            case 3: {
                chatbotmenu(userFilePtr);
                break;
            }
            case 4: {
                adminmenu(userFilePtr);
                break;
            }
            case 0: {
                break;
            }
            default: 
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);
}



#endif 