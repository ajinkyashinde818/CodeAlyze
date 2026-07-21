#include<bits/stdc++.h>
using namespace std;
 
const int N=200010;
int a[N],b[N],n;
 
int main(){
	scanf("%d",&n);
	int x;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n;i++) scanf("%d",&b[i]);
	reverse(b+1,b+1+n);
	int l=0,r=0,t=0,L=0,R=0;
	for(int i=1;i<=n;i++) if(a[i]==b[i]) {
		if(!l) l=i,r=i,t=a[i];
		else r++;
	}
	if(!l){
		printf("Yes\n");
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
		return 0;
	}
	for(int i=1;i<=n;i++) if(a[i]==t || b[i]==t) {L=i-1;break;}
	for(int i=n;i>=1;i--) if(a[i]==t || b[i]==t) {R=i+1;break;}
	if(L+n-R+1<(r-l+1)) printf("No\n");
	else{
		for(int i=1;i<=min(L,r-l+1);i++) swap(b[i],b[l+i-1]);
		for(int i=1;i<=r-l+1-min(r-l+1,L);i++) swap(b[n-i+1],b[r-i+1]);
		printf("Yes\n");
		for(int i=1;i<=n;i++) printf("%d ",b[i]);
	}
}
