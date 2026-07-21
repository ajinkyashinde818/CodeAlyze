#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = (int)1e9 + 7;
const int INF = (int)100100100;

int main() {
    //ll N; cin >> N;
    //ll N,M; cin >> N >> M;
    //string S; cin >> S;
    //ll H,W; cin >> H >> W;
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int r=N/R;
    int sum=0;
    for(int i=0;i<r+1;i++){
        int g=(N-i*R)/G;
        for(int j=0;j<g+1 && (N-i*R-j*G)>=0;j++){
            int x=N-i*R-j*G;
            if(x%B==0 && x>=0)sum++;
        }
    }
    cout << sum;


}

/*



 */
