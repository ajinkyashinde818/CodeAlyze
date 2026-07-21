#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

const int NMAX=3000;
int r,g,b,n;
ll ans=0;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	
	cin >> r >> g >> b >> n;
	
	for(int premier=0;premier<=(n/r);premier++){
		for(int second=0;second<=(n/g);second++){
			int reste=n-premier*r-second*g;
			
			if(reste>=0 && reste%b==0) ans++;
		}
	}
	
	cout << ans << '\n';
    return 0;
}
