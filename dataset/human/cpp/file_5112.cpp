#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<deque>
using namespace std;
typedef long long ll;
int main()
{
	int n,r;
	cin>>n>>r;
	if(n>10)
		cout<<r<<endl;
	else
		cout<<r+100*(10-n)<<endl;
	return 0;
}
