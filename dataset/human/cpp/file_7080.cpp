//#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long ll;
ll n,m,ans;
ll a[200005],b[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[n-i+1];
    }
    ll l=1;
    for(int i=1;i<=n;i++){
		if(a[i]!=b[i])continue;
		while(!(a[i]==b[i]&&a[i]!=a[l]&&b[i]!=b[l])){
			l++;
			if(l>n){
				cout<<"No";
				//system("pause");
				return 0;
			}
		}
		swap(b[l],b[i]);
	}
	cout<<"Yes\n";
	for(int i=1;i<=n;i++)cout<<b[i]<<" ";
    //system("pause");
    return 0;
}
