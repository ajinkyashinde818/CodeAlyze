#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

template <typename Tp> inline void getint(Tp &num){
	register int ch, neg = 0;
	while(!isdigit(ch = getchar())) if(ch == '-') neg = 1;
	num = ch & 15;
	while(isdigit(ch = getchar())) num = num * 10 + (ch & 15);
	if(neg) num = -num;
}

int R, G, B, N, ans = 0;

int main(){
	getint(R), getint(G), getint(B), getint(N);
	for(register int r = 0, maxr = N / R; r <= maxr; r++)
		for(register int g = 0, maxg = (N - r * R) / G; g <= maxg; g++)
			if((N - r * R - g * G) % B == 0) ans++;
	return printf("%d\n", ans), 0;
}
