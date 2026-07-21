#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MOD=1000000007;

int main(){
    int n,r;
    cin>>n>>r;
    if(n<10){
        cout<<100*(10-n)+r;
    }else{
        cout<<r;
    }
    return 0;
}
