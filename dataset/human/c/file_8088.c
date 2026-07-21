#include <stdio.h>

int main(void){
int a;
int b;
int c;
int d;
int menseki1;
int menseki2;

scanf("%d%d%d%d",&a,&b,&c,&d);

menseki1 = a*b;
menseki2 = c*d;

if(menseki1>menseki2){
printf("%d",menseki1);
}else if(menseki1 == menseki2){
printf("%d",menseki1);
}else{
printf("%d",menseki2);
}
}
