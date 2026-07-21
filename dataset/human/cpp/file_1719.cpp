#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    char c = getchar(); int f = 1, x = 0;
    while( c < '0' || c>'9' ) { if(c == '-') f = -1;  c = getchar(); }
    while( c >= '0'&&c<='9' ) { x = x * 10 + c - '0'; c = getchar(); }
    return f * x;
}

int n, k; 

vector <int> s[110000]; 

int main()
{
	n = read(); 
	
	int temp = 1, k = 2; 
	
	while( temp < n ) 
		temp += k, k ++;
	
	if( temp != n ) {
		printf( "No\n" ); return 0; 
	}
	
	printf( "Yes\n%d\n", k ); 
	
	int x = 1, y = 2;
	for( int i = 1; i <= n; i ++ )
	{
		s[x].push_back( i ); 
		s[y].push_back( i ); 
		
		y ++; if( y > k ) x ++, y = x + 1;
	}
	
	vector <int> :: iterator it; 
	for( int i = 1; i <= k; i ++ )
	{
		printf( "%d ", s[i].size() ); 
		for( it = s[i].begin(); it != s[i].end(); it ++ )
			printf( "%d ", *it ); printf( "\n" ); 
	}
	
	return 0; 
}
