#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



int N;
#define number(x, y) ((x)*N + (y) + 1)
#define r(q) ((q - 1) / N)
#define c(q) ((q - 1) % N)
int cl = 0;
FILE *f;
void d_d(int x, int y) {
int i, j;
for (; x < N - 1 && y < N - 1; x++, y++)
for (i = x + 1, j = y + 1; i < N && j < N; i++, j++) {
fprintf(f, "-%d -%d 0\n", number(x, y), number(i, j));
printf("-%d -%d 0\n", number(x, y), number(i, j));
cl++;
}
}



void d_u(int x, int y) {
int i, j;
for (; x > 0 && y < N - 1; x--, y++)
for (i = x - 1, j = y + 1; i >= 0 && j < N; i--, j++) {
fprintf(f, "-%d -%d 0\n", number(x, y), number(i, j));
printf("-%d -%d 0\n", number(x, y), number(i, j));
cl++;
}
}



int main() {
int i, j, c, q, k,n;
printf("Enter the value of N :-");
scanf("%d",&n);
N=n;
char board[N][N],t[10],d;
f = fopen("cl.txt", "w");



for (k = 0; k < N; k++) {



for (i = 0; i < N; i++){
    fprintf(f, "%d ", number(k, i));
    printf("%d ", number(k, i));
}
fprintf(f, "0\n");
printf("0\n");
cl++;



for (i = 0; i < N - 1; i++)
for (j = i + 1; j < N; j++) {
fprintf(f, "-%d -%d 0\n", number(k, i), number(k, j));
printf("The elements in the same row and column :- \n");
printf("-%d -%d 0\n", number(k, i), number(k, j));
cl++;
fprintf(f, "-%d -%d 0\n", number(i, k), number(j, k));
printf("-%d -%d 0\n", number(i, k), number(j, k));
cl++;
}



}




  printf("The elements in the diagonal down from 0 to N :- \n");
  for (i = 0; i < N - 1; i++)
    d_d(0, i);
printf("The elements in the diagonal down from N to 0 :- \n");
  for (i = 1; i < N - 1; i++)
    d_d(i, 0);
printf("The elements in the diagonal UP from 1 to N :- \n");
  for (i = 1; i < N; i++)
    d_u(i, 0);
printf("The elements in the diagonal UP from N to 1 :- \n");
  for (i = 1; i < N - 1; i++)
    d_u(N - 1, i);




printf("p cnf %d %d\n", N * N, cl+N);
fclose(f);
f = fopen("coding1.txt", "w");
fprintf(f, "p cnf %d %d\n", N * N, cl+N);
fclose(f);
system("cat cl.txt >> coding1.txt");
system("./minisat coding1.txt results.txt");
f = fopen("results.txt", "r");
int val=0;
for (i = 0; i < N; i++)
    for (j = 0; j < N; j++)
      board[i][j] = '*';
      val++;
   int count =1;
  while ((c = fscanf(f, "%d", &q)) != EOF) {
      if(count==1){
          d=fscanf(f, "%s", t);
          printf("%s\n",t);
          count=0;
          continue;
      }
    if (c == 0) {
      fgetc(f);
      continue;
    }
      if(q > 0){
      board[r(q)][c(q)] = 'Q';
          }
    }
  
    for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++)
      printf("%c  ", board[i][j]);
    printf("\n");
     }





return 0;



}
