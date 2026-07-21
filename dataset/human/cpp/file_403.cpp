#include <bits/stdc++.h>
using namespace std;
int main(){

	int R, G, B, N;
	cin >> R >> G >> B >> N;

	int ans = 0;

	for(int i=0; i<=N; i++){
      for(int j=0; j<=N-i; j++){
		int k = N - R*i - G*j;
		if(k < 0) break;
        if(k % B == 0) {
          ans++;
        }
      }
	}
	cout << ans << endl;

	return 0;
}
