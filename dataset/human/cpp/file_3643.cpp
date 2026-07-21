#include<cmath>
#include<algorithm>
#include<string>
#include<iostream>
#include <fstream>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include<bitset>
#include<vector>
#include<limits.h>
#include<assert.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define FOR(I, A, B) for (int I = (A); I <= (B); ++I)
#define FORS(I, S) for (int I = 0; S[I]; ++I)
#define RS(X) scanf("%s", (X))
#define SORT_UNIQUE(c) (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
#define GET_POS(c,x) (lower_bound(c.begin(),c.end(),x)-c.begin())
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define pb push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define F first
#define S second
#define MAX 100000 
using namespace std;
typedef long long int lli;
typedef unsigned long long ULL;
typedef long double LD;

int main(){
    lli n;
    cin >> n;
    lli a[100007];
    lli negatives = 0;
    vector<lli> arr;
    lli ans = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] < 0){
            negatives++;
        }
        arr.pb(abs(a[i]));

        ans+= abs(a[i]);
    }
    sort(arr.begin(), arr.end());
    if(negatives%2 != 0){
        ans-=(2*arr[0]);
    }
    cout << ans << endl;
}
