#include <bits/stdc++.h>
#include <queue>
using namespace std;
int main(){
	long long int ans = 0; 
	int R, G, B, N; cin >> R >> G >> B >> N; 
	for(int r = 0; r <= 3010; r++){
		for(int g = 0; g <= 3010; g++){
			if(N - r * R - g * G >= 0 && (N - r * R - g * G) % B == 0){
				ans ++; 
			}
		}
	}
	cout << ans << endl; 
}
