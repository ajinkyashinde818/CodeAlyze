#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <complex>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <cassert>
#include <fstream>
#define popcount __builtin_popcount
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
    int n; cin>>n;
    ll a, mn=1e9;
    ll sum=0;
    int c=0;
    for(int i=0; i<n-1; i++){
        cin>>a;
        sum+=abs(a);
        mn=min(mn, abs(a));
        if(a<0) c++;
    }
    cin>>a;
    if(c&1) cout<<max(sum-a, sum+a-2*mn)<<endl;
    else cout<<max(sum+a, sum-a-2*mn)<<endl;
    return 0;
}
