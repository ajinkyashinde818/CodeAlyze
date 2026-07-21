#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#define ll long long

int main(void){
int N;
int a[100000];
int flag=0;
scanf("%d",&N);
int i=0;
for(i=0;i<N;i++){
scanf("%d",&a[i]);
}
int sw=1;
for(i=0;i<N;i++){
 sw=a[sw-1];
 if(sw==2) {printf("%d\n",i+1); return 0;}
}
printf("-1\n");
return 0;
}
