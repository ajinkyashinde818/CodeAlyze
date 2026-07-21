#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int R, G, B, N;
  int rbox, gbox, bbox;
  int ans = 0;
  cin >> R >> G >> B >> N;
  for(int i = 0; i < N+1; i++){
  	rbox = i * R;
  	if(rbox > N){
  		break;
  	}else{
  		for(int j = 0; j < N+1 - rbox; j++){
  			gbox = j * G;
  			bbox = N - (rbox + gbox);
  			if(bbox < 0){
  				break;
  			}else{
  				if(bbox % B == 0){
  					ans += 1;
  				}
  			}
  		}
    }
  }

  cout << ans << endl;
}
