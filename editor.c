#include <stdio.h>
#include <string.h>

void editLine(char *buffer, int currentLine)
{
  for (int i = 0; i < currentLine; i++)
  {
    // locate newline character in buffer
    buffer = strchr(buffer, '\n');
    if (buffer == NULL) {
            return; // No more lines to edit
    }
    buffer++;
    // buffer now points to the line the user wants to edit
  }

  // lineEnd points to the end of the line the user wants to edit
  char *lineEnd = strchr(buffer, '\n');
  char restOfTheFile[1024] = {0};

  if (lineEnd != NULL) {
        strcpy(restOfTheFile, lineEnd); // Copy the rest of the file
  } 
  else {
      restOfTheFile[0] = '\0'; // No more lines after the current line
  }

  // take input from user and store it in buffer
  printf("Enter your edit: ");
  scanf("%s", buffer);

  // Append the rest of the file to the buffer
  strcat(buffer, restOfTheFile);
}

void printLinebyLine(char *buffer)
{
  int n = strlen(buffer);
  int counter = 0;
  printf("%d ", counter);

  // basically increase counter whenever newline comes
  for (int i = 0; i < n; i++)
  {
    printf("%c", buffer[i]);
    if (buffer[i] == '\n')
    {
      counter++;
      printf("%d ", counter);
    }
  }
  
  printf("\n");
}

int main(int argc, char **argv)
{
  // loading content in the buffer
  FILE *f = fopen(argv[1], "r");
  char buffer[1024] = {0};
  fread(buffer, 1024, 1, f);
  fclose(f);

  printf("File Contents : \n");
  printLinebyLine(buffer);

  // line the user wants to edit
  int currentLine = 0;
  printf("\nEnter Line number you want to edit: "); 
  scanf("%d", &currentLine);

  // make edits
  editLine(buffer, currentLine);

  // write to file
  f = fopen(argv[1], "w");
  fwrite(buffer, strlen(buffer), 1, f);
  fclose(f);

  printf("\nFile Edited! : \n");
  printLinebyLine(buffer);
}
