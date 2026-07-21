#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;

    vector<int> v;
    for(int i = 0; i <= N; ++i){
        const auto x = N-i*B;
        if(x >= 0) v.emplace_back(x);
        else break;
    }

    sort(begin(v), end(v));

    int ans = 0;
    for(int i = 0, n; i <= N; ++i){
        n = i*R;
        for(int j = 0; j <= N; ++j){
            n += j*G;
            if(binary_search(begin(v), end(v), n)) ++ans;
            n -= j*G;
        }
    }

    cout << ans << endl;
}
