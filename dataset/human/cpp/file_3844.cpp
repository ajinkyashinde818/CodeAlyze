#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
const int mod = 1e9 + 7;
inline int mul( int x , int y ){ return 1LL * x * y % mod ;}
int power_mod( int x , int y ){int ret = 1;while( y ){if( y & 1 ) ret = mul( ret , x );y >>= 1;x = mul( x , x );}return ret;}
inline int read(){int x=0,f=1;char ch=getchar();while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}return x*f;}
using namespace std;
const int maxn = 1e3 + 50;
const double pi = acos( -1 );

int stx , sty , edx , edy , n , r[maxn];
pair < int , int > p[maxn];
vector < pair < int , double > > G[maxn];

void Link( int u , int v , double c ){
	G[u].push_back( make_pair( v , c ) );
	G[v].push_back( make_pair( u , c ) );
}

long long sqr( int x ){
	return 1LL * x * x;
}

double cal( int x , int y ){
	if( sqr( r[y] + r[x] ) >= sqr( p[x].first - p[y].first ) + sqr( p[x].second - p[y].second ) )
		return 0;
	else
		return hypot( p[x].first - p[y].first , p[x].second - p[y].second ) - r[x] - r[y];
}

double cal( int x , int y , int id ){
	if( sqr( x - p[id].first ) + sqr( y - p[id].second ) <= sqr( r[id] ) )
		return 0;
	else
		return hypot( x - p[id].first , y - p[id].second ) - r[id];
}

struct Node{
	int x ;
	double v ;

	friend bool operator < ( const Node & a , const Node & b ){
		return a.v > b.v;
	}

	Node( int x , double v ) : x(x) , v(v){}
};

double dp[maxn];
__gnu_pbds::priority_queue < Node > pq;
__gnu_pbds::priority_queue < Node > :: point_iterator pf[maxn];

int main(int argc,char *argv[]){
	stx = read() , sty = read() , edx = read() , edy = read() , n = read();
	for(int i = 1 ; i <= n ; ++ i){
		p[i].first = read() , p[i].second = read() , r[i] = read();
	}
	for(int i = 1 ; i <= n ; ++ i)
		for(int j = 1 ; j < n ; ++ j){
			double dis = cal( i , j );
			Link( i , j , dis );
		}
	for(int i = 1 ; i <= n ; ++ i){
		double dis = cal( stx , sty , i );
		Link( 0 , i , dis );
		dis = cal( edx , edy , i );
		Link( n + 1 , i , dis );
	}
	double dis = hypot( stx - edx , sty - edy );
	Link( 0 , n + 1 , dis );
	for(int i = 1 ; i <= n + 1 ; ++ i)
		dp[i] = 1e233;
	pf[0] = pq.push( Node( 0 , 0 ) );
	while(!pq.empty()){
		Node s = pq.top() ; pq.pop();
		int x = s.x ;
		double fq = s.v;
		for(auto go : G[x]){
			int v = go.first ;
			double cost = go.second;
			if( cost + fq < dp[v] ){
				if( dp[v] > 1e200 ){
					dp[v] = cost + fq;
					pf[v] = pq.push( Node( v , dp[v] ) );
				}
				else{
					dp[v] = cost + fq;
					pq.modify( pf[v] , Node( v , dp[v] ) );
				}
			}
		}
	}
	printf( "%.12lf\n" , dp[n + 1] );
	return 0;
}
