#include<bits/stdc++.h>
using namespace std;
 
int main(){
 ios_base::sync_with_stdio(0); cin.tie(0);
  int r,g,b,n; cin >> r >> g >> b >> n; int ans=0;
  for(int i=0;i<=n;i++){
  	if(i*r <= n){
  		for(int j=0;j<=n;j++){
  			if((n - (i*r + j*g))%b == 0 && (n - (i*r + j*g)) >= 0) ans++;
  		}
  	}
  }
  cout << ans << "\n";
  return 0;
}
