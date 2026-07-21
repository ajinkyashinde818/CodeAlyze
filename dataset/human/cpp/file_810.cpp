#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int arr[MAX] ;
int r , g , b , n ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>r>>g>>b>>n ;
	int ans = 0 ;
	for(int i = 0 ; i <= n ; ++i)
	{
		for(int j = 0 ; j <= n ; ++j)
		{
			if(r*i + g*j > n)
				break ;
			int rem = n - r*i - g*j ;
			if(rem % b == 0)
				ans++ ;
		}
	}
	return cout<<ans<<"\n" , 0 ;
}
