#include <iostream>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    int n, r; cin >> n >> r;
    int k = 0;
    if(n < 10) k = r + (10 - n) * 100 ;
    else k = r;
    cout << k << endl;
	return 0;
}
