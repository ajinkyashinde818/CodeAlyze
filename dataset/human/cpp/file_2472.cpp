#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
 
int main(){
    int N;
    cin >> N;
    ll A[100000], ans = 0, min = LLONG_MAX;
    for(int i=0;i<N;i++){
        cin >> A[i];
        ans += abs(A[i]);
        if(abs(A[i]) < min)
            min = abs(A[i]);
    }
    
    
    vector<ll> vec;
    for(int i=0;i<N;i++){
        if(A[i] < 0)
            vec.push_back(A[i]);
    }
    int size = vec.size();
    // 降順ソート
    sort(A, A + N, greater<int>());
    
    
    if(size % 2 == 0)
        cout << ans << endl;
    else
        cout << ans - 2*min << endl;
    
}
