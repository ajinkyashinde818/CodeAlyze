#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <iomanip>
#include <utility>
using namespace std;
#define ll long long


int main() {
	int R, G, B, N; cin >> R >> B >> G >> N;
	long ans=0;
	for(int i=0; R*i<=N; ++i){
	    for(int j=0; R*i+G*j<=N; ++j){
	        if((N-R*i-G*j)%B==0) ++ans;
	    }
	}
	cout << ans << endl;
	return 0;
}
