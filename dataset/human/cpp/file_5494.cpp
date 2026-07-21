#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<stack>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int n,i,j,k;
	cin>>n>>k;
	if(n>=10) cout<<k;
	else {
		cout<<(10-n)*100+k;
		
	}
}
