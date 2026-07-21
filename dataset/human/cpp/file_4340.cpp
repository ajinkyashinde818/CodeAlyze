#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<unordered_map>
#include<unordered_set>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <ostream& out = cout, class... T> void prints(T&&...){ }
template <ostream& out = cout, class... T> void printd(T&&...){ }
template <ostream& out = cout, class... T> void printb(T&&...){ }
template <ostream& out = cout, class... T> void printArr(T&&...){ }
#endif

int main(){
    int n; cin >> n;
    vector<int> as(n), bs(n);
    int x = 0;
    for(int i = 0; i < n; i++){
        cin >> as[i];
        x ^= as[i];
    }
    for(int i = 0; i < n; i++){
        cin >> bs[i];
    }

    as.push_back(x);
    auto a2 = as, b2 = bs;
    sort(a2.begin(), a2.end());
    sort(b2.begin(), b2.end());
    bool sld = false;
    prints(a2, b2);
    for(int i = 0; i < n; i++){
        if(a2[i + sld] != b2[i]){
            if(sld){
                cout << -1 << '\n';
                return 0;
            }
            sld = true;
            i--;
        }
    }

    unordered_map<int, int> um;
    set<int> s(as.begin(), as.end());
    int cnt = 0;
    for(int i : s){
        um[i] = cnt++;
    }
    for(int& a : as){
        a = um[a];
    }
    for(int& b : bs){
        b = um[b];
    }

    int ans = 0;
    unordered_set<int> rems; // index
    unordered_map<int, vector<int>> mp; // num ->  index
    for(int i = 0; i < n; i++){
        if(as[i] == bs[i]){ continue; }
        rems.insert(i);
        mp[bs[i]].push_back(i);
    }

    queue<int> q; // index
    q.push(n);
    while(rems.size()){
        while(q.size()){
            int sIdx = q.front(); q.pop();
            int sNum = as[sIdx];
            if(mp.count(sNum) == 0){ continue; }
            for(int t : mp[sNum]){
                if(rems.count(t)){
                    rems.erase(t);
                    ans++;
                    q.push(t);
                }
            }
            mp.erase(sNum);
        }
        if(rems.empty()){ break; }
        ans++;
        q.push(*rems.begin());
    }
    cout << ans << '\n';
    return 0;
}
