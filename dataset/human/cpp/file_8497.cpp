#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
#include <cmath>
#include <iomanip>
#include <cstdio>
#include <climits>

using namespace std;

int main(){
    int n, m; cin >> n >> m;
    vector<string> as(n), bs(m);
    for(int i=0; i<n; ++i) cin >> as[i];
    for(int i=0; i<m; ++i) cin >> bs[i];
    bool ans=false;
    for(int ay=0; ay<n-m+1; ++ay){
        for(int ax=0; ax<n-m+1; ++ax){
            bool found=true;
            for(int by=0; by<m; ++by){
                for(int bx=0; bx<m; ++bx){
                    if(as[ay+by][ax+bx]!=bs[by][bx]){
                        found=false;
                        break;
                    }
                }
            }
            if(found){
                ans=true;
                goto end;
            }
        }
    }
end:
    cout << (ans ? "Yes" : "No") << endl;
    return 0;
}
