#include <bits/stdc++.h>
using namespace std;

int main() {
    
    int n, cnt=0; cin >> n;
    long long ans=0;
    vector<int> a(n);
    
    for(int i=0; i < n; ++i){
        cin >> a.at(i);
        if(a.at(i) < 0){
            ++cnt;
        }
    }
    if(cnt % 2==1){
        for(int i=0; i < n; ++i){
           a.at(i)=abs(a.at(i));
        }
        sort(a.begin(),a.end());
        for(int i=0; i < n; ++i){
           ans += abs(a.at(i));
        }
        ans = ans-2*a.at(0);
    }else{
        for(int i=0; i < n; ++i){
            ans += abs(a.at(i));
        }
    }
    
    cout << ans << endl;   
}
