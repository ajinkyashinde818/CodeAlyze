#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <ctime>
#include <numeric>
#include <cstdlib>

using namespace std;

typedef long long ll;
#define FOR(i,a,b)   for(ll i = (a); i < (b); i++ )
#define REP(i, n)    FOR(i,0,n)
typedef pair< ll, ll >   cp2;
typedef pair< ll, cp2 >   cp3;
#define fi first
#define se second
#define sec  se.fi
#define thr  se.se
const ll mod = 1000000007;
//              123456789

 
///////////////////////////////////////////////
//
//
///////////////////////////////////////////////

////////////////////////////////////////////////
////////////////////////////////////////////////

int R, G, B;
int N;
int dp[6123][3];

int main(){
	
	cin>>R>>G>>B>>N;
	
	fill( dp[0], dp[6000], 0 );
		
	int s = 0;
	while( s <= N ){
		dp[s][0]++;
		s += R;
	}
	
	REP( i, N+1 ){
		s = 0;
		if( dp[i][0] == 0 ) continue;
		while( s <= N ){
			dp[i+s][1] += dp[i][0];
			s += G;
		}
	}
	
	REP( i, N+1 ){
		s = 0;
		if( dp[i][1] == 0 ) continue;
		while( s <= N ){
			dp[i+s][2] += dp[i][1];
			s += B;
		}
	}
	
	
	cout<<dp[N][2]<<endl;
	
	return 0;
	
}
