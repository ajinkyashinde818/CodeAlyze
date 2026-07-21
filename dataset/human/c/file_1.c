#include<stdio.h>
int main()
{
int R, G, B, N;
int some=scanf("%d %d %d %d",&R,&G,&B, &N);
int r, g;
int counter=0;

for(r=0;r*R<=N;r++)
for(g=0;g*G<=N-r*R;g++)
if((N-r*R-g*G)%B==0 && (N-r*R-g*G)>=0)
{
counter++;
//printf("%d %d %d\n",r,g,(N-r*R-g*G)/B);
}
printf("%d", counter);
return 0;
}
