#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define pb(a) push_back(a)
#define EPS (1e-7)
#define INF (1e9)
#define PI (acos(-1))

typedef long long unsigned int ll;
typedef pair<ll, ll> P;

int main(){
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	int c=0;
	REP(i,n+1){
		if(r*i<=n){
			REP(j,n+1){
				if(r*i+g*j<=n){
					if((n-r*i-g*j)%b==0){
						c++;
					}
				}
			}
		}
	}
	cout << c <<endl;
}
