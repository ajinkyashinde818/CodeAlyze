#include <iostream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <string>
#include <functional>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <bitset>
#define pb push_back
#define YES cout<<"YES"<<endl
#define Yes cout<<"Yes"<<endl
#define NO cout<<"NO"<<endl
#define No cout<<"No"<<endl
#define rep(i,n) for(int i=0;i<n;i++)
#define INF (1<<20)
#define LLINF (1LL<<60)
#define MOD 1000000007
typedef long long ll;
using namespace std;

int main(){
    int n,r;
    cin >> n >> r;
    if(n>=10){
        cout << r;
    }else{
        cout << r + (10 - n) * 100;
    }
    return 0;
}
