#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;
typedef long long LL;
using Graph = vector<vector<int>>;

static long long INF = (1LL<<62);

void addMapKey(map<long long, int> &m, long long k){
	if(m.count(k) == 0){
		m[k] = 1;
	}
	else{
		m[k]++;
	}
}

long long N;
vector<long long> A;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	long long minus = 0;
	long long min = INF;
	long long ans = 0;
	for(int i=0; i<N; i++){
		long long a;
		cin >> a;
		A.push_back(a);
		ans += abs(a);
		if(a < 0){
			minus++;
		}
		if(min > abs(a)){
			min = abs(a);
		}
	}
	
	if((minus % 2) != 0){
		ans -= 2*min;
	}
	printf("%lld\n", ans);
	return 0;
}
