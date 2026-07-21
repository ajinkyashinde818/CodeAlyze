#include<bits/stdc++.h>


using namespace std;

using ll   = long long;
using ii   = pair   < int , int >;
using i3   = pair   < int , ii  >;
using li   = pair   < ll  , int >;
using lii  = pair   < ll  , ii  >;
using pll  = pair   < ll  , ll  >;
using vi   = vector < int       >;
using vl   = vector < ll        >;
using vii  = vector < ii        >;
using vli  = vector < li        >;
using vpll = vector < pll       >;
using vi3  = vector < i3        >;
using vlii = vector < lii       >;


const int N = 2e5 + 5;
const ll INF = 1e17 + 7;
const double eps = 1e-9 , PI = acos(-1);



int n;
int a[N] , b[N];


void solve(int testCase){

    scanf("%d" , &n);

    for(int i = 0 ; i < n ; i ++) {
            scanf("%d" , &a[i]);
    }

    for(int i = 0 ; i < n ; i ++) {
            scanf("%d" , &b[i]);
    }

    for(int i = 0 ; i < n / 2 ; i ++) {
            swap(b[i] , b[n - i - 1]);
    }

    int l = -1 , r = -1;

    for(int i = 0 ; i < n ; i ++) {
            if(a[i] == b[i]) {
                    if(l == -1) l = i;
                    r = i;
            }
    }

    for(int i = 0 ; i < n && l <= r && l != -1 ; i ++) {
            if(i >= l && i <= r) continue;

            if(b[i] != b[l] && a[i] != b[l]) {
                    swap(b[i] , b[l]);
                    l ++;
            }
    }

    if(l <= r && l != -1) {
            printf("No\n");
    }
    else {
            printf("Yes\n");
            for(int i = 0 ; i < n ; i ++) {
                    printf("%d%c" , b[i] , i == n-1 ? '\n' : ' ');
            }
    }

}

main(){

    int t = 1;
    // scanf("%d" , &t);

    for(int testCase = 1 ; testCase <= t ; testCase ++){
            solve(testCase);
    }

    return 0;
}
