#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>

#define repd(i,a,b) for (int i=(a);i<(b);++i)
#define rep(i,n) repd(i,0,n)
#define reprd(i,a,b) for (int i=(a);i>=(b);--i)
#define repr(i,n) reprd(i,n,0)
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

using namespace std;

const ll BIG = 1000000007LL;

int inputValue(){
    int a;
    cin >> a;
    return a;
};

template<typename T>
void inputArray(T* p, int a){
    rep(i, a){
        cin >> p[i];
    }
};

template<typename T>
void inputVector(vector<T> * p, int a){
    rep(i, a){
        T input;
        cin >> input;
        p -> push_back(input);
    }
}

template <typename T>
void output(T a, int precision = 0) {
    if(precision > 0){
        cout << setprecision(precision)  << a << "\n";
    }
    else{
        cout << a << "\n";
    }
}

const int Max = 110000;
int N;
ll A[Max], Aabs[Max];

int main(int argc, const char * argv[]) {
    cin >> N;
    inputArray(A, N);

    int minusCount = 0;
    rep(i, N) {
        if (A[i] < 0) minusCount++;
    }

    rep(i, N) {
        Aabs[i] = abs(A[i]);
    }

    ll sumA = 0;
    rep(i, N) {
        sumA += Aabs[i];
    }

    if (minusCount %2 == 0) {
        output(sumA);
    } else {
        ll minA = Aabs[0];
        rep(i, N) {
            chmin(minA, Aabs[i]);
        }
        output(sumA - 2*minA);
    }

    return 0;
}
