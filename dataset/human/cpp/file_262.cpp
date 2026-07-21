#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>
#include<queue>

using ll = long long;
const int inf = 99999999;

using namespace std;

void print2(ll a , ll b){cout << a << " : " << b << endl;}
void print3(ll a , ll b , ll c){cout << a << " : " << b << " : " << c << endl;}

const ll mod = 1e9 + 7;

int main(){
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	ll ans = 0;
	for(int i = 0; i <= n/r + 1; i++){
		for(int j = 0; j <= n/g + 1; j++){
			int k = n - (i*r + j*g);
			if(k%b == 0 && k >= 0)ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
