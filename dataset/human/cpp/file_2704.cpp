#include <iostream>

using namespace std;
const int MAXN = 1e5+5;
long long arr[MAXN];
long long dp[MAXN][3];
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        for(int j=0;j<=2;j++){
            dp[i][j] = -1e18;
        }
    }
    for(int i=2;i<=n;i++){
        if(i == 2){
            dp[i][0] = arr[i-1]+arr[i];
            dp[i][1] = (long long)-1*(arr[i-1]+arr[i]);
        }else{
            dp[i][0] = max(dp[i][0],max(dp[i-2][0],dp[i-2][1])+arr[i-1]+arr[i]);
            dp[i][0] = max(dp[i][0],max(dp[i-1][0],dp[i-1][1])+arr[i]);
            dp[i][1] = max(dp[i][1],max(dp[i-2][0],dp[i-2][1])+((long long)-1*(arr[i-1]+arr[i])));
            dp[i][1] = max(dp[i][1],dp[i-1][0]+((long long)-1*(arr[i])-((long long)2*arr[i-1])));
            dp[i][1] = max(dp[i][1],dp[i-1][1]+((long long)-1*arr[i])+((long long)2*arr[i-1]));
        }


    }
    cout<<max(dp[n][0],dp[n][1])<<endl;
}
