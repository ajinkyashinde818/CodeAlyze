#include <cstdio>
#include <cmath> 

using namespace std ;
 
int N ;
inline bool Squ( int K ) {
	if( (int)sqrt( K ) * (int)sqrt( K ) == K ) return true ;
	return false ;
}
int S[1005][1005] ;
int Top[1005] ;
 
int main() {
	
	scanf( "%d" , &N ) ;
	if( not Squ( N * 8 + 1 ) ) return not printf( "No\n" ) ;
	if( (int)sqrt( N * 8 + 1 ) % 2 == 0 ) return not printf( "No\n" ) ;
	printf( "Yes\n" ) ;
	int Nod = (int)sqrt( N * 8 + 1 ) + 1 >> 1 ;
	int Cnt = 0 ;
	for(register int i = 1 ; i < Nod ; i++ )
		for(register int j = i + 1 ; j <= Nod ; j++ ) {
			++Cnt ;
			S[i][++Top[i]] = Cnt ;
			S[j][++Top[j]] = Cnt ;
		}
	printf( "%d\n" , Nod ) ;
	for(register int i = 1 ; i <= Nod ; i++ ) {
		printf( "%d " , Top[i] ) ;
		for(register int j = 1 ; j <= Top[i] ; j++ )
			printf( "%d " , S[i][j] ) ;
		printf( "\n" ) ;
	}
	return 0 ;
	
}
