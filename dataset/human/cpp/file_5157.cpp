#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <vector>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

signed main(){
    cin.tie(0); 
    ios::sync_with_stdio(false);
    int n,r;
    cin >> n >> r;
    if( n >= 10 ){
        cout << r << "\n";
    }else{
        cout << r + 100 * (10 - n) << "\n";
    }
    return 0;
}
