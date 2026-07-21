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
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> v(N);
    long ans=0;
    for(int i=0; i<N; ++i){
        cin >> v[i];
        ans += abs(v[i]);
    }
    sort(v.begin(), v.end());
    int p=0;
    while(p<N){
        if(v[p]>=0) break;
        ++p;
    }
    if(p%2==1){
        if(p<N) cout << ans+2*max(v[p-1], -v[p]) << endl;
        else cout << ans+2*v[p-1] << endl;
    }
    else cout << ans << endl;
	return 0;
}
