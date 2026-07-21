#include <bits/stdc++.h>

using namespace std ;

const int MAX = 1e5 + 10 ;

int n , m ;
int arr[MAX] ;
string s ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>m ;
	if(n >= 10)
		return cout<<m<<"\n" , 0 ;
	else
		return cout<<m + 100 * (10-n) <<"\n" , 0 ;
}
