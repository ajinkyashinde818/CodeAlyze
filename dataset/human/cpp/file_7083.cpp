#include<bits/stdc++.h>
using namespace std;
const int maxn=200010;
int n,c=-1,l=0,r=-1,a[maxn]={},b[maxn]={},h[maxn]={};
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),h[n-i+1]=b[i];
	for(int i=1;i<=n;i++)b[i]=h[i];
	for(int i=1;i<=n;i++)if(a[i]==b[i]){c=a[i];break;}
	for(int i=1;i<=n;i++)if(a[i]==c&&b[i]==c){l=i;break;}
	for(int i=n;i>=1;i--)if(a[i]==c&&b[i]==c){r=i;break;}
	for(int i=1;i<=n;i++)if(a[i]!=c&&b[i]!=c&&l<=r)swap(b[l],b[i]),l++;
	if(l<=r)printf("No");
	else{printf("Yes\n");for(int i=1;i<=n;i++)printf("%d ",b[i]);}
	return 0;
}
