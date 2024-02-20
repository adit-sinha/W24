#include <stdio.h>
#include <stdlib.h>

int main(){

  int *stack = malloc(sizeof(int)*4);
  int i, num, numfound;
  int sign = 1;
  int stacksize = 4;

  while (! feof(stdin)){

    char inp = getchar();

    if (feof(stdin)){

      if (numfound == -1){
        stack[0] = sign*num;
      }

      printf("%d\n", stack[0]); 

      free(stack);
    }

    if (inp == ' ' || inp == '\n' || inp == '\t'|| inp == '\r'|| inp == '\v'|| inp == '\f'){

      //checking for spaces
      if (numfound == -1){
        numfound = 0;
        

        if (stacksize == i+1){ //memory issue encountered

          stacksize = stacksize*2; //doubling strategy
          int *newstack = malloc(sizeof(int)*stacksize);
          for (int j = 0; j <= i; ++j){
            newstack[j] = stack[j];

          }

          free(stack);
          stack = newstack;
          //free(newstack);
        }
        stack[i] = num*sign;
        num = 0;

        i += 1;
      }
      sign = 1;
    }
    else{
        //does not check for invalid input
      if (inp == '-'){
        //must be negative number not subtract
        sign = -1;
      }
      else if (inp == 'p'|| inp == 's'|| inp == '*' || inp == '/'){
          if (inp == 'p') {
            stack[i-2] += stack[i-1];
          }
          else if (inp == 's') {
            stack[i-2] -= stack[i-1];
          }
          else if (inp == '*') {
             stack[i-2] *= stack[i-1];
          }
          else if (inp == '/') {
            stack[i-2] /= stack[i-1];
          }

        //nullifying previous elem
        stack[i-1] = 0; 
        

        i -= 1;
      }
      else{
        int digit = inp - '0';
        num = num*10 + digit;
        numfound = -1;
      }
    }
  }
}
