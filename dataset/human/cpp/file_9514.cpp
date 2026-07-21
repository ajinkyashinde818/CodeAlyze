#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <numeric>
#include <string>
using namespace std;
const double PI = acos(-1.0);
const string alp = "abcdefghijklmnopqrstuvwxyz";
const string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)

int a,b,c;
int n,m;
double d,e,f;
string s,t,u;
vector<int> v,w,x;
vector<string> y,z;

int main(void) {
    cin >> n >> m;
    REP(i,n-m+1){
        y.push_back("");
    }
    REP(i,n){
        cin >> s;
        REP(j,n-m+1){
            y[j]+=s.substr(j,m);
        }
    }
    t = "";
    REP(i,m){
        cin >> s;
        t += s;
    }
    REP(i,n-m+1){
        if (y[i].find(t)!=-1){
            puts("Yes");
            return 0;
        }
    }
    puts("No");
    return 0;
}
