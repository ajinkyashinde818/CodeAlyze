#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>




int main(void){
int n,r;
scanf("%d %d",&n,&r);
if(n>=10){printf("%d",r);}
else{printf("%d",(r+100*(10-n)));}
}
