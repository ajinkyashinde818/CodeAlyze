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
typedef long long int ll;
typedef long double ld;
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int MOD=1000000007;
const int MAX_N=500010;
const ll INF=99999999999;

int main(){
    ll N,a,sum,m,neg;
    sum=0; neg=0; m=INF;
    cin>>N;
    for(int n=0;n<N;n++){
        cin>>a;
        sum+=abs(a);
        m=min(m,abs(a));
        if(a<0) neg++;
    }
    if(neg%2==0){
        cout<<sum<<endl;
    }else{
        cout<<sum-2*m<<endl;
    }
    return 0;
}
