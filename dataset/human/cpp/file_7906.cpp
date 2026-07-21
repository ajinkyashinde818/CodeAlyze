#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;

ll inf=1ll<<60;

int main()
{
	//freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0);
	ll i,j,k,n,s1=0,s2=0,a[200000],ans;
	cin>>n;
	for (i=0;i<n;i++){
		cin>>a[i];
		s2+=a[i];
	}
	s1=a[0];
	s2-=a[0];
	ans=abs(s1-s2);
	for (i=1;i<n-1;i++){
		s1+=a[i];
		s2-=a[i];
		ans=min(ans,abs(s1-s2));
	}
	cout<<ans;
	return 0;
}
