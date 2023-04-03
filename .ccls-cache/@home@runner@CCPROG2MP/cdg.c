/***************
CCPROG2 S18 GRP <NUMBER>
Clavano, Angelica Therese
De Grano, Justin Patrick

Date Created: 2023-03-22
Date Merged: 2023-04-02
***************/

/* Necessary Library & Header Files */
#include "cdg.h"

void mainmenu(struct *userProfilesptr, struct *userAmountptr) {
  int choice;
  return 0;
  printf("Hello World!");
}

int main() {
  struct user userProfiles[MAX_USERS];
  struct user *userProfilesptr = userProfiles;
  int userAmount = 0;
  int *userAmountptr = &userAmount; // to ensure access bc c is weird

  // display_loading();
  mainmenu(userProfilesptr, userAmountptr);
  return 0;
}