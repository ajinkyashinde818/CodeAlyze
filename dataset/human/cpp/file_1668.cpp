#include <iostream>
#include <bitset>
#include <fstream>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <functional>
#include <cctype>
#include <list>
#include <limits>
//#include <boost/multiprecision/cpp_int.hpp>

const double EPS = (1e-10);


using namespace std;
using Int = long long;
//using namespace boost::multiprecision;

const Int MOD = 1000000007;

Int mod_pow(Int x, Int n) {
    Int res = 1;
    while(n > 0) {
        if(n & 1) res = (res * x) % MOD; //ビット演算(最下位ビットが1のとき)
        x = (x * x) % MOD;
        n >>= 1; //右シフト(n = n >> 1)
    }
    return res;
}

vector<vector<int>> ss;

int main(){
    cin.tie(0);

    Int N; cin >> N;
    Int S;
    int flag = 1;
    for (Int i = 1; i*(i-1) <= 2*N; i++){
        if (i*(i-1) == 2*N){
            cout << "Yes" << endl;
            S = i;
            flag = 0;
            break;
        }
    }
    if (flag){
        cout << "No" << endl;
        return 0;
    }
    int cnt = 1;
    ss = vector<vector<int>> (S);
    for (int i = 0; i < S; i++){
        for (int j = i+1; j < S; j++){
            ss[i].push_back(cnt);
            ss[j].push_back(cnt);
            cnt++;
        }
    }
    cout << ss.size() << endl;
    for (auto i : ss){
        cout << i.size() << " ";
        for (int j = 0; j < i.size(); j++){
            cout << i[j];
            if (j != i.size()-1) cout << " ";
        }
        cout << endl;
    }
        
}
