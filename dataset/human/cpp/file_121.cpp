#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int R,G,B,N;
    cin >> R >> G >> B >> N;
    int ans=0;
    for(int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            int tmp=N-R*i-G*j;
            if(tmp>=0&&tmp%B==0) ans++;
        }
    }
    cout << ans << endl;
}
