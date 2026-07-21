#include <iostream>
using namespace std;
typedef long long ll;
int N;
ll A[100010],dp[100010][2] = {};
const ll inf = -1e18;

int main(){
    cin >> N;
    for(int i=1;i<=N;i++){
        cin >> A[i];
        dp[i][0] = inf;
        dp[i][1] = inf;
    }
    for(int i=2;i<=N;i++){
        if(i==2){
            dp[i][0] = A[i-1]+A[i];
            dp[i][1] = -A[i-1]-A[i];
        }else{
            dp[i][0] = max(dp[i-1][0],dp[i-1][1])+A[i];
            dp[i][1] = max(dp[i-1][0]-2*A[i-1]-A[i],dp[i-1][1]+2*A[i-1]-A[i]);
        }
    }
    cout << max(dp[N][0],dp[N][1]) << endl;
}
