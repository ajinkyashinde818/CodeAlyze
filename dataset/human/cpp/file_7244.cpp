#include <iostream>
using namespace std;

int main(void){
    int n;
    cin>>n;
    long long a_sum[n+1] = {};
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        a_sum[i+1] = a_sum[i] + a;
    }

    long long ans = abs(a_sum[n]-a_sum[1]*2);
    for(int i=2;i<n;i++){
        long long tmp = abs(a_sum[n]-a_sum[i]*2);
        ans = min(ans,tmp);
    }
    cout<<ans<<endl;

}
