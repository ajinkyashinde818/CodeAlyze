#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

int add(int a, int b){
    return (a+b)%MOD;
}

int mul(int a, int b){
    return((ll)a*b)%MOD;
}

int main(){
    ios_base::sync_with_stdio(false);
    cout.precision(10);
    cout<<fixed;

    int n;
    cin >> n;
    string s;
    cin >> s;
    ll res = 1;
    for(int i=2; i<=n; i++){
        res = mul(res, i);
    }
    int tren = 0;
    for(int i=0; i<2*n; i++){
        if(s[i] == 'B'){
            if(tren%2 == 0){
                tren++;
            }
            else{
                res = mul(res, tren);
                tren--;
            }
        }
        if(s[i] == 'W'){
            if(tren%2 == 0){
                res = mul(res, tren);
                tren--;
            }
            else tren++;
        }
    }
    if(tren){
        cout << 0;
        return 0;
    }
    cout << res;
    return 0;
}
