#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	const int M=1000000007;
	int n;
	cin>>n;
	n<<=1;
	string s;
	cin>>s;
	ll res=1,o=0;
	for(int i=0;i<n;++i){
		if(i<n/2)
			res=res*(i+1)%M;
		int x=(s[i]=='B')^(o&1);
		if(x)
			++o;
		else{
			res=(res*o)%M;
			--o;
		}
	}
	if(o)
		res=0;
	cout<<res<<endl;
	return 0;
}
