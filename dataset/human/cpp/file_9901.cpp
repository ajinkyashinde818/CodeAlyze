#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <cstdlib> 
#include <string.h>
#include <vector>
#include <cstdio>
#include <iomanip>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <ctime>
#include <algorithm>
#include <cmath>
#define PI 3.1415926535897932384626433832795l
#define IOS ios :: sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define deci(n) cout<<fixed<<setprecision(n);
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define ALPHA 27
#define ll long long int
#define ld long double
#define mmset(arr, n) memset(arr, n, sizeof arr)
#define debug(x) cerr << '#' << ' ' << x << '\n'
#define len(s) s.length()
#define ForA(i,a,b) for(int i = a; i < b; i++)
#define ForA1(i,a,b) for(int i = b - 1; i >= a; i--)
#define ForB1(i,a,b) for(int i = b; i > a; i--)
#define ForB(i,a,b) for(int i = a; i <= b; i++)
#define INT_SIZE 18 
#define maxn 55
#define Maxn 100010

using namespace std;

const ll INF = (ll)(8e18);
const ll MOD = 1000000007;

int freq[ALPHA];

int main()
{
    IOS;       
    int n; cin >> n;
    string s; cin >> s;
    ForB(i,0,n - 1) freq[s[i] - 'a']++;
    ll ans = 1;
    ForB(i,0,ALPHA - 1){
        if(freq[i] > 0){
           ans *= (freq[i] + 1);
           ans %= MOD;
        }
    }
    cout << (ans - 1 + MOD) % MOD << '\n';
    #ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
    #endif
    return 0 ;
}
