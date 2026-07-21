#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int n; cin >> n;
    vector<int> as(n);
    long long sum=0;
    for(int i=0; i<n; ++i){
        cin >> as[i];
        sum+=as[i];
    }
    long long x=as[0];
    long long y=sum-as[0];
    long long ans=abs(x-y);
    for(int i=1; i<n-1; ++i){
        x+=as[i];
        y-=as[i];
        ans=min(ans, abs(x-y));
    }
    cout << ans << endl;
    return 0;
}
