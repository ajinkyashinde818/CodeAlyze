#include <stdio.h>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <queue>
#include <cstring>
using namespace std;

int main() {
	int R, G, B, N,ans=0; cin >> R >> G >> B >> N;
	for (int i = 0; i <= N; i += R) {
		for (int j = 0; j <= N - i; j += G) {
			if ((N-i-j)%B==0) ans++;
		}
	}
	cout << ans << endl;
}
