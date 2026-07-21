#include<cstdio>
#include<algorithm>
int N,a[100010],b[100010],nums[100010],cnt,fa[100010],deg[100010];
bool fe[100010];
int find(int i){return fa[i]==i?i:fa[i]=find(fa[i]);}
int main(){
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",a+i),a[0]^=a[i];
	for(int i=1;i<=N;i++)scanf("%d",b+i),b[0]^=b[i];
	for(int i=0;i<=N;i++)nums[cnt++]=a[i];
	std::sort(nums,nums+cnt);
	cnt=std::unique(nums,nums+cnt)-nums;
	for(int i=0;i<cnt;i++)fa[i]=i;
	for(int i=0;i<=N;i++){
		a[i]=std::lower_bound(nums,nums+cnt,a[i])-nums;
		int*t=std::lower_bound(nums,nums+cnt,b[i]);
		if(t<nums+cnt&&*t==b[i])b[i]=t-nums;
		else return puts("-1"),0;
		if(find(a[i])!=find(b[i]))
			fe[fa[find(a[i])]=find(b[i])]=1;
		else if(!i)fe[find(a[i])]=1;
		deg[a[i]]++;deg[b[i]]--;
	}
	for(int i=0;i<cnt;i++)
		if(deg[i])return puts("-1"),0;
	int ans=-1;
	for(int i=1;i<=N;i++)if(a[i]!=b[i])ans++;
	for(int i=0;i<cnt;i++)if(fa[i]==i&&fe[i])ans++;
	printf("%d\n",ans);
}
