#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define ANSI_REPEATCHOICE "\r\033[1A\r\033[K\r\033[1A\r\033[K\r\033[1A\r\033[K"

void displayPassword_ast(char password[])
{
  int len = strlen(password);

  for (int i = 0; i < len; i++)
  {
    if (password[i] != ' ' && password[i] != '\n')
    {
      password[i] = '*';
    }
  }
}

int main()
{
    char password[10];
    char astpassword[10];
    printf("enter password: ");
    scanf("%s", password);
    //store the asterisk password in astpassword
    displayPassword_ast(password);
    strcpy(astpassword, password);
    system("pause");
    printf(ANSI_REPEATCHOICE);
    printf(ANSI_REPEATCHOICE);
    printf("password: %s", astpassword);
}