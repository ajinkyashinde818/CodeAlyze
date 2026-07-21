#include<iostream>
#include<cassert>
#include<stdexcept>
#include<utility>
#include<functional>
#include<numeric>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<array>
#include<stack>
#include<queue>
#include<deque>
#include<vector>
#include<complex>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<bitset>
using namespace std;
using ll=long long;

int main(){
    int r,g,b,n;
    cin>>r>>g>>b>>n;
    int res=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            int rest=n-r*i-g*j;
            if(rest<0) continue;
            if(rest%b==0) res++;
        }
    }
    cout<<res<<endl;
    
    return 0;
}
