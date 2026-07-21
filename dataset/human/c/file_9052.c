#include<stdio.h>
int main()
{
	int n,k,h[100000],i,cnt;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&h[i]);
	}
	cnt=0;
	for(i=0;i<n;i++){
		if(k<=h[i]){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	return 0;
}
