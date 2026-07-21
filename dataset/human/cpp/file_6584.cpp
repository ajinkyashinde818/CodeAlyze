#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)


int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    n *= 2;
    ll res = 1;
    for(int i=1;i<=n/2;i++){
        res *=i;
        res %= mod;
    }
    if(s[0]=='W'||s[n-1]=='W'){
        cout << 0 << endl;
        return 0;
    }

    ll p = 1;
    for(int i=1;i<n;i++){
        if(s[i]=='B'){
            if(p%2==1){
                res *= p;
                res %= mod;
                p--;
            }else{
                p++;
            }
        }else if(s[i]=='W'){
            if(p%2==1){
                p++;
            }else{
               res *= p;
                res %= mod;
                p--; 
            }
        }
    }
    if(p!=0){
        cout << 0 << endl;
    }else{
        cout << res << endl;
    }
    return 0;
}
