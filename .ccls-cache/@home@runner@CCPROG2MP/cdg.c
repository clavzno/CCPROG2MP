/***************
CCPROG2 S18 GRP <NUMBER>
Clavano, Angelica Therese
De Grano, Justin Patrick

Date Created: 2023-03-22
Date Merged: 2023-04-02
***************/
#include "cdg.h"

void mainmenu(struct *userProfilesptr, struct *userAmountptr) {
	int choice;
	printf("TEST HELLO WORLD PLEASE TELL ME THIS WORKS");
	return 0;
}

int main() {
  struct user userProfiles[MAX_USERS];
  struct user *userProfilesptr = userProfiles;
  int userAmount = 0;
  int *userAmountptr = &userAmount; // to ensure access bc c is weird

  displayLoading();
  mainmenu(userProfilesptr, userAmountptr);
  return 0;
}