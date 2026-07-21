//ABC156A
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <climits>
#include <cfloat>
#include <string>
#include <unordered_map>
using namespace std;

int main(){
	int n, r;
	cin >> n >> r;
	int ans;
	if(n >= 10){
		ans = r;
	}else{
		ans = r + 100*(10-n);
	}
	cout << ans << endl;
	return 0;
}
