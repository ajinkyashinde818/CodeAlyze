#include <bits/stdc++.h>

using namespace std;

vector<string> split(const string& s, char c) {
    vector<string> v; stringstream ss(s); string x;
    while (getline(ss, x, c)) v.emplace_back(x); return move(v);
}
template<typename T, typename... Args>
inline string arrStr(T arr, int n) {
    stringstream s; s << "[";
    for(int i = 0; i < n - 1; i++) s << arr[i] << ",";
    s << arr[n - 1] << "]";
    return s.str();
}

#define ANTHRO(args...) {__anthro_begin(__LINE__); __anthro(split(#args, ',').begin(), args);}

inline void __anthro_begin(int line) { cerr << "#" << line << ": "; }
template<typename T> inline void __anthro_out_var(vector<T> val) { cerr << arrStr(val, val.size()); }
template<typename T> inline void __anthro_out_var(T* val) { cerr << arrStr(val,2); } //Change the values in case you want to debug something
template<typename T> inline void __anthro_out_var(T val) { cerr << val; }
inline void __anthro(vector<string>::iterator it) { cerr << endl; }

template<typename T, typename... Args>
inline void __anthro(vector<string>::iterator it, T a, Args... args) {
    cerr << it->substr((*it)[0] == ' ', it->length()) << "=";
    __anthro_out_var(a);
    cerr << "; ";
    __anthro(++it, args...);
}
//Simple Debugger

#define ll long long
#define MOD 1000000007
#define EPS 1e-9
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
/*
    This is A. Beginner
    ABC 156
*/

int main(){
    ll n,r; cin>>n>>r;
    if(n<10){
        cout<<r+(100*(10-n));
    }
    else{
        cout<<r;
    }
    return 0;
}
