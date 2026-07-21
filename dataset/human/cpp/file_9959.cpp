#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    
    map<char, int> alph;
    for (int i=0; i<N; i++) {
        if(alph.find(S[i]) != alph.end()){
            alph[S[i]]++;
        }
        else{
            alph.emplace(S[i], 1);
        }
    }
    
    long ans = 1;
    long mod = 1000000007;
    auto begin = alph.begin(), end = alph.end();
    for(auto itr = begin; itr != end; itr++){
        ans *= (long)itr->second + 1;
        ans %= mod;
    }
    ans += mod -1;
    ans %= mod;
    cout << ans << endl;
//
//    vector<pair<int, int>> alph;
//    for(int i=0; i<N; i++){
//        if(mp.find(s[i]) != mp.end()){
//            mp[s[i]]++;
//        }
//        else{
//            mp.emplace(s[i], 1);
//        }
//    }
//    for(int i=0; i<M; i++){
//        if(mp.find(t[i]) != mp.end()){
//            mp[t[i]]--;
//        }
//        else{
//            mp.emplace(t[i], -1);
//        }
//    }
//
//    int ans=0;
//    auto begin = mp.begin(), end = mp.end();
//    for(auto itr = begin; itr != end; itr++){
//        if(itr->second > ans){
//            ans = itr->second;
//        }
//    }
//    cout << ans << endl;
}
