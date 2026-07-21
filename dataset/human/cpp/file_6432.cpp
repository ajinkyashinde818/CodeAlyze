#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <math.h>
#include <string>
#include <map>
#include <cstdlib>
#include <sstream>
#include <bitset>
using namespace std;

typedef long long ll;
ll mod=1000000007;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<int> LR(2*N);//-1L,1R
    if(S[0]=='W' || S[2*N-1]=='W'){
        cout << 0 << endl;
        return 0;
    }

    LR[0]=-1;
    LR[2*N-1]=1;
    int cnt=1;
    for(int i=1; i<2*N-1; i++){
        if(S[i]==S[i-1]) LR[i]=LR[i-1]*-1;
        else LR[i]=LR[i-1];

        if(LR[i]==1) cnt++;
    }

    if((S[2*N-2]==S[2*N-1] && LR[2*N-2]==LR[2*N-1]) || (S[2*N-2]!=S[2*N-1] && LR[2*N-2]!=LR[2*N-1]) || cnt!=N){
        cout << 0 << endl;
        return 0;
    }

    int c_L=0;
    ll ans=1;
    for(int i=0; i<2*N; i++){
        if(LR[i]==-1) c_L++;
        else{
            ans*=c_L;
            c_L--;
            ans%=mod;
        }
    }
    for(int i=0; i<N; i++){
        ans*=(i+1);
        ans%=mod;
    }
    
    cout << ans << endl;

    return 0;
}
