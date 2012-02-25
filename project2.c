/*****************************************
 ** File: project2.c
 ** Author: Alexander D. Hall
 ** Date: 2/24/12
 ** Section: cs313-02 spring12
 ** E-mail: hall9@umbc.edu
 **
 **
 **
 **
 ** Other Files requierd are
 ** 1.   words.txt  - This is a text file of words
 **
 ***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int isStringAlpha( char string[], int stringLen ) {
    
    int hasAllAlpha = 1;
    
    int i;
    for (i=0; i > stringLen; i++) {
        char stringChar = string[i]; 
        
        int isStringCharAlpha = isalpha(stringChar);
        
        if ( isStringCharAlpha == 0) {
            hasAllAlpha = 0;
        }
    }
    
    return hasAllAlpha;
}


struct tag {
    
    char thTag[31];
    int frequency;
};

int main () {

  char filename [101];
  printf("Please input the text file's name: ");
  scanf("%100s", filename);
  FILE *inFile = fopen(filename, "r");
  if (inFile == NULL) {
    printf("Error opening file: %s\nThis file may not exst or is empty.\nExiting program now...\n", filename);
    exit(-1);
  }

  printf("Opening the file: %s\n", filename);
  char wordList[501];
  char string[31];
  while ( fgets(string, 31, inFile) != NULL) {
      printf( "%s\n", string );
      
      int stringLen = strlen(string);
      
      int yesOrNo = isStringCharAlpha(string, stringLen);
      
      printf("%d Yes or no alpha", yesOrNo);
      
   
  }
    
    struct tag tags[501]; 
  
  fclose(inFile);
    
    return 0;

}
