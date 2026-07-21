#include<iostream>
#include<cstdio>
#include<list>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<cmath>
#include<set>
using namespace std;
int main()
{
	int n,r;
	cin>>n>>r;
	if(n<10)
		cout<<r+100*(10-n)<<endl;
	else
		cout<<r<<endl;
	return 0;
}
