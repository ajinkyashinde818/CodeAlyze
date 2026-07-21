#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int main(){
    int n;
    cin >> n;
    int k = 1;
    for(k = 1;  k*(k-1)<=2*n; k++){
        if(k*(k-1)/2 == n)break;
    }
    if(k*(k-1)/2!=n){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    cout << k << endl;
    vector<int>s[1000];
    int cnt = 1;
    rep(i,k){
        for(int j = i+1 ; j < k; j++){
            s[i].push_back(cnt);
            s[j].push_back(cnt++);
        }
    }
    rep(i,k){
        cout << k-1 << " ";
        rep(j,k-2){
            cout << s[i][j] << " ";
        }
        cout << s[i][k-2] << endl;
    }
}
