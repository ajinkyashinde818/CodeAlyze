#include <bits/stdc++.h>
 
using namespace std;
 
int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(false);
 
	int n;
	long long int t,res=0;
	int cnt = 0;
	long long int Min = 1E18;
 	cin >> n;

 	for(int i=0;i<n;i++)
 	{
 		cin >> t;
 		if(t<0)
 		{
 			cnt++;
 		}
 		Min = min(Min,abs(t));
 		res += abs(t);
 	}

 	if(cnt%2==1)
 	{
 		res -= 2*Min;
 	}

 	cout << res << '\n';
 	
	return 0;
}
