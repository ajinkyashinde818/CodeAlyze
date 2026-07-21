#include <cstdlib>
#include <iostream>
#include <string>
#include <time.h>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <vector>
#include <functional>
//#include "bits/stdc++.h"
using namespace std;
//using namespace std::vector;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)

#define huge 1000000007
typedef long long ll;
ll gcd(ll a, ll b);

int main(void) {

	ll N = 0;
	ll A = 0;
	ll B = 0;
	ll C = 0;
	ll D = 0;
	ll M = 0;
	//ll M = 0;
	//ll a[200] = {};
	//ll b[200] = {};
	//ll v[3] = {};
	//ll *a, *b, *x;
	string S,T,U[52];
	ll count = 0;
	ll count2 = 0;
	ll sum = 0;
	ll min = 100000000000000;
	ll max = 0;
	ll smax = 0;
	ll max2 = 0;
	ll smax2 = 0;
	int tmax = 0;
	int tmax2 = 0;
	int flag = 0;
	char temp,head;
	//int is = 0;
	
	
	//char p;


	

	

	//cin >> S;
	
	//b = (ll *)malloc(M * sizeof(ll));
	//vector<pair<int,int>> ch(50);

	
	cin >> N;
	//a = (ll *)malloc(A * sizeof(ll));
	vector<ll> a(N);
	rep(i,0,N){
		cin >> a[i];
		sum += a[i];
	}



		rep(i, 0, N-1) {
			max += a[i];

			if (llabs(sum - 2 * max) < min)
				min = llabs(sum - 2 * max);

			//max = 0;
		}

		

		//cout << max << "," << smax << endl;

	
		



	cout << min << endl;
	//x = (ll *)malloc((N+1) * sizeof(ll));
	//c = (ll *)malloc((N) * sizeof(ll));
	//cin >> D >> G;
	//vector<pair<int,int>> tr(M);
	//vector<pair<int,int>> qes(Q);
	//sort(c.begin(), c.end());
	
	//cout << c[2] - c[1] << endl;

	

	/*A = N / 1000;
	N %= 1000;
	B = N / 100;
	N %= 100;
	C = N / 10;
	N %= 10;
	D = N;*/
	


	return 0;

}

ll gcd(ll a, ll b) {
	ll x = a * b;

	/* 自然数 a > b を確認・入替 */
	if (a<b) {
		ll tmp = a;
		a = b;
		b = tmp;
	}

	/* ユークリッドの互除法 */
	ll r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}


	return x/b;
}
