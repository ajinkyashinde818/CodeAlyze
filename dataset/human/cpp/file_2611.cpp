#include <bits/stdc++.h>
const int INF = 1e9;
const int MOD = 1e9+7;
using LL = long long;
const LL LINF = 1e18;
const double EPS = 1e-10;
using namespace std;

int main(){
    int N;cin >> N;
    vector<LL> vec;
    int cnt  = 0;
    for(int i = 0;i < N;i++){
        int b;cin >> b;
        if(b < 0)cnt++;
        vec.push_back(abs(b));
    }
    if(cnt%2 == 0){
        cout<<accumulate(vec.begin(), vec.end(), 0LL)<<endl;
    }else{
        cout<<accumulate(vec.begin(), vec.end(), 0LL) - 2 * *min_element(vec.begin(),vec.end())<<endl;
    }
}
