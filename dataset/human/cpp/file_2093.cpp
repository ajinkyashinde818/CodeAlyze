#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int N,count=0,sum=0;
    bool zero=false;
    cin >> N;
    vector<long long int> A(N),B(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
        B[i] = abs(A[i]);
        sum += B[i];
        if(A[i]<0){
            count++;
        }else if(A[i]==0){
            zero = true;
        }
    }

    sort(B.begin(),B.end());

    if(count%2==0 || zero){
        cout << sum << endl;
    }else{
        cout << sum-B[0]*2 << endl;
    }
}
