#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
using P = pair<ll, ll>;
using P3 = pair<int, P>;
using PP = pair<P, P>;
constexpr int INF = 1 << 30;
constexpr ll MOD = ll(1e9) + 7;
constexpr int di[] = {0, 1, 0, -1};
constexpr int dj[] = {1, 0, -1, 0};

ll gcd(ll p, ll q){
    if(q==0) return p;
    else return gcd(q, p%q);
}

int main() {
    string s;
    cin >> s;
    ll a = 0, ad = 0;
    for(auto c : s){
        if(c == '(') break;
        else if(c == '.') ad = 1;
        else{
            a = a*10 + c-'0';
            ad *= 10;
        }
    }
    if(s.find('(') != s.npos){
        ll b = 0, bd = 1;
        bool f = false;
        for(int i=s.find('.')+1;s[i]!=')';i++){
            if(s[i] == '(') f = true;
            else{
                if(f) b = b*10+s[i]-'0';
                bd *= 10;
            }
        }
        int l = s.find(')')-s.find('(')-1;
        b *= pow(10,l);
        bd *= (ll(pow(10,l))-1);
        ll gb = gcd(b, bd);
        b /= gb;
        bd /= gb;
        a = a*bd + b*ad;
        ad *= bd;
    }
    ll ga = gcd(a, ad);
    a /= ga;
    ad /= ga;
    cout << a << "/" << ad << endl;
    return 0;
}
