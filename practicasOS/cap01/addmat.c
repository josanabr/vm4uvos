#include <stdio.h>
#define N 825
#define ROW 1
#define COL 2 

int main(int argc, char** argv) {
  int a[N][N],
      b[N][N], c[N][N];
  int i,j;
  int flag;

  if (argc == 1) {
   printf("Recorrido por filas");
   flag = ROW;
  } else {
   printf("Recorrido por columnas");
   flag = COL;
  }
  printf(" (int = %lu bytes)\n", sizeof(int));

  for (i = 0; i < N; i++) 
    for (j = 0 ; j < N; j++) {
      if (flag == ROW) { 
        a[i][j] = 314;
        b[i][j] = 186;
      } else {
        a[j][i] = 314;
        b[j][i] = 186;
      }
    }

  for (i = 0; i < N; i++) 
    for (j = 0 ; j < N; j++) {
      if (flag == ROW)  
        c[i][j] = a[i][j] + b[i][j];
      else
        c[j][i] = a[j][i]  + b[j][i];
    }

  return 0;
}
