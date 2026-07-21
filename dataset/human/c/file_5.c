#include <stdio.h>

int main(){
    int a,b,c,d=0;
  	int R=0,G=0,B=0,N=0,P=0;
    scanf("%d %d %d %d",&R,&G,&B,&N);
  	a=N/R;
  	b=N/G;
  	c=N/B;
  	for(int i=0;i<=a;i++)
    {
      for(int j=0;j<=b;j++)
      {
        if(R*i+G*j==N)d++;
        else{
        	P=N-(R*i+G*j);
        	if(P>=B&&P%B==0)d++;
        }
      }
    }
  	printf("%d",d);
}
