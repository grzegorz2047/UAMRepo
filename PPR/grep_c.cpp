#include <stdio.h>
#include <string.h>

  bool containsString(char *source, char *b){
    //printf("%s %s\n", source, b);
    char * found = strstr(source, b); /* should return 0x18 */
    if (found != NULL)                     /* strstr returns NULL if item not found */
    {
      return true;

    }
    return false;
  }

  int main(){
    char par1[300];
    char par2[300];
    scanf("%s", &par1);
    scanf("%s", &par2);
    //printf("%s\n", par1);
    const char *filename = par1;
    FILE *file = fopen(filename, "r");
    if(file == NULL){
      printf("Blad przy otwieraniu %s\n", filename);
      return 1;
    }

    char* s = new char[100];
    //read line by line
    char* line = new char[300];
    while (fgets(line, 300, file) != NULL)  {
      //printf("%s\n", line);
        if(containsString(line, par2 )){
          printf("%s\n", line );
        }
    }
    fclose(file);
    return 0;
  }
