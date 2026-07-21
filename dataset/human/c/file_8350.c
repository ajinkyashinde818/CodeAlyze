#include <stdio.h>
int main()
{
	int i=0;
	char S[256];
	int N=0;
	int K=0;
	char L;
	
	scanf("%d",&N);
	scanf("%s",&S);
	scanf("%d",&K);
	
	L=S[K-1];
	
	for(i=0;i<N;i++)
	{
		if(S[i]==L)
		{
			
		}
		else
		{
			S[i]='*';
		}
	}
	printf("%s\n",S);
	return 0;
}
