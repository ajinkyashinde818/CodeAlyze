#include <iostream>
using namespace std;
typedef long long ll;

int main(void){
    // Your code here!
    int N;
    cin >> N;
    
    ll A[N];
    for(int i = 0; i < N; i++) cin >> A[i];
    
    ll dp[N][2];
    
    dp[0][0] = 0;
    dp[0][1] = -(10<<21);
    
    for(int i = 0; i < N; i++){
        dp[i+1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
        dp[i+1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
    }
    
    cout << dp[N][0] << endl;
    
    
}
