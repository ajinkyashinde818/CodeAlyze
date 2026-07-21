#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long > A(N);
    for(auto& a : A){
        cin >> a;
    }

    int num_zero = 0;
    int num_minus = 0;
    int min_abs = abs(A[0]);
    long long int sum = 0;
    for(int ii=0; ii<N; ii++){
        if(A[ii]<0) num_minus++;
        if(A[ii]==0) num_zero++;
        min_abs = min(min_abs, (int)abs(A[ii]));
        sum += abs(A[ii]);
    }

    if(num_zero>0 || num_minus % 2 == 0){
        cout << sum << endl;
    }else{
        cout << sum - min_abs * 2 << endl;
    }
    return 0;
}
