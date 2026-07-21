#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef pair<int,int> P;
typedef long long ll;

int main(){
	int R,G,B,N;

	cin >> R >> G >> B >> N;

	ll ans = 0;

	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++){
			if(N-i*R-j*G < 0) continue;
			if ((N-i*R-j*G) % B == 0){
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}
