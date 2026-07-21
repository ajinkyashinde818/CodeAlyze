#include<iostream>
#include<string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	long long N;
	string S;
	cin >> N;
	cin >> S;
	long long i;
	vector<long long> A(30);
	for (i = 0; i < 26; i++) {
		A.at(i) = 0;
	}
	for (i = 0; i < N; i++) {
		switch (S.at(i)) {
		case 'a':
			A[0] += 1;
			break;
		case 'b':
			A[1] += 1;
			break;
		case 'c':
			A[2] += 1;
			break;
		case 'd':
			A[3] += 1;
			break;
		case 'e':
			A[4] += 1;
			break;
		case 'f':
			A[5] += 1;
			break;
		case 'g':
			A[6] += 1;
			break;
		case 'h':
			A[7] += 1;
			break;
		case 'i':
			A[8] += 1;
			break;
		case 'j':
			A[9] += 1;
			break;
		case 'k':
			A[10] += 1;
			break;
		case 'l':
			A[11] += 1;
			break;
		case 'm':
			A[12] += 1;
			break;
		case 'n':
			A[13] += 1;
			break;
		case 'o':
			A[14] += 1;
			break;
		case 'p':
			A[15] += 1;
			break;
		case 'q':
			A[16] += 1;
			break;
		case 'r':
			A[17] += 1;
			break;
		case 's':
			A[18] += 1;
			break;
		case 't':
			A[19] += 1;
			break;
		case 'u':
			A[20] += 1;
			break;
		case 'v':
			A[21] += 1;
			break;
		case 'w':
			A[22] += 1;
			break;
		case 'x':
			A[23] += 1;
			break;
		case 'y':
			A[24] += 1;
			break;
		case 'z':
			A[25] += 1;
			break;
		}
	}
	long long B = 1;
	for (i = 0; i < 26; i++) {
		B = B*(A.at(i) + 1) % 1000000007;
	}
	cout << B - 1;
}
