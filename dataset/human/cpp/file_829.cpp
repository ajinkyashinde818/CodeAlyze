#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef vector<int> V;
const long long MOD=1000000007LL;
const long long INFL=1LL << 60;
const int INF=1<<29;


int main() {
    int R,G,B,N;
    cin >>R>>G>>B>>N;
    int cnt=0;
    for(int i=0;i<=N/R;i++){
        for(int j=0;j<=(N-i*R)/G;j++){
            if((N-i*R-j*G)%B==0) cnt++;
        }
    }
    cout<<cnt<<endl;

    return 0;
}
