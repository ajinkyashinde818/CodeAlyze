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

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL R, G, B, N;
	cin >> R >> G >> B >> N;
	LL r, g, b;
	LL ans = 0;
	for(r=0; r<=3000; r++){
		for(b=0; b<=3000; b++){
			LL v = N - (R*r) - (B*b);
			if(v >= 0 && (v % G) == 0){
				ans++;
			}
		}
	}
	printf("%lld\n", ans);
	return 0;
}
