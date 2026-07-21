#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <vector>
#include <cstdlib>
#include <map>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>
#include <functional>
#include <sstream>
#define rep(i,j,n) for(i=j;i<(n);i++)
#define rrep(i,j,n) for(i=j;i>(n);i--)
typedef long long int lli;
#define N 1000000007
#define M 998244353

using namespace std;

int main(){
    lli n,a,Min=N,sum=0,count=0;
    lli i,j;
    cin>>n;
    rep(i,0,n){
        cin>>a;
        if(a<0){
            count++;
        }
        Min=min(Min,abs(a));
        sum+=abs(a);
    }
    if(count%2==1){
        sum-=2*Min;
    }
    cout<<sum<<endl;
}
