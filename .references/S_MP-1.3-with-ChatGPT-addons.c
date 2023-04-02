#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "UserRegFunc.c"

// Display Functions

void gotoxy(short x, short y)                                           
{
	COORD pos = {x,y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void 
displayLine ()
{
	printf("===========================================================================");
}

void 
displayTop()
{
	displayLine();
	printf("\n                          Animo Vax Registration	");
	printf("\n                              Green is Clean!\n");
  	displayLine();
}

void
displayOpt()
{
  printf("\n  	a. User Registration Menu");
  printf("\n  	b. Data Management Menu");
  printf("\n  	c. Frequently Asked Questions");
  printf("\n	d. Exit the Application\n");
  displayLine();
}

void 
displayMenu(char *pOption)
{
  displayTop();
  displayOpt();
  printf("\n  Enter Option: ");
  scanf(" %c", pOption);
  system("cls");
}

void 
displayUserReg ()
{
	printf("\n");
	displayLine();
  	printf ("\n                          User Registration Menu\n");
  	displayLine();
  	
}

void // tentative function used for checking previous inputs (ex: no duplicate uid)
InputChecker (struct UserReg UR)
{
//	int i, check;
//	for (i = 0; i < 4; i++)
//	{
//		if (UR.userID)	
//	} 
}

int main ()
{
	struct UserReg UR;
  	char option;
  	
  	do
  	{
  		displayMenu(&option);
	} while (option != 'a' && option != 'b' && option != 'c' && option != 'd');
	
  	switch (option)
  	{
  		case 'a':
  			system ("cls");	
  			displayUserReg();
  			UserRegInput (UR);
  			break;
  		case 'b':
		  	//displayDataMan();
			break;
		case 'c':
			//displayFAQ();
			break;
		case 'd':
			printf("\n	     	     Thank you for using the program!");
			break;		
	}
	
	return 0;
}
  