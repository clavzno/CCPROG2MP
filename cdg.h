/* Library declarations */
#include <stdio.h>
#include <string.h>
#include <unistd.h> //Required for the display_loading function, alternate is <windows.h>

/* Define directives for max users since dynamic memory allocation is hard */
#define MAX_USERS 100


/* UI Functions and define directives */

/* Define directives for cosmetic purposes in the program such as the
main menu and headers when under a certain module. */
// \e == (Esc)ape code, [ for ANSI code, m for end of ANSI code
#define ANSI_FLASH_RED "\e[0;6;31m"
#define ANSI_FLASH_BLUE "\e[0;6;34m"
#define ANSI_FLASH_WHITE "\e[0;6;1m"
#define ANSI_RED "\e[0;31m" // FOR ERRORS
#define ANSI_BLUE "\e[0;34m" // FOR TIPS
#define ANSI_WHITE "\e[0;1m"
#define ANSI_YELLOW "\e[0;93m" // menu 1: vaccination registration
#define ANSI_GREEN "\e[0;92m"  // menu 2: data management
#define ANSI_CYAN "\e[0;96m"   // menu 3: settings
#define ANSI_OFF "\e[0m"	   // removes ANSI code and restores to default text
// COLOR_OFF to end command; 1 = bold, 5 = slow blink, X = color, m = end of ANSI code
#define ANSI_PREVLINE "\e[1A" // moves cursor to previous line


/**********************************************/

/* Function Prototypes */



