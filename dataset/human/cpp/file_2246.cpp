#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;


int main() {
    long long n,p=0,ans = 0;;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i ++){
        cin >> a.at(i);
    }
    
    for(int i = 0;i < n;i ++){
        if(a.at(i) < 0){
            p ++;
        }
    }
    if(p%2 == 0){
        for(int i = 0; i < n;i ++){
            ans += abs(a.at(i));
        }
    }else{
        for(int i = 0;i < n;i ++){
        a.at(i) = abs(a.at(i));
        }
        sort(a.begin(),a.end());
        for(int i = 1;i < n;i ++){
            ans += a.at(i);
        }
        ans -= a.at(0);
    }

    cout << ans << endl;


}
