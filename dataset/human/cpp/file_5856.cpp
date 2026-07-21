#include <iostream>
#include <cstdio>
#include <cassert>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
#include <numeric>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <queue>
#include <numeric>
#include <iomanip>
#define ll long long
using namespace std;
const int MAXN = 100005;
long long n,c;
pair<long long,long long> pt[MAXN];
long long front[MAXN],back[MAXN];
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> n >> c;
    for(int i = 1; i <= n; i++){
        cin >> pt[i].first >> pt[i].second;
    }
    sort(pt + 1, pt + n +1);
    long long sum = 0;
    long long ans = 0;
    priority_queue<pair<long long,long long > > fpq,bpq;
    for(int i = 1; i <= n; i++){
        front[i] = -pt[i].first + sum + pt[i].second;
        sum += pt[i].second;
        ans = max(ans,front[i]);
        fpq.push(make_pair(front[i],i));
    }
    
    sum = 0;
    for(int i = n; i >= 1; i--){
        back[i] = -(c - pt[i].first) + sum + pt[i].second;
        sum += pt[i].second;
        ans = max(ans,back[i]);
        bpq.push(make_pair(back[i],i));
    }
    for(int i = 1; i <= n - 1; i++){
        while(bpq.size() && bpq.top().second <= i) bpq.pop();
        long long temp = front[i] - pt[i].first + bpq.top().first;
        ans = max(ans,front[i] - pt[i].first + bpq.top().first);
    }
    for(int i = n; i > 1; i--){
        while(fpq.size() && fpq.top().second >= i) fpq.pop();
        ans = max(ans,back[i] - (c - pt[i].first) + fpq.top().first);
    }
    cout << ans;
    
    
//    cout << ans;
    
    return 0;
}


/*
 15 10000000000
 400000000 1000000000
 800000000 1000000000
 1900000000 1000000000
 2400000000 1000000000
 2900000000 1000000000
 3300000000 1000000000
 3700000000 1000000000
 3800000000 1000000000
 4000000000 1000000000
 4100000000 1000000000
 5200000000 1000000000
 6600000000 1000000000
 8000000000 1000000000
 9300000000 1000000000
 9700000000 1000000000
 */
