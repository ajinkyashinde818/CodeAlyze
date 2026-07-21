#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
string s;
ll n,m,r,c,t;
int main(){
	int n,r;
	cin>>n>>r;
	if(n>=10)cout<<r;
	else cout<<r+100*(10-n);
	return 0;
}
