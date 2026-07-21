#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include<cmath>
#include<limits>
#define ll long long
#define ALL(x) (x).begin(),(x).end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define int_INF 2147483647
#define pint_INF 2000000000
#define ll_INF 	9223372036854775807
#define MOD 1000000007
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define pii pair<int,int>
#define vpii vector<pair<int,int>>
#define vvc vector<vector<char>>
#define sysp system("PAUSE")
using namespace std;

bool check(int x, int y, vvc test, vvc table){
    for(int p = 0; p < test.size(); p++){
        for(int q = 0; q < test.size(); q++){
            if(table[p+x][q+y] == test[p][q]){
                continue;
            }else{
                return false;
            }
        }
    }

    return true;
}

int main(){
    int N,M; cin >> N >> M;
    vector<vector<char>> table(N,vector<char>(N));

    rep(i,N) rep(j,N) cin >> table[i][j];

    vector<vector<char>> test(M,vector<char>(M));

    rep(i,M) rep(j,M) cin >> test[i][j];

    int K = N - M;
    bool flag = false;
    for(int k = 0; k <= K; k++){
        for(int l = 0; l <= K; l++){
            if(check(k,l,test,table)){
                flag = true;
            }
        }
    }

    if(flag){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    sysp;
}
