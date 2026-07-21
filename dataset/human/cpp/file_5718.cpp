#include <bits/stdc++.h>
using namespace std;
int N; 
long long L; 
string S[100010]; 
vector<int> E[200010]; 
long long depth[200010]; 
long long G(long long l){
	long long prod = 1LL; 
	long long tmp = l; 
	while(!(tmp & 1)){
		prod <<= 1; tmp >>= 1; 
	}
	return prod; 
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> L; 
	for(int i = 0; i < N; i++) cin >> S[i]; 
	int v0 = 1; int v1 = 100001; 
	for(int i = 0; i < N; i++){
		int now = 0; 
		for(int j = 0; j < S[i].size(); j++){
			int num = S[i].at(j) - '0'; 
			bool exist = false; 
			for(int k = 0; k < E[now].size(); k++){
				if(num == 0 && E[now].at(k) <= 100000){
					now = E[now].at(k); exist = true; break; 
				}else if(num == 1 && E[now].at(k) > 100000){
					now = E[now].at(k); exist = true; break; 
				}
			}
			if(exist) continue;
			if(num == 0){
				E[now].push_back(v0); 
				depth[v0] = depth[now] + 1; 
				now = v0++; 
			}else if(num == 1){
				E[now].push_back(v1); 
				depth[v1] = depth[now] + 1; 
				now = v1++; 
			}
		}
	}
	long long grundy = 0LL; 
	for(int i = 0; i <= 200005; i++){
		if(E[i].size() == 1){
			grundy ^= G(L - depth[i]); 
		}
	}
	cout << (grundy ? "Alice" : "Bob") << "\n";
}
