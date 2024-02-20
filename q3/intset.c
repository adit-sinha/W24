#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char inp, targ;
  int num, digit, numfound, xlen, ylen;
  inp = getchar();
  int *x = malloc(sizeof(int)*4); //initializing dynamic array
  int *y = malloc(sizeof(int)*4);
  while ((inp != 'q') && (! feof(stdin))){
    if (inp == 'p'){
        while (1){
            inp = getchar();
            if ((inp == ' ')||(inp == '\n')){
                continue;
            }
            else if (inp == 'x'){ 
		for (int i = 0; i < xlen; i++){
                    
                    printf("%d ",x[i]);
               }
	       if (xlen != 0){
		printf("\n");
		}
               break;

            }
            else if (inp == 'y'){
                for (int i = 0; i < ylen; i++){
                    printf("%d ",x[i]);
               }
               if (ylen != 0){
			printf("\n");
		}
               break;
                
            }
            else{
                printf("Invalid target for command p, expected x or y received %c\nYour test case is likely invalid input\n", inp);
                break;
            }
        } 
    }   
   
    inp = getchar();
  }
}
