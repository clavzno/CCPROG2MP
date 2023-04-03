#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_OFF "\x1b[0m"

int random_num(void)
{
    return rand() % 10;
}

char random_uppercase(void)
{
    return 'A' + rand() % 26;
}

char random_lowercase(void)
{
    return 'a' + rand() % 26;
}

char random_special(void)
{
    char special_chars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+', '=', '{', '}', '[', ']', '\\', '|', ';', ':', '\'', '\"', '<', '>', ',', '.', '/', '?', '~', '`'};
    int num_chars = sizeof(special_chars) / sizeof(char);
    return special_chars[rand() % num_chars];
}

void generate_password(int length, int has_uppercase, int has_lowercase, int has_numbers, int has_special_chars)
{
    int i;
    char password[length + 1]; // +1 for null character at end of string

    for (i = 0; i < length; i++)
    {
        int type = rand() % 4; // Choose random type of character to generate

        if (type == 0 && has_uppercase)
        {
            password[i] = random_uppercase();
        }
        else if (type == 1 && has_lowercase)
        {
            password[i] = random_lowercase();
        }
        else if (type == 2 && has_numbers)
        {
            password[i] = random_num() + '0'; // Convert int to char
        }
        else if (type == 3 && has_special_chars)
        {
            password[i] = random_special();
        }
        else
        {
            // If the selected type is not allowed, generate a new character of a different type
            i--;
            continue;
        }
    }

    password[length] = '\0'; // Add null character at end of string
    printf(ANSI_GREEN "GENERATED PASSWORD:" ANSI_OFF " %s\n", password);
}

int main(void)
{
    int length, has_uppercase, has_lowercase, has_numbers, has_special_chars, choice;
    char buffer[255]; // Buffer for reading from file

    srand(time(NULL));

    printf(ANSI_RED "WELCOME TO THE PASSWORD GENERATOR\n" ANSI_OFF);
    printf("*****************************\n");
    printf("[1] Generate password\n");
    printf("[2] Import specifications from file\n");
    printf("*****************************\n");
    printf("> ");
    scanf("%d", &choice);
    getchar();

    if (choice == 1)
    {
        printf("Enter password length: ");
        scanf("%d", &length);
        getchar();

        printf("Include uppercase letters? (0/1): ");
        scanf("%d", &has_uppercase);
        getchar();

        printf("Include lowercase letters? (0/1): ");
        scanf("%d", &has_lowercase);
        getchar();

        printf("Include numbers? (0/1): ");
        scanf("%d", &has_numbers);
        getchar();

        printf("Include special characters? (0/1): ");
        scanf("%d", &has_special_chars);

        generate_password(length, has_uppercase, has_lowercase, has_numbers, has_special_chars);
    }
    else if (choice == 2)
    {
        FILE *fp = fopen("input.txt", "r");         // Open file for reading
        FILE *fp_output = fopen("output.txt", "w"); // Open file for writing

        if (fp == NULL || fp_output == NULL)
        {
            printf("Error: Could not open file.\n");
            return 1;
        }

        fscanf(fp, "%d", &length);
        fscanf(fp, "%d", &has_uppercase);
        fscanf(fp, "%d", &has_lowercase);
        fscanf(fp, "%d", &has_numbers);
        fscanf(fp, "%d", &has_special_chars);

        generate_password(length, has_uppercase, has_lowercase, has_numbers, has_special_chars);
        fprintf(fp_output, "%d\n%d\n%d\n%d\n%d\n", length, has_uppercase, has_lowercase, has_numbers, has_special_chars);
        fclose(fp);
        fclose(fp_output);
    }
    else
    {
        printf("Error: Invalid option.\n");
        return 1;
    }

    return 0;
}
