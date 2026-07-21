#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<map>
#include<vector>
#include<stack>
#include<queue>
#define loop(i,a,b) for(int i=a;i<b;i++)
#define rep(i,a) loop(i,0,a)
#define pi acos(-1)
#define pb push_back
#define int long long
using namespace std;
typedef pair<int,int> p;
typedef long long ll;

signed main(){
	int n;
	cin>>n;
	int a[n],tmp[n];
	rep(i,n){
		cin>>a[i];
		if(i){
			tmp[i]=tmp[i-1]+a[i];
		}else tmp[i]=a[i];
	}
	int ans=1e12;
	rep(i,n-1){
		ans=min(ans,abs(tmp[i]-(tmp[n-1]-tmp[i])));
	}
	cout<<ans<<endl;
	return 0;
}
