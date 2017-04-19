#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

  int main(){
    int FileChatName = 1;
    const char *filename = "czat";
    filename.a
    FILE *file = fopen(filename, "r");
    while(file != NULL){
      //printf("Blad przy otwieraniu %s\n", filename);
      return 1;
    }
    const char *filename = "file01.txt";
    FILE *file = fopen(filename, "r");
    if(file == NULL){
      printf("Blad przy otwieraniu %s\n", filename);
      return 1;
    }
    int lines = 0;
    int chars = 0;
    int words = 0;
    char s[100];
    //read line by line
    char* line = new char[300];
    //Na patencie
    int fileLength = 0;
    while (fgets(line, 300, file) != NULL)  {
        fileLength++;
    }
    rewind(file);
    char * exit = NULL;
    int timer = time(NULL);
    srand(timer);
    int random = 1;
    //printf("%i", fileLength);
    fileLength--;
    while(true){
      random = rand() % fileLength;

      //printf("%i", random);
      int lineNumber = 0;
      while (fgets(line, 300, file) != NULL)  {
          if(lineNumber == random){
            printf("%s", line);
            break;
          }
          lineNumber++;
      }
      rewind(file);
      char answer[300];
      scanf("%s", answer);
      //printf("%s\n", answer);
      if(strcmp(answer, "exit") == 0){
        return false;
      }
      else{
        //Zapisz do pliku
      }
    }


    rewind(file);
    fclose(file);
    return 0;
  }
