#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using ll = long long;
using itn = int;
using namespace std;
int GCD(int a, int b){
    return b ? GCD(b, a%b) : a;
}
int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    ll cnt=0;
    int rm=n/r,gm=n/g;
    for(int i=0; i<=rm; ++i){
        //G,Bが0個
        if( (i*r) == n){
            cnt++;
            continue;
        }
        for(int j=0; j<=gm; ++j){
            //Bが0個
            if( (i*r+j*g) == n){
                cnt++;
                continue;
            }
            //Bを取る場合
            else if( ((n-(i*r+j*g))%b) == 0 && (n-(i*r+j*g) > 0) ){
                cnt++;
                continue;
            }
        }
    }
    cout << cnt << endl; 
    return 0;
}
