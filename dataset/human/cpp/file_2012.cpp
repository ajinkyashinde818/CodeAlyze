#include <bits/stdc++.h>
using namespace std;

typedef long long  ll;

ll MOD = 1000000007;
ll INF = 100000000000;
double PI = 3.1415926535;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}


int main(){
    ll N;cin >> N;
    vector<ll> A(N);
    ll memo = 10000000000;
    ll cnt = 0;
    ll sum = 0;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        if(abs(A[i]) < memo){
            memo = abs(A[i]);
        }
        if(A[i] < 0){
            cnt++;
        }
        sum += abs(A[i]);
    }
    ll ans = 0;
    if(cnt % 2 == 0){
        cout << sum << endl;
    }else{
        cout << sum - 2 * memo << endl;
    }
}
