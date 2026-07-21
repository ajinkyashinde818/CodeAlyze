#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <climits>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    long long int n,ans=LLONG_MAX,x=0;
    cin>>n;
    vector<long long int>a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    long long int sum=accumulate(a.begin(),a.end(),0LL);
    for(int i=0;i<n;i++){
        x+=a[i];
        if(i+1<n)ans=min(ans,abs(sum-2*x));
    }
    cout<<ans;
}
