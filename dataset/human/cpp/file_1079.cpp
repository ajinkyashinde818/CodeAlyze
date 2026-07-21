#include <bits/stdc++.h>
using namespace std;

int main(){
	int R,G,B,N;
	cin >> R >> G >> B >> N;
	int ans=0;
	for(int i=0;i*R<=N;i++){
		int n=N-i*R;
		for(int j=0;j*G<=n;j++)if((n-j*G)%B==0)ans++;
	}
	cout << ans << endl;
	return 0;
}
