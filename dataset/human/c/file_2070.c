#include<stdio.h>
int N,M,B[105],i,r,l,m;

int ch(int w)
{
	int t=0,i,d=1;
	for(i=0;i<N;i++)
	{
		if(w<B[i])return 0;
		if(t+B[i]>w)
		{
			d++;
			t=0;
		}
		t+=B[i];
	}
	return d<=M;
}

int main()
{
	for(;scanf("%d%d",&M,&N),N;)
	{
		for(i=0;i<N;i++)
			scanf("%d",&B[i]);
		for(l=0,r=1500001;r-l>1;)
		{
			m=(l+r)/2;
			if(ch(m))r=m;//OK
			else l=m;//NG
		}
		printf("%d\n",r);
	}
	return 0;
}
