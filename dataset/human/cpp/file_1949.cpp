#include<iostream>
#include<queue>
using namespace std;
int p[32000];
int main() {
	
	//D
	int n;
	cin >> n;
	long long int a[100000];
	int i;
	int minuscount = 0;
	long long int suma = 0;
	long long int mina = 1000000001;
	for (i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] >= 0) {
			suma = suma + a[i];
			if (a[i] < mina)mina = a[i];
		}
		else {
			minuscount++;
			if (-a[i] < mina)mina = -a[i];
			suma = suma - a[i];
		}
	}
	if (minuscount % 2 == 1)suma = suma - 2 * mina;
	cout << suma << endl;
	return 0;

	//C
	/*int n;
	cin >> n;
	int a[100000];
	int i,j;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	//int p[32000];
	int flag = 0;
	int pp = 0;
	for (i = 2; i < 32000; i++) {
		for (j = 0; j * j <= i; j++) {
			if (i % j == 0) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			p[pp] = i;
			pp++;
		}
	}
	for (i = 0; i < pp; i++) {
		for (j = 0; j < n; j++) {
			if (a[i] % p[pp] == 0) {

			}
		}
	}*/

	//B
	/*int n;
	cin >> n;
	int i;
	int cost = 0, v[20], c[20];
	for (i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (i = 0; i < n; i++) {
		if (v[i] - c[i] > 0) {
			cost = cost + v[i] - c[i];
		}
	}
	cout << cost << endl;
	return 0;
	*/
	//A
	/*
	int a, b, t;
	cin >> a >> b >> t;
	int bb = 0;
	int aa = 0;
	while (aa + a <= t) {
		bb = bb + b;
		aa = aa + a;
	}
	cout << bb << endl;
	return 0;
	*/
}
