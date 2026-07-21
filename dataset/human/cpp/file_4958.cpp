#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
int n,r;
int main(){
	cin>>n>>r;
	if(n>=10){
		cout<<r<<endl;
	}
	else{
		cout<<r+(10-n)*100<<endl;
	}
	return 0;
}
