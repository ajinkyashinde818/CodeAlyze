#include<stdio.h>
 int main(void)
 {
     char X,Y;
     int x,y;

     scanf("%c %c",&X,&Y);

     if(X=='A') x=10;
     if(X=='B') x=11;
     if(X=='C') x=12;
     if(X=='D') x=13;
     if(X=='E') x=14;
     if(X=='F') x=15;

     if(Y=='A') y=10;
     if(Y=='B') y=11;
     if(Y=='C') y=12;
     if(Y=='D') y=13;
     if(Y=='E') y=14;
     if(Y=='F') y=15;

     if(x<y)       printf("<\n");
     else if(x>y)  printf(">\n");
     else          printf("=\n");

     return 0;
 }
