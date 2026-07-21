#include<bits/stdc++.h>
using namespace std;
using Int = long long;

signed main(){
    Int N;
    cin>>N;
    vector<Int> A(N);
    for(Int i = 0; i < N; i++){
        cin >> A.at(i);
    }

    Int sum = 0;
    for(Int i = 0; i < N; i++){
        if(A.at(i) < 0){
            sum++;
        }
    }

    Int tmp = 0;
    for(Int i = 0; i < N; i++){
        tmp += abs(A.at(i));
    }

    Int temp = 0;
    Int ans = INT_MAX;
    for(Int i = 0; i < N; i++){
        temp = abs(A.at(i));
        if(temp < ans){
            ans = temp;
        }
    }

    if(sum % 2 == 0){
        cout << tmp << endl;
    }else{
        cout << tmp - ans*2 << endl;
    }
}
