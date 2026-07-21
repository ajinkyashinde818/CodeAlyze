#include <iostream>
using namespace std;

typedef long long ll;

int h[7] = {
	5000000,
	2500000,
	1250000,
	 625000,
	 312500,
	 156250,
	  78125
};

int pow10(int x){
	int res = 1;
	for(int i = 0 ; i < x ; i++ ) res *= 10;
	return res;
}

int main(){
	int Q;
	
	cin >> Q;
	for(int i=0 ; i < Q ; i++ ){
		ll n = 0;
		for(int j=0 ; j < 8 ; j++ ){
			char c;
			cin >> c;
			if( 'a' <= c ){
				c = c - 'a' + 10;
			}else{
				c = c - '0';
			}
			n = n * 16ll + c;
		}
		
		if( n & (1ll << 31) ) cout << "-";
		
		ll a = 0;
		for(int j = 7; j < 31 ; j++ ){
			int k = j - 7;
			if( n & (1ll << j) ) a += (1ll << k);
		}
		cout << a << ".";
		
		int b = 0;
		for(int j = 6 ; j >= 0 ; j-- ){
			int k = 6 - j;
			if( n & (1ll << j) ) b += h[k];
		}
		if( b == 0 ){
			cout << 0;
		}else{
			int k = 7;
			for(int j=6, b_ = b ; j >= 0 ; j-- ){
				int d = 6 - j;
				if( b_ % 10 == 0 ){
					k = j;
					b_ /= 10;
				}else{
					break;
				}
			}
			for(int j = 0 ; j < k ; j++ ){
				cout << (b / pow10(6 - j)) % 10;
			}
		}
		cout << endl;
	}
}
