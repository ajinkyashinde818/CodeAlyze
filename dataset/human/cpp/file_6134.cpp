#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <map>
#include <functional>
#include <array>

using namespace std;

int main(){
    int N;
    int64_t C;
    cin >> N >> C;

    vector<int64_t> x(N), v(N);
    vector<int64_t> x2(N), v2(N);
    for(int i = 0; i < N; ++i){
        cin >> x[i] >> v[i];
        x2[i] = C - x[i];
        v2[i] = v[i];
    }
    v[0] -= x[0];
    int64_t ans = 0;
    ans = max(ans, v[0]);
    //cout << v[0] << endl;
    for(int i = 1; i < N; ++i){
        v[i] += x[i-1];
        v[i] -= x[i];
        v[i] += v[i-1];
        //cout << v[i] << endl;
        ans = max(ans, v[i]);
    }
    v2[N-1] -= x2[N-1];
    ans = max(ans, v2[N-1]);
    /*cout << "po" << endl;
    cout << v2[N-1] << endl;*/
    for(int i = N-2; i >= 0; --i){
        v2[i] += x2[i+1];
        v2[i] -= x2[i];
        v2[i] += v2[i+1];
        //cout << v2[i] << endl;
        ans = max(ans, v2[i]);
    }
    vector<int64_t> vm(N), vm2(N);
    vm[0] = 0;
    vm[0] = max(vm[0], v[0]);
    for(int i = 1; i < N; ++i){
        vm[i] = max(v[i], vm[i-1]);
    }
    vm2[N-1] = 0;
    vm2[N-1] = max(vm2[N-1], v2[N-1]);
    for(int i = N-2; i >= 0; --i){
        vm2[i] = max(v2[i], vm2[i+1]);
    }

    for(int i = 0; i < N-1; ++i){
        int64_t sum = v[i] - x[i] + vm2[i+1];
        ans = max(ans, sum);
    }
    for(int i = 1; i < N; ++i){
        int64_t sum = v2[i] - x2[i] + vm[i-1];
        ans = max(ans, sum);
    }
    cout << ans << endl;
}
