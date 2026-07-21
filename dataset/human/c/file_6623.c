#include<stdio.h>
#define MAX 200000

int max(int,int);
int min(int,int);

int main(){
int R[MAX],n,i;

scanf("%d", &n);
 for ( i = 0; i < n; i++ ){
   scanf("%d", &R[i]);
 }

 int maxv=-2000000000;
 int minv=R[0];

 for ( i = 1; i < n; i++ ){
   maxv=max(maxv,R[i]-minv);
   minv=min(minv,R[i]);
 }
 printf("%d\n",maxv);

 return 0;
}


int max(int x, int y) {
  if ( x > y ) {
    return x;
  } else {
    return y;
  }
}

int min(int x, int y) {
  if ( x < y ) {
    return x;
  } else {
    return y;
  }
}
