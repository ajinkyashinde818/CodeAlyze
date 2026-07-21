#include <iostream>
#include <algorithm>
#include <functional>
#include<vector>
#include<math.h>
#include<bitset>
#include<string>
#include<queue>
#include<map>
using namespace std;
long int A[200009];
int main() {
	long long int N;
	cin >> N;
	long long int Y = 0;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		if (i != 0)Y += A[i];
	}

	long long int X = A[0];

	long long int Z = abs(X - Y);
	
	for (int i = 1; i < N-1; i++) {
		X += A[i];
		Y -= A[i];
		if (Z > abs(X - Y))Z = abs(X - Y);
	}

	cout << Z << endl;

	return 0;
}
