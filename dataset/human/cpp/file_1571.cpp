#include<cstdio>
#include<cmath>
int n;
int main(){
	scanf("%d",&n);
	if((int)std::sqrt(8*n+1)*(int)std::sqrt(8*n+1)!=8*n+1) return puts("No"),0;
	puts("Yes");
	int x=(std::sqrt(8*n+1)-1)/2;
	printf("%d\n",x+1);
	for(int i=1;i<=x+1;++i){
		printf("%d",x);
		int now=i-1;
		for(int j=1;j<i;++j) printf(" %d",now), now+=x-j;
		for(int j=i;j<=x;++j) printf(" %d",++now);
		puts("");
	}
	return 0;
}
