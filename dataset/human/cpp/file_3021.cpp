#include <iostream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <numeric>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<long long> a(n),b(n);

    int cnt=0;
    long long sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<0){
            cnt++;
            b[i]=-a[i];
        }
        else b[i]=a[i];
    }
    for(int i=0;i<n;i++){
        sum+=b[i];
    }
    sort(b.begin(),b.end());
    if(cnt%2==0)cout<<sum<<endl;
    else cout<<sum-b[0]*2<<endl;
}
