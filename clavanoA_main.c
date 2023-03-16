#include "clavanoA.c"

/***********************************************************************/
/* Driver code */
int main()
{
	struct user Profiles[MAX_USERS];
	struct user *ptr = Profiles; // pointer to Profiles to access values
	struct settings Settings;
	struct settings *setptr = &Settings; // pointer to Settings to access values

	int num_users = 0; // we know the max size but we don't know the number of users
	int *num_usersptr = &num_users;

	// note use malloc to add new user space?
	display_loading();
	menu_main(ptr, num_usersptr, setptr);
	return 0;
}