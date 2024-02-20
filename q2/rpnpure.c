#include <stdio.h>
#include <stdlib.h>

int operate(int a, int b, char op){
  if (op=='p') return a+b;
  if (op=='s') return a-b;
  if (op=='/') return a/b;
  if (op=='*') return a*b;
  return 0;
}

int main(){

  int size = 4;
  int index = 0;
  int *narr = malloc(size*sizeof(int));
  int curnum = 0;
  int readingnum = 0;
  int multiplier = 1;

  while (! feof(stdin)){
    char rc = getchar();

    if (rc == EOF){
      //finish all operation > print output
      if (readingnum==1){
        narr[0] = curnum*multiplier;
      }
      printf("%d\n",narr[0]);
      free(narr);
      return 0;
    }

    char c = rc;
    if (c == '\t' || c == ' ' || c == '\n'){
      //if reading number, finalise the number and add in the array
      if (readingnum==1){
        readingnum = 0;
        //add to array
        if (index+1==size){
          size = size*2;
          int *newnarr = malloc(size*sizeof(int));
          for (int i = 0; i <= index; ++i){
            newnarr[i] = narr[i];
          }
          free(narr);
          narr = newnarr;
        }
        narr[index] = curnum*multiplier;
        ++index;
        curnum = 0;
      }
      multiplier = 1;
    }
    else{

      if (c=='p'||c=='s'||c=='*'||c=='/'){
        //do operations on array
        narr[index-2] = operate(narr[index-2],narr[index-1],c);
        narr[index-1] = 0;
        --index;
      }
      else if (c=='-'){
        multiplier = -1;
      }
      else{
        //read in number
        readingnum = 1;
        int digit = c - '0';
        curnum = curnum*10 + digit;
      }

    }
  }

  free(narr);
  return 0;
}
