#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_QUESTION_LEN 100
#define MAX_ANSWER_LEN 100

int reg_Chat(char *input_question)
{
    char question[MAX_QUESTION_LEN], answer[MAX_ANSWER_LEN];
    FILE *fp, *fp_history;
    fp = fopen("chatbot.txt", "r");
    fp_history = fopen("chathistory.txt", "a"); // open file for appending

    int found = 0;

    if (fp == NULL || fp_history == NULL)
    {
        printf("Error opening files!\n");
        return 1;
    }

    while (fgets(question, MAX_QUESTION_LEN, fp))
    {
        fgets(answer, MAX_ANSWER_LEN, fp);
        question[strcspn(question, "\n")] = 0; // remove trailing newline
        answer[strcspn(answer, "\n")] = 0;

        if (strcmp(question, input_question) == 0)
        {
            printf("[AssistiVax]: %s\n", answer);
            fprintf(fp_history, "%s\n", input_question); // write question to file
            fprintf(fp_history, "%s\n\n", answer);       // write answer to file
            found = 1;                                      // set flag to indicate that answer was found
            break;
        }
    }

    if (!found)
    {
        printf("Sorry, I don't know the answer. Please type another question.\n");
        fprintf(fp_history, "%s\n", input_question); // write question to file
        fprintf(fp_history, "Sorry, I don't know the answer. Please type another question.\n\n");        // write unknown answer to file
    }

    fclose(fp);
    fclose(fp_history);
    return 0;
}

int main()
{
    char input_question[MAX_QUESTION_LEN];
    printf("Ask me a question (type 'exit' to quit): ");
    fgets(input_question, MAX_QUESTION_LEN, stdin);    // read user input
    input_question[strcspn(input_question, "\n")] = 0; // remove trailing newline

    while (strcmp(input_question, "exit") != 0) // continue prompting user until they type "exit"
    {
        reg_Chat(input_question); // pass user input to reg_Chat function
        printf("\nAsk me a question (type 'exit' to quit): ");
        fgets(input_question, MAX_QUESTION_LEN, stdin);    // read user input
        input_question[strcspn(input_question, "\n")] = 0; // remove trailing newline
    }

    return 0;
}
