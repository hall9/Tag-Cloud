/*****************************************
 ** File: project2.c
 ** Author: Alexander D. Hall
 ** Date: 2/24/12
 ** Section: cs313-02 spring12
 ** E-mail: hall9@umbc.edu
 **
 **     This file contails the main driver program for project 2.
 ** This program read the file specified and reads each word in the file.
 ** The program then counts the words frequency. It then sorts the whole list
 ** by highest to lowest. Then orders the top 20 by aplah and prints them out.
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
#define true 1
#define false 0
typedef char bool;


/* This takes in the word(string) and also its length
    then outputs true if its all alpha or false if not all char are alpha */
bool isStringAlpha( char string[], int stringLen ) {
    
    int hasAllAlpha = true;
    
    int i;
    for (i=0; i < stringLen-1; i++) {
        
        if ( isalpha(string[i]) == 0 ) {
            hasAllAlpha = false;
            i = stringLen;
        }
    }
    
    return hasAllAlpha;
}


/* This takes in the word(string) and also its length
    then output the word in lower case  */
int toStringLowerCase( char string[], int stringLen) {
    
    int i;
    for (i=0; i < stringLen-1; i++) {
        string[i] = tolower(string[i]);
    }
}

// Create the struct tag
// which contain the a word and its frequency
struct tag {
    
    char theTag[31];
    int frequency;
};

int main () {

    // Asks for file name.
  char filename [101];
  printf("Please input the text file's name: ");
  scanf("%100s", filename);
  FILE *inFile = fopen(filename, "r");
  if (inFile == NULL) {
    printf("Error opening file: %s\nThis file may not exst or is empty.\nExiting program now...\n", filename);
    exit(-1);
  }

    // create the an array of tags
    struct tag tags[501];
    int tagNumber = 0; 
    
  printf("Opening the file: %s\n", filename);
  char string[31];
    // Start by reading the file and looking at each word
  while ( fgets(string, 31, inFile) != NULL) {
    
      int stringLen = strlen(string);
      
      // does the word only contain alpha test
      bool isStringAlphaTest = isStringAlpha(string, stringLen);
      
      
      // if word is longer than 4 char & if it only contains alpha
      if ( stringLen > 4 && isStringAlphaTest ) {
              
                // change to lower case
              toStringLowerCase(string, stringLen);
              int tagAdded = 0;
              int i;
                // if word hasn't been seen before create struct
              for (i=0; i < tagNumber+1; i++) {
                  if (strcmp(tags[i].theTag, string) == 0) {
                      tags[i].frequency = tags[i].frequency + 1;
                      tagAdded = 1;
                  }
              }
              // if the tag was not just added it must have seen bofore
                // add one to its frequency
              if (tagAdded == 0) {
                      strcpy(tags[tagNumber].theTag, string);
                      tags[tagNumber].frequency = 1;
                      tagNumber++;
              }
      }
  }
    
  fclose(inFile);
    
    int b, n;
    struct tag temp;
    
    // Sort the struct array by highest frequency to lowest
    for (b=0; b < tagNumber - 1; ++b) {
        for (n = 0; n < tagNumber - 1 - b; ++n ) {
            if (tags[n].frequency < tags[n+1].frequency) {
                temp = tags[n+1];
                tags[n+1] = tags[n];
                tags[n] = temp;
            }
        }
    }
    
    // Sort the top 20 by alpha
    int v, c;
    struct tag temps;
    for (v=0; v < 20 - 1; ++v) {
        for (c = 0; c < 20 - 1 - v; ++c ) {
            if (strcmp(tags[c].theTag, tags[c+1].theTag) >= 1) {
                temps = tags[c+1];
                tags[c+1] = tags[c];
                tags[c] = temps;
            }
        }
    }
    
    // print only the top 20 in the array.
    printf("\nTop 20 Tags: \n");
    int k;
    for (k=0; k < 20; k++) {
        printf("%s", tags[k].theTag);
        printf("%d\n", tags[k].frequency);
    }
    
    return 0;

}
