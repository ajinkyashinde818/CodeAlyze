#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    long long sum[n+1];
    sum[0] = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        sum[i+1] = sum[i] + a[i];
    }
    long long ans = LLONG_MAX;
    for(int i=1;i<n;i++){
        long long tmp = abs(sum[n]-2*sum[i]);
        if(ans>tmp){
            ans = tmp;
        }
    }
    cout << ans << endl;
    return 0;
}
