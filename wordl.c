//q1.c
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
const char * const GREEN = "\x1b[32m";
const char * const YELLOW = "\x1b[33m";
const char * const WHITE = "\x1b[0m";
const char * current = WHITE;

void setColour(const char *colour) {
  if (current == colour) return;
  printf("%s", colour);
  current = colour;
}

int main(int argc, char *argv[]){
  if (argc != 2){
    printf("Invalid number of command line arguments\n");
    exit(0);
  }
  char *word = argv[1];
  int n = strlen(word);
  if (n > 12){
    printf("Code longer than 12 characters, invalid input\n");
    exit(0);
  }
  int freqlist[26];
  int wordcodearr[n]; //resets every loop, 1 is green, 2 is yellow.
  for (int i = 0; i < 6; i++){
    for (int k = 0; k < 26; k++){
        freqlist[k] = 0;
}
    for (int a = 97; a <= 122; a++){
      for (int j = 0; j < n; j++){
        if ((char) a == word[j]){
          // printf("%c vs %c\n", (char) i, word[j]);
           freqlist[a-97] += 1;
      }
    }
    }
    for (int k = 0; k < n; k++){ //reset for incoming guess
            wordcodearr[k] = 0;
    }
    char guess[n];
    
    printf("Enter guess: ");
    scanf("%s", guess);
    if (strlen(guess) != n){
      setColour(WHITE);
      printf("Invalid guess, guess length must match word length\n");
      exit(0);
    }
    for (int j = 0; j < n; j++){ //green loop
      if (guess[j] == word[j]){
        wordcodearr[j] = 1;
        for (int l = 97; l <= 122; l++){
          if ((char) l == word[j]){
                //printf("%c vs %c\n", (char) i, word[j]);
                freqlist[l-97] -= 1; //reduces freq for yellow loop
        }
      }
    }
    }
    for (int j = 0; j < n; j++){ //yellow loop
        for (int l = 97; l <= 122; l++){
          if (((char) l == guess[j]) && (freqlist[l-97] > 0) && (wordcodearr[j]!= 1)){
                //printf("%c vs %c\n", (char) i, word[j]);
                wordcodearr[j] = 2; //value for yellow
            freqlist[l-97] -= 1; //freq decreased
        }
      }
    }
    for (int j = 0; j < n; j++){
        
      if (wordcodearr[j]== 1){
        setColour(GREEN);
      }
      else if (wordcodearr[j] == 2){
        setColour(YELLOW);
      }
      else {
        setColour(WHITE);
      }
      printf("%c", guess[j]);
      
    }
    
    printf("\n");
    setColour(WHITE);
    if (strcmp(guess, word) == 0){ //can't compare using ==
      
  	  printf("Finished in %d guesses\n", i+1);
    	exit(0);
}
  }
  
  printf("Failed to guess the word: %s\n", word);
}

