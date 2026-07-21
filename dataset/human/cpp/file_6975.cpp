#include<iostream>
using namespace std;
const int N=1002020;
int n,a[N],b[N];
void print(){
	puts("Yes");
	for(int i=1;i<=n;i++)
		cout<<b[i]<<" ";cout<<endl;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--)cin>>b[i];
	int l=n,r=0;
	for(int i=1;i<=n;i++)
		if(a[i]==b[i])l=min(l,i),r=max(r,i);
	if(!r){print();return 0;}
	int nw=l;
	for(int i=1;i<l && nw<=r;i++)
		if(b[nw]!=a[i] && b[nw]!=b[i])
			swap(b[nw],b[i]),++nw;
	for(int i=r+1;i<=n && nw<=r;i++)
		if(b[nw]!=a[i] && b[nw]!=b[i])
			swap(b[nw],b[i]),++nw;
	int fl=0;
	for(int i=1;i<=n;i++)
		if(b[i]==a[i]){fl=1;break;}
	if(fl)puts("No"); else print();
	return 0;
}
