#include <stdio.h>
#include <algorithm>

using namespace std;

int a , b , c , n;
int ans;
void work () {
	int i , j;
	scanf ( "%d%d%d%d" , &a , &b , &c , &n );
	for ( i = 0 ; i <= n ; i++ ) {
		for ( j = 0 ; j <= n ; j++ ) {
			if ( i * a + j * b > n ) break;
			if ( (n-i*a-j*b) % c == 0 ) ans++;
		}
	}
	printf ( "%d\n" , ans );
}
int main () {
	work ();
	return 0;
}
