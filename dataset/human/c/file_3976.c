#include <stdio.h>
int main(void)
{
	int a, b, k, i, c, d=0;
	
	scanf("%d%d%d",&a,&b,&k);
	
	if(a>b) c=b;
	else    c=a;
	for(i=c;i>0;i--){
	    if((a%i==0)&&(b%i==0)) d++;
	    if(k==d) break;
	}
	printf("%d\n",i);
	return 0;
}
