#include<stdio.h>
#include<vector>
#include<math.h>
#include<string>

typedef long long ll;
typedef unsigned short int unsi;
typedef unsigned int uni;
typedef unsigned long int unli;

using namespace std;

unsi gojoho(unsi A, unsi B) {
	unsi R = 1;
	if (A > B) {
		while (R != 0) {
			R = A % B;
			A = B;
			B = R;
		}
		return A;
	}
	else {
		while (R != 0) {
			R = B % A;
			B = A;
			A = R;
		}
		return B;
	}
}

uni gojoho(uni A, uni B) {
	uni R = 1;
	if (A > B) {
		while (R != 0) {
			R = A % B;
			A = B;
			B = R;
		}
		return A;
	}
	else {
		while (R != 0) {
			R = B % A;
			B = A;
			A = R;
		}
		return B;
	}
}

unli gojoho(unli A, unli B) {
	unli R = 1;
	if (A > B) {
		while (R != 0) {
			R = A % B;
			A = B;
			B = R;
		}
		return A;
	}
	else {
		while (R != 0) {
			R = B % A;
			B = A;
			A = R;
		}
		return B;
	}
}

int gojoho(int A, int B) {
	int R = 1;
	if (A > B) {
		while (R != 0) {
			R = A % B;
			A = B;
			B = R;
		}
		return A;
	}
	else {
		while (R != 0) {
			R = B % A;
			B = A;
			A = R;
		}
		return B;
	}
}



int main() {
	int R, G, B, N;
	int r_max;
	//int gcdRB;
	int	ans = 0;
	bool b = false;
	scanf("%d", &R);
	scanf("%d", &G);
	scanf("%d", &B);
	scanf("%d", &N);
	r_max = N / R;
	//gcdRB = gojoho(R, B);
	for (int i = 0; i <= r_max; i++) {
		int t = N - i * R;
		int b_max = t / B;
		for (int j = 0; j <= b_max; j++) {
			int s = t - j * B;
			if (s%G == 0) {
				ans = ans + 1;
			}
		}

	}
	printf("%d", ans);
	return(0);
}
