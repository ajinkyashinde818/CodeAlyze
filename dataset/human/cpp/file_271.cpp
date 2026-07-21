#include<iostream>
typedef long long ll;
using namespace std;
int main(){
    int R, G, B, N; cin >> R >> G >> B >> N;
    ll cnt = 0;
    for(int i=0; i<=N; i++)for(int j=0; j<=N-i; j++)if((N - i*R - j*G) % B == 0 && i*R + j*G <= N) cnt++;
    cout << cnt << endl;
    return 0;
}
