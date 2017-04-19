#include <stdio.h>

  int main(){
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
    while (fgets(line, 300, file) != NULL)  {
        printf(line);
        lines++;
    }
    rewind(file);
    while (fscanf(file, "%s", &s) != EOF) {
      //printf("%s\n", s);
      words++;
    }
    //printf("%i ", lines);
    rewind(file);
    char c;
    while (fscanf(file, "%c", &c) != EOF) {
      //if(c != ' '){
        //printf("%c", c);
        chars ++;
      //}
    }

    printf("%i %i %i\n",lines, chars, words );
    fclose(file);
    return 0;
  }
