#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> A;

void solve(){
    long sum = 0;
    int abs_min = INT_MAX;
    int m_count = 0;
    for(auto i = 0; i < N; ++i){
        sum += abs(A[i]);
        int absx = abs(A[i]);
        if(absx < abs_min) abs_min = absx;
        if(A[i] < 0) m_count++;
    }
    if(m_count % 2 == 1) sum -= abs_min*2;

    cout << sum;
}

int main(){
    cin >> N;
    A.resize(N);
    for(auto &x : A){
        cin >> x;
    }

    solve();
}
