#include <stdio.h>
#include <stdlib.h>

int add(int *set,int n,int len){
  int insertindex = len;

  // INITIALIZE SET
  if (len == 0) {set[0]=n; return 1;}
  // CHECK IF NUMBER EXISTS IN SET / FIND INDEX TO BE INSERTED AT
  for (int i = 0; i < len; ++i){
    if (n == set[i]) return 0;
    if (n < set[i]) {insertindex = i; break;}
  }
  // SHIFT ALL OTHER NUMBERS RIGHT
  for (int i = len; i > insertindex; --i){
    set[i] = set[i-1];
  }
  // INSERT NUMBER
  set[insertindex] = n;
  return 1;
}

int rem(int *set,int n,int len){
  int remindex = -1;

  // FIND INDEX TO BE REMOVED
  for (int i = 0; i < len; ++i){
    if (n == set[i]) remindex = i;
  }
  if (remindex == -1) return 0;
  // SHIFT ALL OTHER NUMBERS LEFT
  for (int i = remindex; i < len-1; ++i){
    set[i] = set[i+1];
  }
  return 1;
}

int printset(int *set, int len){
  if (len == 0) return 0;
  for (int i = 0; i < len-1; ++i){
    printf("%d ",set[i]);
  }
  printf("%d\n",set[len-1]);
  return 0;
}

void unionset(int lenx, int leny, int *xset, int *yset){
        int *u = malloc(sizeof(int) * (lenx+leny));
        int lenu = 0;
        for (int i = 0; i < lenx; ++i) {u[i]=xset[i]; ++lenu;}
        for (int i = 0; i < leny; ++i){
          int n = yset[i];
          if ( add(u,n,lenu) ) ++lenu;
        }

        printset(u,lenu);
        free(u);
}

void intersectset(int lenx, int leny, int *xset, int *yset){
        int sizei;
        if (lenx>leny) {sizei = lenx;} else {sizei = leny;}
        int *i = malloc(sizeof(int) * sizei);
        int leni = 0;
        for (int xi = 0; xi < lenx; ++xi){
          int n = xset[xi];
          for (int yi = 0; yi < leny; ++yi){
            if (yset[yi]==n){
              if ( add(i,n,leni) ) ++leni;
            }
          }
        }

        printset(i,leni);
        free(i);
}
int main(){
  int sizex = 4;
  int *x = malloc(sizex*sizeof(int));
  int lenx = 0;

  int sizey = 4;
  int *y = malloc(sizey*sizeof(int));
  int leny = 0;

  char command;
  char set;
  int num;

  while(!feof(stdin)){
    scanf(" %c",&command);

    if (command == 'a'){
      scanf(" %c %d",&set,&num);
      if (set == 'x'){
        if ( add(x,num,lenx) ) ++lenx;
      }
      if (set == 'y'){
        if ( add(y,num,leny) ) ++leny;
      }

    } else if (command == 'r'){
      scanf(" %c %d",&set,&num);
      if (set == 'x'){
        if ( rem(x,num,lenx) ) --lenx;
      }
      if (set == 'y'){
        if ( rem(y,num,leny) ) --leny;
      }

    } else if (command == 'p'){
      scanf(" %c",&set);
      if (set == 'x') printset(x,lenx);
      if (set == 'y') printset(y,leny);

    } else if (command == 'u'){
      unionset(lenx, leny, x, y);

    } else if (command == 'i'){
      intersectset(lenx, leny, x, y);

    } else if (command == 'q'){
      free(x);
      free(y);
      return 0;

    } else {printf("INVALID COMMAND"); free(x); free(y); return 0;}



    if (lenx==sizex){
      sizex = sizex*2;
      int *narr = malloc(sizex*sizeof(int));
      for (int i = 0; i < lenx; ++i){
        narr[i] = x[i];
      }
      free(x);
      x = narr;
    }

    if (leny==sizey){
      sizey = sizey*2;
      int *narr = malloc(sizey*sizeof(int));
      for (int i = 0; i < leny; ++i){
        narr[i] = y[i];
      }
      free(y);
      y = narr;
    }
  }

  free(x);
  free(y);
  return 0;
}
