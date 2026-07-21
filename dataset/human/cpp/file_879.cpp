#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int R, G, B, n, ans, ball;

int main(){
	cin >> R >> G >> B >> n;
	for(int r=0; r<n/R+1; r++){
		for(int g=0; g<n/G+1; g++){
			ball = n-r*R-g*G;
			if(ball<0){
				continue;
			}
			if(ball%B==0){
				ans++;
			}
		}
	}
	cout << ans << endl;
}
