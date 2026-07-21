#include <bits/stdc++.h>

using namespace std;

using i64 = int64_t;
const i64 MOD = 1e9 + 7;
const i64 INF = i64(1e18) + 7;


signed main(){
    string s;cin >> s;
    string zyunnkan;
    string not_junkan_syousu;
    string not_junkan_seisuu;
    bool f = false;
    bool f2 = false;

    for(auto a : s){
        if(a == '('){
            f2 = true;
            continue;
        }
        if(a == '.'){
            f = true;
            continue;
        }
        if(f2){
            if(a == ')'){
                continue;
            }
            zyunnkan.push_back(a);
        }else if(f){
            not_junkan_syousu.push_back(a);
        }else{
            not_junkan_seisuu.push_back(a);
        }
    }
    if(zyunnkan.size() == 0){
        i64 ans = stoi(not_junkan_seisuu);
        ans *= pow(10, not_junkan_syousu.size());
        ans += stoi(not_junkan_syousu);
        i64 bunnbo = pow(10, not_junkan_syousu.size());
        i64 gcd = __gcd(ans, bunnbo);
        cout<<ans/gcd<<"/"<<bunnbo/gcd<<endl;
    }else{
        i64 ans = stoi(not_junkan_seisuu);
        if(not_junkan_syousu.size())ans *= pow(10, not_junkan_syousu.size());
        if(not_junkan_syousu.size())ans += stoi(not_junkan_syousu);
        ans *= pow(10, zyunnkan.size());
        ans += stoi(zyunnkan);

        i64 bunnbo = pow(10, zyunnkan.size()) - 1;
        i64 bunsi  = ans * pow(10, zyunnkan.size()) + stoi(zyunnkan) - ans;
        bunnbo *= pow(10, not_junkan_syousu.size() + zyunnkan.size());
      //  cout<<bunnbo<<endl;

        i64 gcd = __gcd(bunnbo, bunsi);
        cout<<bunsi/gcd<<"/"<<bunnbo/gcd<<endl;
    }
}
