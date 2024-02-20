#include <stdlib.h>
#include <stdio.h>
int main() {
   int inp, xlen;
   int *x =  malloc(sizeof(int)*24);
   for (int i = 0; i < 6; i++){
   scanf("num: %d", &inp);
   xlen += 1;
   for (int j = 0; j < xlen; j++){
   if (inp > x[j]){
   x[j+1] = inp;
}
   else {
   for (int k = xlen; k > j; k--){
   x[k] = x[k-1];

}
x[j] = inp;
}

}
} 
  free(x);


}
