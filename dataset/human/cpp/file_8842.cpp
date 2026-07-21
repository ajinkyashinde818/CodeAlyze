#include<algorithm>
#include<cmath>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<sstream>
#include<vector>
using namespace std;
using uint = unsigned int;
using ll = long long;
const int M = 1e9 + 7;
const ll MLL = 1e18L + 9;
#pragma unused(M)
#pragma unused(MLL)
#ifdef LOCAL
#include"rprint.hpp"
#else
template <class... T> void printl(T&&...){ }
template <class... T> void printc(T&&...){ }
template <class... T> void prints(T&&...){ }
template <class... T> void printd(T&&...){ }
#endif

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<char>> as(n, vector<char>(n)), bs(m, vector<char>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> as[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            cin >> bs[i][j];
        }
    }
    for(int i=0;i<n-m+1;i++){
        for(int j=0;j<n-m+1;j++){
            bool ok = true;
            for(int k=0;k<m;k++){
                for(int l=0;l<m;l++){
                    if(as[i + k][j + l] != bs[k][l]){
                        ok = false;
                        break;
                    }
                }
            }
            if(ok){
                cout << "Yes" << '\n';
                return 0;
            }
        }
    }
    cout << "No" << '\n';
    return 0;
}
