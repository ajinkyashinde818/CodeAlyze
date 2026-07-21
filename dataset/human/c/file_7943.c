#include <stdio.h>
#define maxn 200010
int L[maxn],R[maxn],lc,rc;
char s[maxn];
int main(){
	int n,k,c,i;
	scanf("%d%d%d%s",&n,&k,&c,s+1);
	for(i=1;i<=n;){//正向寻找
		if(s[i]=='o'){
			L[++lc]=i,i+=c;
			if(lc==k)break;
		}
		i++;
	}
	for(i=n;i>=1;){//反向寻找
		if(s[i]=='o'){
			R[++rc]=i,i-=c;
			if(rc==k)break;
		}
		i--;
	}
	for(i=1;i<=k;i++)//重合工作的寻找
		if(L[i]==R[k-i+1])printf("%d\n",L[i]);
	return 0;
}
