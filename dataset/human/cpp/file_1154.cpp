#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main()
{
	int R, G, B, N,M1,M2,M3,m1,m2,m3;
	cin >> R >> G >> B >> N;
	int r, g, b;
	int count = 0;
	int a[3] = { R, G, B};    // 配列を用意する。
	sort(a, a+3);
	M1 = a[2];
	M2 = a[1];
	M3 = a[0];
	
	int flag = -1, N1 = 0;;
	int fcount = 0;
	for (m1 =0; m1<=N/M1; m1++) {
		N1 = N - M1 * m1;
		for (m2 =0; m2 <=N1/M2; m2++)
			if ((N1 - m2 * M2) % M3 == 0)
				fcount++;
	}

	
	cout << fcount;

	
}
