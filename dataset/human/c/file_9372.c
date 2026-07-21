#include<stdio.h>
int main(void)
{
 int N,D,X,i,Y;
Y=0;
 scanf("%d%d%d",&N,&D,&X);
 for(i=1;i<=N;i++){
 int Ai,Bi;
 scanf("%d",&Ai);
 for(Bi=0;Bi*Ai+1<=D;Bi++){
 }
 Y=Y+Bi; 
 }
printf("%d",Y+X);

 return 0;
}
