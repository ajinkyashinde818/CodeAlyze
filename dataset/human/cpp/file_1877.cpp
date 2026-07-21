#include <cstdio>
using namespace std;

int main(){
	unsigned q, s;
	for(scanf("%u", &q); q--; ){
		scanf("%x", &s);
		int x = (s & 0x7fffffffu) >> 7;
		int y = (s & 0x7fu) * 78125;
		int d = 7;
		while(d > 1 && y % 10 == 0){
			y /= 10;
			--d;
		}
		
		if(s >> 31) putchar('-');
		printf("%d.%0*d\n", x, d, y);
	}
}
