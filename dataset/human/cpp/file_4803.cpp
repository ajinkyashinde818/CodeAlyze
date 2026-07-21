#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long LL;

LL n,k;

int main(){
	cin >> n >> k;
	if(n >= 10) cout << k << endl;
	else{
		cout << k + 100 * (10 - n) << endl;
	}
	return 0;
}
