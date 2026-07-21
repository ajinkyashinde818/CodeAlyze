#include <iostream>
#include <cstring>
#include <string>    
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll r, g, b, n;

int main(){
	cin >> r >> g >> b >> n;
    ll ans = 0;
    
    for(ll i = 0; i <= n/r; i++){
    	ll buf = n-r*i;
    	if(buf == 0){ans++;}
    	else{
			for(ll j = 0; j <= buf/g; j++){
				    ll bufbuf = buf-g*j;
					if(bufbuf%b == 0){ans++;}
			}
    	}
    }
    
	cout << ans << endl;
	return 0;
}
