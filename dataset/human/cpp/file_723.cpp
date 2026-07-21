#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int a, b, c, d, n, judg = 0, sub = 0, Ans = 0, i, j, k;
	int A[3];	
		cin >> A[0] >> A[1] >> A[2] >> n;
		for (i = 0; i < 2; i++) {
			for (j = i + 1; j < 3; j++) {
				if (A[i] < A[j]) {
					sub = A[i];
					A[i] = A[j];
					A[j] = sub;
				}
			}
		}
		for (i = 0; i <= 3000; i++) {
			if (A[0]*i > n)
				break;
			for (j = 0; j <= 3000; j++) {
				if (A[0] * i + A[1] * j > n)
					break;
				if ((n - (A[0] * i + A[1] * j)) % A[2] == 0) {
					Ans += 1;
				}
			}
		}
		cout << Ans << endl;
}
