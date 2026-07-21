#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int N;
    cin >> N;
    vector<ll> B;
    ll sum = 0, minuscnt = 0;
    for(int i = 0; i < N;i++){
        ll A; cin >> A;
        if(A >= 0){
            B.push_back(A);
            sum += A;
        }
        else{
            B.push_back(-A);
            sum -= A;
            minuscnt++;
        }
    }
    if(minuscnt % 2 == 0) cout << sum << endl;
    else{
        sort(B.begin(), B.end());
        sum -= 2 * B[0];
        cout << sum << endl;
    }
}
