//replace ai by a0=a1^...^an
//a1^a2^....^ai-1^a0^ai+1^....^an=ai!:swap a0 and ai
//2nd operation just replace some aj by ai:swap a0(=ai) and aj
//now xor=ai^aj^ai=aj
//3rd operation just replace some ak by aj
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct kk
{
	int num,id;
}a[100010],b[100010];
int fa[100010],n,i,c[100010];
bool cmp1(kk A,kk B){return A.num<B.num||(A.num==B.num&&A.id<B.id);}
bool cmp2(kk A,kk B){return A.id<B.id;}
int find(int x)
{
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void unit(int x,int y)
{
	int a=find(x),b=find(y);
	if (a!=b) fa[a]=b;
}
int main()
{
	scanf("%d",&n);
	a[0].num=0;b[0].num=0;
	a[0].id=0;b[0].id=0;
	int i;
	for (i=1;i<=n;i++)
	{
		scanf("%d",&a[i].num);
		a[0].num^=a[i].num;
		a[i].id=i;
	}
	for (i=1;i<=n;i++) 
	{
		scanf("%d",&b[i].num);
		b[0].num^=b[i].num;
		b[i].id=i;
	}
	sort(a,a+n+1,cmp1);sort(b,b+n+1,cmp1);
	for (i=0;i<=n;i++)
	{
		if (a[i].num!=b[i].num)
		{
			printf("-1\n");
		    return 0;
		}
	}
	//离散化
	int now=0;
	for (i=0;i<n;i++)
	{
		if (a[i].num!=a[i+1].num)
		{
			a[i].num=now;
			now++;
		}
		else a[i].num=now;
	}
	a[n].num=now; 
	now=0;
	for (i=0;i<n;i++)
	{
		if (b[i].num!=b[i+1].num)
		{
			b[i].num=now;
			now++;
		}
		else b[i].num=now;
	}
	b[n].num=now; 
	for (i=0;i<=now;i++) fa[i]=i;
	sort(a,a+n+1,cmp2);sort(b,b+n+1,cmp2);
	int ans=0;
	for (i=1;i<=n;i++) 
	  if (a[i].num!=b[i].num) 
	  {
	  	unit(a[i].num,b[i].num);
	  	ans++;
	  }
	memset(c,0,sizeof(c));
	for (i=0;i<=now;i++) c[find(i)]++;
	for (i=0;i<=now;i++) 
	{
		if (c[i]>=2) ans++;
	}
	if (c[find(a[0].num)]>=2) ans--;
	printf("%d\n",ans);
}
