#include <stdio.h>

int main( int argc, char *argv[] )
{
	int k,s;
	scanf("%d%d",&k,&s);
	if(s-k<0)k=s;
	int ans=0,extra=0;
	for(int i=0; i<=k; i++){
		if(s-i<0 || s-i > 2*k){}		
		else if(s-i<k)ans+=s-i+1;
		else ans+=2*k+1-(s-i);
		//printf("x=%d\n%d\n",i,ans);
	}
	printf("%d\n",ans);
	return 0;
}
