#include<iostream>

using namespace std;
int R,G,B,N;
int r,g,b;
int ans=0;
void solve(){
    int k=0;
    for(int i=0;i<=r;i++){
        for(int j=0;j<=g;j++){
                k=N-i*R-j*G;
                if(k>=0&&k%B==0)ans++;
        }
    }
    cout << ans;
}

int main(){
    cin >> R >> G >> B >> N;
    r=N/R;
    g=N/G;
    solve();
}
