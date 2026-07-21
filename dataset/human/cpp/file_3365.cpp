#include <iostream>
#include <string>
#include <math.h> 
using namespace std;

int main()
{
	int N, i, judg = 0, judg2 = 0;
	double A[100005], sub = 1000000000.0;
	long long Ans = 0;
	cin >> N;
	for (i = 0; i < N; i++)
		cin >> A[i];

	for (i = 0; i < N; i++) {
		if (A[i] < 0.0)
			judg += 1;
		if (A[i] == 0.0)
			judg2 = 1;
		Ans += fabs(A[i]);
		if (sub > fabs(A[i]))
			sub = fabs(A[i]);
	}

	if (judg % 2 == 1 && judg2 == 0)
		Ans -= sub * 2.0;

	cout << Ans;
	return 0;
}
