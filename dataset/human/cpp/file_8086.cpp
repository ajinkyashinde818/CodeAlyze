#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <ctime>
#include <climits>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <utility>
#include <cstdlib>

using namespace std;
long int pow107 = (int)pow(10, 9) + 7;
int ilimit = INT_MAX;
long int llimit = LONG_MAX;

bool comp(pair<int, string> a, pair<int, string> b){
    if(a.first != b.first) return a.first > b.first;
    else return a.second < b.second;
}

long int jou(long int x, long int y){
    long int f = 1;
    for(int i = 0; i < y; ++i){
        f = f * x % pow107;
    }
    return f;
}

bool pn(long int x){
    if(x != 2 && x % 2 == 0)
        return false;
    for(int i = 3; i < x; ++i){
        if(x != i && x % i == 0)
            return false;
    }
    return true;
}

long int factorial(long int n){
    long int f = 1;
    for(long int i = 1; i <= n; ++i){
        f = f * i % pow107;
    }
    return f;
}

int Func2(int n,int m){
    long int s2 = 1,
        r = 1;


    for(int i = 1; i <= m; ++i){
        s2 = (s2*(n - (i - 1))/i) % pow107;
    }

    return s2;
}

//long intの最大llimit
//intの最大ilimit
//10^9+7    pow107
//素数pn
//n乗jou
//階乗factorial
//コンビネーションFunc2

int main(){
    long int n,t = 0;
    cin >> n;
    vector<long int> v;
    for(int i = 0; i < n; ++i){
        long int a;
        cin >> a;
        v.push_back(a);
        t += a;
    }
    long int min = ilimit,a = 0;
    for(int i = 0; i < n - 1; ++i){
        a += v[i];
        t -= v[i];
        //cout << a << " " << t << endl;
        if(min > abs(a-t)){
            min = abs(a-t);
        }
    }
    cout << min << endl;
}
