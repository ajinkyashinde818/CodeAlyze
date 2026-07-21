#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<deque>
using namespace std;
//long long int x[2001];
long long int MOD = 1000000007;
int a[200000], b[200000], c[200000];
int C[200001], D[200001];
int beg[200000];
int ct[200000];
pair<int, int> num[200001];
int main() {


	//F
	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {

		cin >> a[i];
		//beg[i] = -1;

	}
	for (i = 0; i < n; i++) {
		cin >> b[i];
	}

	int j = 0, k = 0;
	int counter, counterb;
	i = 0;
	int cc = 0;
	while (i <= n) {

		i++;
		counter = 0;
		counterb = 0;
		while (j < n) {
			if (a[j] == i) {
				j++;
				counter++;
			}
			else {
				//num[i].first = counter;
				//num[i].second = i;
				break;
			}
		}
		//beg[i] = j % n;

		//cout << i << endl;
		while (k < n) {
			//cout << i << endl;

			if (b[k] == i) {
				k++;
				counterb++;
				if (counter + counterb > n) {
					cout << "No" << endl;
					return 0;
				}
			}
			else {
				//cout << i << ' ' << counterb << ' ' << endl;
				break;
			}
		}
		//ct[i] = counterb;
		//num[i - 1].first = counterb + counter;
		//num[i - 1].second = i;



	}
	cout << "Yes" << endl;
	//sort(num, num + n, greater<pair<int,int>>());
	//for (i = 0; i < n; i++)cout << num[i].first << endl;

	int dd;
	cc = 0; dd = 0;
	i = 0;
	for (i = 0; i < n; i++) {
		if (a[i] == cc) {
			C[cc]++;
		}
		else {
			while (cc < a[i]) {
				cc++;
				C[cc] = C[cc - 1];
			}
			C[cc]++;;
		}

	}
	while (cc <= n) {
		cc++;
		C[cc] = C[cc - 1];
	}

	for (i = 0; i < n; i++) {
		if (b[i] == dd) {
			D[dd]++;
		}
		else {
			while (dd < b[i]) {
				dd++;
				D[dd] = D[dd - 1];
			}
			D[dd]++;
		}

	}

	while (dd <= n) {
		dd++;
		D[dd] = D[dd - 1];
	}

	int cdmax = 0;
	for (i = 1; i <= n; i++) {
		if (cdmax < C[i] - D[i - 1])cdmax = C[i] - D[i - 1];
	}
	for (i = 0; i < n; i++) {
		c[(i + cdmax) % n] = b[i];
	}
	for (i = 0; i < n; i++) {
		cout << c[i];
		if (i < n - 1)cout << ' ';
	}
	cout << endl;
	return 0;

	/*for (i = 0; i < n; i++) {

		cc = beg[num[i].second];
		for (j = 0; j < ct[num[i].second]; j++) {
			while (1) {
				if (c[cc] == 0 && a[cc] != num[i].second) {
					c[cc] = num[i].second;
					break;
				}
				else {
					cc++;
					cc = cc % n;
				}
			}
		}

	}


	for (i = 0; i < n; i++) {
		cout << c[i] << ' ';
	}

	return 0;
	*/

	//D
	/*long long int s;
	
	cin >> s;

	int i, j;
	x[0] = 0; x[1] = 0; x[2] = 0; x[3] = 1; x[4] = 1; x[5] = 1;
	for (i = 6; i < 2001; i++) {
		for (j = 3; j < i; j++) {
			x[i] = (x[i] + x[i- j]) % MOD;
		}
		x[i] = (x[i] + 1) % MOD;
	}
	cout << x[s] << endl;
	return 0;
	*/


	//C
	/*long long int n;
	long long int MOD = 1000000007;
	cin >> n;
	int i;
	long long int a, b, c;
	a = 1; b = 2; c = 1;
	for (i = 0; i < n; i++) {
		a = a * 10; b = b * 9; c = c * 8;
		a = a % MOD; b = b % MOD; c = c % MOD;
	}
	a = (a - b + MOD) % MOD;
	a = (a + c) % MOD;
	cout << a << endl;
	return 0;*/

	//B
	/*long long int a, b, c, d;
	cin >> a >> b >> c >> d;

	long long int x[4];
	x[0] = a * c;
	x[1] = a * d;
	x[2] = b * c;
	x[3] = b * d;
	sort(x, x + 4);
	
	
	cout << x[3] << endl;

	return 0;*/
	

	//A
	/*int x;
	cin >> x;
	if (x == 1) {
		cout << 0;
	}
	else {
		cout << 1;
	}
	cout << endl;
	return 0;
	*/

}
