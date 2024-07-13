#include "functions.h"
#include "structs.h"

/**
 * @author Jack Clavano
 * @date 2023-12-02, 2023-12-12, 2023-12-13m 2024-06-17
*/

/**
 * @brief Initializes all userIDs to 0, meaning empty.
 * @param userFilePtr Pointer to the array of user profiles.
*/
void initializeUserIDs(struct userFile *userFilePtr) {
    for (int i = 0; i < MAX_USERS; i++) {
        userFilePtr[i].userID = 0;
    }
}

int main() {
    //declare userprofiles
    struct userFile userFile[MAX_USERS];
    //set pointer to userprofiles
    struct userFile *userFilePtr = userFile;
    //initialize userIDs to be 0 meaning empty
    initializeUserIDs(userFilePtr);
    // run menu
    mainmenu(userFilePtr);
    // when finished, exit program
    system("cls");
    printf("\nExiting program...\n");
}