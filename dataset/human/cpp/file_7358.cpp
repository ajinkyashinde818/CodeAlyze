#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <deque>
using namespace std;
using Graph = vector<vector<int>>;

int main() {
    //input
    int n;cin >>n;
    vector<long long> a(n + 1);
    for(int i = 1; i < n + 1; i++) cin >> a[i];
    vector<long long> s(n + 2,0);
    
    //compute
    s[1] = a[1];
    for(int i = 1; i < n; i++){
        s[i + 1] = s[i] + a[i + 1];
    }

    long long opt = 10000000000;

    for(int i = 1; i < n; i++){
        long long tmp = abs(s[n] - 2 * s[i]) ;
        if(tmp < opt){
            opt = tmp;
        }
    }

    cout << opt << endl;             

}
