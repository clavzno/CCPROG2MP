#include <stdio.h>
#include <string.h>

int file_countLines(FILE *file)
{
  int count = 0;
  if (file == NULL)
  {
    printf("Error opening file!");
    return -1;
  }

  int c;
  while ((c = fgetc(file)) != EOF)
  {
    if (c == '\n')
    {
      count++;
    }
  }
  return count+1; //+1 because we want to include the first line
}

int main()
{
  FILE *file = fopen("Chatbot.txt", "r");
  int count = file_countLines(file);
  printf("Number of lines: %d", count);
  fclose(file);
  return 0;
}