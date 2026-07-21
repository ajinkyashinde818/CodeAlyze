#include<stdio.h>
int main(void)
{
	int N;
	int count1=0;
	int count2=0;
	scanf("%d", &N);
	int ary[N+1];for(int i=1;i<=N;i++){scanf("%d", &ary[i]);}
	int bry[N+1];for(int i=1;i<=N;i++){scanf("%d", &bry[i]);}
	int cry[N+1];for(int i=1;i<N;i++){scanf("%d", &cry[i]);}
	for(int i=1;i<=N;i++){count1 = count1+bry[i];}
	for(int i=1;i<=N;i++){
		if(ary[i+1]-ary[i]==1){count2=count2+cry[ary[i]];}
		else count2= count2+0;
		}
	printf("%d", count1+count2);
	
	return 0;
}
