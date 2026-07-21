//new.cpp
/*
Author : Hocky Yudhiono
Sab 27 Okt 2018 07:50:23  WIB
Current Local Time : 19:50:23

getchar_unlocked > getchar > cin without sync > scanf > cin with sync
bool operator<(const MyStruct& rhs) const
*/

#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

#if 0
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target("sse3","sse2","sse")
#pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
#pragma GCC target("f16c")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#pragma GCC diagnostic error "-std=c++14"
#pragma GCC target ("string"...)
#pragma GCC push_options
#pragma GCC pop_options
#pragma GCC reset_options
#pragma GCC optimize ("O3")
#endif

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
//If the time limit is strict, try not to use long double

#define mp make_pair
#define pb push_back
#define pf push_front
#define popb pop_back
#define popf pop_front
#define remove erase
//Remember to undefine if the problem is interactive
#define endl '\n'
#define DEBUG(X) cout << ">>> DEBUG(" << __LINE__ << ") " << #X << " = " << (X) << endl

const double eps = 1e-9;
const int INFMEM = 63;
const int INF = 1061109567;
const LL LINF = 4557430888798830399LL;
const double DINF = numeric_limits<double>::infinity();
const LL MOD = 1000000007;
const int dx[8] = {1,0,-1,0,1,1,-1,-1};
const int dy[8] = {0,1,0,-1,1,-1,1,-1};
const double PI = 3.141592653589793;

#ifdef _WIN32
#define getchar_unlocked getchar
#endif
#define GETCHAR getchar_unlocked
inline void fastll(LL &input_number) 
{
    input_number = 0;
    int ch = GETCHAR();
    int sign = 1;
    while(ch < '0' || ch > '9'){
        if(ch == '-') sign=-1;
        ch = GETCHAR();
    }
    while(ch >= '0' && ch <= '9'){
        input_number = (input_number << 3)+(input_number << 1) + ch-'0';
        ch = GETCHAR();
    }
    input_number *= sign;
}

inline void open(string a){
    freopen((a+".in").c_str(),"r",stdin);
    freopen((a+".out").c_str(),"w",stdout);
}

inline void fasterios(){
    //Do not use if interactive
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}

LL n,k;
LL akar(LL x){
	LL ret = sqrt(x);
	while(ret*ret < x) ret++;
	while(ret*ret > x) ret--;
	return ret;
}

int main(){
	fasterios();
    cin >> n;
    k = (8*n)+1;
    LL sq = akar(k);
    if(sq*sq != k){
    	cout << "No" << endl;
    	return 0;
    }
    cout << "Yes" << endl;
    k = (sq-1)/2; k++;
	LL cur = 1;
	LL now = 0;
    cout << k << endl;
    LL sz = (2*n)/k;
    for(int i = 1;i <= k;i++){
    	now += i;
    	cout << sz;
    	for(int j = 1;j <= i-1;j++){
    		cout << " " << cur++;
    	}
    	LL st = now;
    	for(int j = i;j <= sz;j++){
    		cout << " " << st;
    		st += j;
    	}
    	cout << endl;
    }
    return 0;
}
