#include<bits/stdc++.h>
using namespace std;
int n;
long long a[100100];
long long res;
int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int minu=0;
	for(int i=1;i<=n;i++){
		if(a[i]<0)
			minu++;
		a[i]=abs(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		if(minu%2==1&&i==1)
			res-=a[i];
		else
			res+=a[i];
	}
	cout<<res<<endl;
	return 0;
}
