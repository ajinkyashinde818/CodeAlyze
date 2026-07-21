#include<bits/stdc++.h>
using namespace std ;

main(){
	int Q ;
	string s ;
	cin >> Q ;
	while(Q--){
		cin >> s ;
		int b[32] = {} ;
		for( int i=0 ; i<8 ; i++ ){
			int c = s[i] - '0' ;
			if( c >= 10 ) c -= 39 ;
			
			for( int j=3 ; j>=0 ; j-- ){
				int q=1 ;
				for( int k=0 ; k<j ; k++ ) q*=2 ;
				if( c&q ) b[4*i+3-j] = 1 ;
			}
		}
		if( b[0] ) cout << '-' ;
		
		int sum = 0 ;
		for( int i=1 ; i<=24 ; i++ ){
			sum += b[i] * pow(2,24-i) ;
		}
		
		double sum2 = 0 ;
		for( int i=1 ; i<=7 ; i++ ) sum2 += b[24+i] * pow(0.5,i) ;
		
		int k = 10000000 ;
		int sum3 = sum2 * k ;
		
		k /= 10 ;
		int p[7] = {} ;
		for( int i=0 ; i<7 ; i++ ){
			p[i] = sum3 / k ;
			sum3 -= p[i]*k ;
			k /= 10 ;
		}
		
		cout << sum << '.' ;
		cout << p[0] ;
		for( int i=1 ; i<7 ; i++ ){
			bool t = false ;
			if( p[i] ) t = true ;
			else {
				for( int j=i+1 ; j<7 ; j++ ){
					if( p[j] ) t = true ;
				}
			}
			if( t ) cout << p[i] ;
		}
		cout << endl ;
	}
}
