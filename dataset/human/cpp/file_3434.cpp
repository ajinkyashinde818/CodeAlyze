#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
#include <string>
#include <set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <cmath>
using namespace std;

int64_t a[100010];
int64_t d[100010][2];

int main() {
    int n;
    cin>>n;
    for(int i=0;i<n;++i){
        cin>>a[i];
    }
    d[1][0]=a[0];
    d[1][1]=-a[0];
    for(int i=2;i<n;++i){
        d[i][0]=d[i][1]=-1e18;
        for(int j=0;j<2;++j){
            d[i][0]=max(a[i-1]*(-2*j+1)+d[i-1][j],d[i][0]);
            d[i][1]=max(a[i-1]*(2*j-1)+d[i-1][j],d[i][1]);
        }
    }
    cout<<max(d[n-1][0]+a[n-1],d[n-1][1]-a[n-1])<<endl;
    return 0;
}
