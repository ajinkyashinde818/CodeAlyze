/*
本宝的程序外人别想看！！

name: [夏宝宝]
run time：[] ms
compilation time: [] ms
output memory: [] MiB
where: []
state: []
*/
#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	
	cout.sync_with_stdio(false);
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n, m;
	
	cin>>n>>m;
	
	if(n<10)
	{
		cout<<m+100*(10-n)<<endl;
	}
	else
	{
		cout<<m<<endl;
	}
	
	return 0;
}
