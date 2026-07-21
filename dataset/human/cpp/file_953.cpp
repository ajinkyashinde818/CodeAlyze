#include <bits/stdc++.h>
using namespace std;

const int MOD = (int)1e9+7;

int main(){
	int R,G,B,N;
	cin >> R >> G >> B >> N;
	
	int ans=0;
	for(int i=0;i<=N;i++){
		if(i*R>N)	break;
		for(int j=0;j<=N;j++){
			if(i*R+j*G>N)	break;
			if(i*R+j*G==N)	ans++;
			else if((N-i*R-j*G)%B==0)	ans++;
		}
	}
	cout << ans << endl;
	
	return 0;
}
