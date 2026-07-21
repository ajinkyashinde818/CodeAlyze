#include <bits/stdc++.h>
using namespace std;


int main(void){
    
    int N;
    cin >> N;
    long long A[N];
    
    for(int i = 0; i < N ;i++)cin >> A[i];
    
    map<int,long long> sum;
    map<int,long long> Isum;
    sum[0] = A[0];
    //cout << sum[0] <<endl;
    for(int i = 1; i < N ;i++){
        sum[i] += A[i] + sum[i-1];
        //cout << sum[i] <<endl;
    }
    //cout << sum[N-1]-sum[0] <<"-"<< sum[0]<<endl;
    long long ans = abs((sum[N-1]-sum[0])-sum[0]);
    long long calc;
    
    for(int i = 1; i < N-1 ;i++){
        //cout << sum[N-1]-sum[i] <<"-"<< sum[i]<<endl;
        calc = abs((sum[N-1]-sum[i])-sum[i]);
        ans = min(calc,ans);
    }
    cout << ans <<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
}
