#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef pair<int,int> P;

const int MOD=1000000007;

int main()
{
	int n,r;
	cin>>n>>r;
	if(n>=10)cout<<r<<"\n";
	else cout<<r+100*(10-n)<<"\n";
	
	return 0;
}
