#include<iostream>
#include<algorithm>
#include<vector>
 using namespace std;
 typedef long long ll;
 int main()
 {
 	ll n,r;
 	cin>>n>>r;
 	if(n>=10) cout<<r<<endl;
 	else{
 		r=r+100*(10-n);
 		cout<<r<<endl;
	}
 	return 0;
 }
