//#define DEB1 //input from input.txt
//#define NDEBUG
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <thread>
#include <mutex>
#include <iomanip>
#include <cassert>

#define ZERO(a) memset(a, 0, sizeof(a))
#define MINUS(a) memset(a, 0xff, sizeof(a))
#define INF(a) memset(a, 0x3f, sizeof(a))
#define ALL(t) (t).begin(),(t).end()
#define FILL(a,c) fill(a, a+ sizeof(a)/sizeof(*a),c)
#define FILL2D(A,c) fill(A[0], A[0] +sizeof(A)/sizeof(**A),c)
#define FILL3D(A,c) fill(A[0][0], A[0][0] +sizeof(A)/sizeof(***A),c)
#define REP(i,m) for(int i=0;i<(m);++i)
// closed interval, inverse repeat
#define CIREP(i,start,fin) for(int i=(start);i>=(fin);i--)
#define CREP(i,start,fin) for(int i=(start);i<=(fin);i++)
#define RNG(i,start,fin) for(int i=(start);i<(fin);i++)
#define IN(a, x, b) (a<=x && x<b)
#define PB push_back
#define SZ(x) (int)(x).size()

using namespace std;

using LL = long long;
using PAIR = pair<int, int>;
using PAIRLL = pair<LL,LL>;
using VI = vector<int>;
using VLL = vector<LL>;
using VVLL = vector<VLL>;
using VVI = vector<VI>;
const LL LINF = 1001002003004005006ll;
/* 
template<typename T>inline istream& operator>>(istream&i,vector<T>&v)
{REP(j,SZ(v))i>>v[j];return i;}

template<typename T>string join(const vector<T>&v)
{stringstream s;REP(i,SZ(v))s<<' '<<v[i];return s.str().substr(1);}

template<typename T>inline ostream& operator<<(ostream&o,const vector<T>&v)
{if(SZ(v))o<<join(v);return o;}
*/

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}




/*
constant values
*/

//const int dx[] = {1,0,-1,0};
//const int dy[] = {0,1,0,-1};
//const int MX = 31001;

//const ll INF= 1LL<<60 ;//INF = 1001001001001; //1e9


// Main program
void solve(){
    int N,K;
    cin >> N >> K;
    if(N >= 10){
        cout << K << endl;
        return;
    }
    cout << K + 100 * (10-N) << endl;

    return;
}

// ----------------------------------------------
int main(){

#ifdef DEB1
    cout << "DEBUG MODE"  << endl;
    ifstream in("input.txt"); //for debug
    cin.rdbuf(in.rdbuf()); //for debug
#endif

    int T=1; 

    for (int i = 0; i < T; ++i) {
        solve();
    }

    return 0;
}
