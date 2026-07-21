#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<map>
#include<set>
#include<queue>
//int[1e7] ll[5*1e6]
typedef long long ll;
typedef unsigned long long ull; 
using std::string;using std::cin;using std::cout;

int n,r;

int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("in.in", "r", stdin);
    cin >> r >> n;
    if(r >= 10) cout << n << "\n";
    else {
        cout << n + 100 * (10 - r) << "\n";
    }
    

    return 0;
}
