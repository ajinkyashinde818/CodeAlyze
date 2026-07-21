#include <stdio.h>
#define maxn 200010
int n,k,a[maxn];
int judge(int x){
	int i,cnt=0;
	for(i=1;i<=n;i++)
		cnt+=(a[i]-1+x)/x-1;//(a[i]-1+x)/x用来统计原木分割的段数((a[i]-1+x)/x此种写法是常见技巧)，切割次数=段数-1
	if(cnt>k)return 0;//切割次数过多
	else return 1;//切割次数小于等于k
}
int main(){
	int i,l,r,mid;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	l=0,r=1000000000;
	while(l+1<r){
		mid=(l+r)/2;
		if(judge(mid))r=mid;
		else l=mid;
	}
	printf("%d\n",r);
	return 0;
}
