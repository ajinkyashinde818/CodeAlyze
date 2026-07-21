#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main() {
    long long n,a;
    vector<long long> v,vf,vb;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        v.push_back(a);
        if(i==0)vf.push_back(a);
        else vf.push_back(vf[i-1]+a);
    }
    vf.pop_back();
    reverse(begin(v),end(v));
    for(unsigned i=0;i<v.size();i++){
        if(i==0)vb.push_back(v[i]);
        else vb.push_back(vb[i-1]+v[i]);
    }
    vb.pop_back();
    reverse(begin(vb),end(vb));
    long long temp=0,ans = 100000000000;
    for(unsigned i=0;i<vf.size();i++){
        temp = abs(vf[i]-vb[i]);
        if(ans > temp)ans = temp;
    }
    cout << ans << endl;
    return 0;
}
