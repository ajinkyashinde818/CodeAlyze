#include<stdio.h>

int reached[100010];

int main(){
	int N,ans=0;
	scanf("%d",&N);
	int a[N+1];
	for(int i=1;i<=N;i++)scanf("%d",&a[i]);
	
	int b=1;
	while(1){
		if(reached[b]==1){
			ans=-1;
			break;
		}
		if(b==2)break;
		reached[b]=1;
		b=a[b];
		ans++;
	}
	printf("%d\n",ans);
	return 0;
}
