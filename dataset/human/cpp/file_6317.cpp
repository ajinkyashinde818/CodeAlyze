#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std ;

const long long mod = 1e9 + 7ll ;

const int MAX = 2e5 + 5 ;

int n ;

int add(int x , int y)
{
	if(x >= mod)
		x -= mod ;
	if(y >= mod)
		y -= mod ;
	int z = x+y ;
	if(z >= mod)
		z -= mod ;
	return z ;
}

int arr[MAX] ;
string s ;

int main()
{
	//ios_base::sync_with_stdio(0) ;
	//cin.tie(0) ;
	cin>>n ;
	cin>>s ;
	for(int i = 0 ; i < n*2 ; ++i)
	{
		if(s[i] == 'W')
			arr[i] = 0 ;
		else
			arr[i] = 1 ;
	}
	long long ans = 1ll ;
	long long moves = 0 ;
	if(arr[0] == 0)
		return cout<<0<<"\n" , 0 ;
	for(int i = 0 ; i < n*2 ; ++i)
	{
		if((arr[i] + moves) % 2 != 0)
			moves++ ;
		else
		{
			ans = (ans * moves) % mod ;
			ans %= mod ;
			moves-- ;
		}
		if(moves > n || moves < 0)
			return cout<<0<<"\n" , 0 ;
	}
	if(moves != 0)
		return cout<<0<<"\n" , 0 ;
	long long fact = 1ll ;
	for(int i = 2 ; i <= n ; ++i)
	{
		fact = (fact * i) % mod ;
		fact %= mod ;
	}
	ans = (ans * fact) % mod ;
	ans %= mod ;
	return cout<<ans<<"\n" , 0;
}
