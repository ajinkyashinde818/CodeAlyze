#include <bits/stdc++.h>
#include <stdio.h>
#include <math.h>
using namespace std;
using vi = vector<int>;
using vll = vector<long long int>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvll = vector<vector<long long int>>;
using ll = long long int;

int main(){
    ll N; cin >> N;
    vll A(N); ll c = 0;
    cin >> A[0];
    if(A[0]<0){c++;}
    ll min = abs(A[0]);
    for(int i=1; i<N; i++){
        cin >> A[i];
        if(A[i] < 0){c++;}
        if(abs(A[i])<min){min = abs(A[i]);}
    }
    ll sum = 0;
    for(auto x: A){
        sum += abs(x);
    }
    if(c%2 == 0){cout << sum;}
    else{sum -= 2*min; cout << sum;}
}
