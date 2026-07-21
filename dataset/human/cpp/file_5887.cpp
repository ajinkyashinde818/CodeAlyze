#include <iostream>
using namespace std;

typedef long long ll;
int N;
ll C;

int main(){
	cin >> N >> C;
	ll X[N+2] = {0},V[N+1] = {0},Y[N+2] = {0};
	X[N+1] = C;
	for(int i=1;i<=N;i++){
		cin >> X[i] >> V[i];
		Y[i] = C - X[i];
	}
	ll ans = 0;
	ll T[N+1] = {0};
	for(int i=1;i<=N;i++){
		T[i] = T[i-1] + V[i] -(X[i]-X[i-1]);
		ans = max(ans,T[i]);
	}
	ll S[N+2] = {0};
	X[N+1] = C;
	for(int i=1;i<=N;i++){
		S[N+1-i] = S[N+2-i] + V[N+1-i] + (X[N+1-i]-X[N+2-i]);
		ans = max(ans,S[N+1-i]);
	}
	ll G[N+1] = {0};
	ll H[N+2] = {0};
	for(int i=1;i<=N;i++){
		G[i] = max(G[i-1],T[i]-X[i]);
		H[N+1-i] = max(H[N+2-i],S[N+1-i]-Y[N+1-i]);
	}
	/*cout << ans << endl;
	cout << G[0] << endl;
	cout << G[1] << endl;
	cout << G[2] << endl;
	cout << G[3] << endl;*/
	for(int i=1;i<=N;i++){
		ans = max(ans,S[i] + G[i-1]);
		ans = max(ans,T[i] + H[i+1]);
	}
	cout << ans << endl;
}
