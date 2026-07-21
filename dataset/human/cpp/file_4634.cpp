#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	int n,r;
	cin>>n>>r;
	if(n>=10)
	{
		cout<<r<<"\n";
	}
	else
	{
		int ans=r+100*(10-n);
		cout<<ans<<"\n";
	}
}
