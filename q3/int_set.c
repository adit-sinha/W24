#include <stdio.h>
#include <stdlib.h>


void p(int *x, int xlen) {
    for (int i = 0; i < xlen-1; i++){
                    printf("%d ", x[i]);
               }
               
    if (xlen != 0){
                printf("%d", x[xlen-1]);
                printf("\n");
               }
}

int a(int *x, int xlen, int num){
    //add in ascending
    int xind = xlen;

    if (xlen == 0){
            x[0] = num;
            return 1;
         }

    for (int i = 0; i < xlen; i++){
            if (num < x[i]){
                   xind = i; 
                   break;
                }
            else if (num == x[i]){
                return 0;
                }
    }

    for (int j = xlen; j > xind; j--){
                x[j] = x[j-1];
    }

    x[xind] = num;
    return 1;
    
}

int r(int *x, int xlen, int num){

    int xind, numfound;

    if (xlen == 0){
           return 0;
         }

    for (int i = 0; i < xlen; i++){
            if (num == x[i]){
                xind = i;
                numfound = -1;
                }
    }

    if (numfound == 0) return 0; //num not found

    for (; xind < xlen-1; xind++){
    x[xind] = x[xind+1];
    }
    return 1;
    
}

int main() {
  char inp, targ;
  int num, digit, numfound, digfound, xlen, ylen, xsize, ysize, sign;
  sign = 1;
  xsize = 4;
  ysize = 4;
  inp = getchar();
  int *x = malloc(sizeof(int)*xsize); //initializing dynamic array
  int *y = malloc(sizeof(int)*ysize);
  

  while ((inp != 'q') && (! feof(stdin))){
    
    //doubling strategy
    if (xsize==xlen){
      //based off lecture code
      xsize *= 2;
      int *incsize = malloc(xsize*sizeof(int));

      for (int i = 0; i < xlen; ++i){
        incsize[i] = x[i];
      }

      free(x);
      x = incsize;
      //free(incsize);
      
    }

    if (ylen == ysize){
      //based off lecture code
      ysize *= 2;
      int *incsize2 = malloc(ysize*sizeof(int));

      for (int i = 0; i < ylen; ++i){
        incsize2[i] = y[i];
      }

      free(y);
      y = incsize2;
      //free(incsize2);
      
    }

    if (inp == 'a'){
      while (1){
        inp = getchar();
        if (inp == ' ' || inp == '\n' || inp == '\t'|| inp == '\r'|| inp == '\v'|| inp == '\f'){
            if (digfound == 0){
                continue;
            }
            else{
                numfound = -1;
                break;
            }
          
        }
        else if (inp == 'x'){
          targ = 'x';
        }
        else if (inp == 'y'){
          targ = 'y';
        }
        else if (inp == '-'){
            sign = -1;
        }
        else {
          if (numfound != -1){
              digit = inp - '0';
          	  num = num*10 + digit;
              digfound = -1;

          }
          else {
            printf("Invalid command: received %c\n", inp);
            printf("Your test case is likely invalid input\n");
          }
        }
        
      }
      num *= sign;
      //code for addition here
      if (targ == 'x'){ 
        
         xlen += a(x, xlen, num);
      }
      else if (targ == 'y'){
         ylen += a(y, ylen, num);
        
      }
      sign = 1;
      //targ = '';
      num = 0;
      numfound = 0;
      digit = 0;
      digfound = 0;
      }
      
      
      
    
            
      

    else if (inp == 'r'){

      while (1){
        inp = getchar();
        if (inp == ' ' || inp == '\n' || inp == '\t'|| inp == '\r'|| inp == '\v'|| inp == '\f'){
            if (digfound == 0){
                continue;
            }
            else{
                numfound = -1;
                break;
            }
          
        }
        else if (inp == 'x'){
          targ = 'x';
        }
        else if (inp == 'y'){
          targ = 'y';
        }
        else if (inp == '-'){
            sign = -1;
        }
        else {
          if (numfound != -1){
              digit = inp - '0';
          	  num = num*10 + digit;
              digfound = -1;

          }
          else {
            printf("Invalid command: received %c\n", inp);
            printf("Your test case is likely invalid input\n");
          }
        }
        
        //code for removal here
      }
      num *= sign;
      if (targ == 'x'){ 
         xlen -= r(x, xlen, num);
      }
      else if (targ == 'y'){
         ylen -= r(y, ylen, num);
        
      }
      sign = 1;
      //targ = '';
      num = 0;
      numfound = 0;
      digit = 0;
      digfound = 0;
    }

    else if (inp == 'p'){
        
            scanf(" %c", &inp); //easier to examine
            if (inp == 'x'){
                p(x, xlen);

            }
            else if (inp == 'y'){
                p(y, ylen);
                
            }
            else{
                printf("Invalid target for command p, expected x or y received %c\nYour test case is likely invalid input\n", inp);
                
            }
        
        
      
    }
    else if (inp == 'u'){

        int ulen;
        int *uarr = malloc((xlen+ylen)*sizeof(int));
        

        for (int i = 0; i < xlen; i++) {
            //takes all sorted elements of x first
            uarr[i] = x[i]; 
            ulen += 1;
            }

        for (int j = 0; j < ylen; j++){
          ulen += a(uarr, ulen, y[j]);
        }

        p(uarr,ulen);
        free(uarr); //for every iteration
        
      
    }
    else if (inp == 'i'){
        int ilen, isize;

        if (xlen >= ylen) {
            isize = xlen;
        } //doesnt matter if eq
        else {
            isize = ylen; 
        }
        
        int *iarr = malloc(sizeof(int) * isize);

        for (int j = 0; j < xlen; j++){
          for (int k = 0; k < ylen; k++){
            if (y[k] == x[j]){
              ilen += a(iarr, ilen, x[j]);
            }
          }
        }

        p(iarr, ilen);
        free(iarr); //for every iteration

      
    }
    else if (inp == ' ' || inp == '\n' || inp == '\t'|| inp == '\r'|| inp == '\v'|| inp == '\f') {
        inp = getchar();
        continue;
    }
    else {
        //tests for error
            printf("Invalid command: received %c\n", inp);
            printf("Your test case is likely invalid input\n");
    }
   
    inp = getchar();
  }

  free(x);
  free(y);
  }

