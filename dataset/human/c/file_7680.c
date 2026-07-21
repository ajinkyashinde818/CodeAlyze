#include <stdio.h>
int main (void){
int a;
int b[10000];
int c=1;
for(a=1; a<=10000;a++ ){
        scanf("%d",&b[a]);
if (b[a]==0)break;
c++;
          }
for(a=1; a<=10000;a++ ){
printf ("Case %d: %d\n",a,b[a]);
if (a==c-1)break;                  }
return 0 ;
}
