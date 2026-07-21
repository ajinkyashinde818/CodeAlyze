#include<stdio.h>
char S[105],T[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
int N,K[105],i,j,p;
int main()
{
	for(;scanf("%d",&N),N;puts(""))
	{
		for(i=0;i<N;K[i++])
			scanf("%d",&K[i]);
		scanf("\n%s",S);
		for(i=j=0;S[i];i++,j=(j+1)%N)
		{
			if(S[i]<'a')p=S[i]-'A'+26;
			else p=S[i]-'a';
			putchar(T[(p-K[j]+52)%52]);
		}
	}
	return 0;
}
