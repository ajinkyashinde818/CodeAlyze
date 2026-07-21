#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <functional>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <cmath>
#include <cctype>
#include <cstdio>
#define ll long long
#define INF 1e+9
#define MOD 1000000007
using namespace std;


int main(){
    int R,G,B,N;
    cin >>  R >> G >> B>>N;
    ll ans=0;
    for(int i=0; i*R<=N; i++){
        for(int j=0; j*G<=N; j++){
            
            if((N-i*R-j*G)%B==0 && (N-i*R-j*G)>=0){
                ans++;
            }
            
        }
    }
    cout<<ans<<endl;
    return 0;
}
