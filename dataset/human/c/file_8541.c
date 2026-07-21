#include <stdio.h>

int main(void) {
	int n,i;
	long long cnt=0;
	if(scanf("%d",&n)!=1)return 1;
	for(i=0;i<n;i++) {
		char kakko[4];
		int num;
		if(scanf("%*d%s%d",kakko,&num)!=2)return 1;
		if(kakko[0]=='(')cnt+=num; else cnt-=num;
		puts(cnt==0?"Yes":"No");
	}
	return 0;
}
