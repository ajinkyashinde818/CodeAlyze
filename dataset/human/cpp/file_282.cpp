#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#include <limits>
#include <iomanip>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    int cnt=0;
    for(int i=0;i<=N/R;i++){
        for(int j=0;j<=N/G;j++){
            int num = N - i*R - j*G;
            if(num<0){
                break;
            }
            else{
                if(num%B==0){
                    cnt++;
                }
            }
        }
    }
    cout << cnt<< endl;
}
