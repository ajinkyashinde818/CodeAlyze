#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll nCr(int n, int r, int dup){
    int nn;
    ll* a = (ll*)calloc(n,sizeof(ll));
    ll retv;
    nn = (dup) ? (n+r-1) : n;
    if ( nn-r < r ) r = nn-r;
    if ( r == 0 ) return 1;
    if ( r == 1 ) return nn;
    for ( int i=1; i<r; i++ ) a[i] = i+2;
    for ( int i=3; i<=nn-r+1; i++ ) {
        a[0] = i;
        for ( int j=1; j<r; j++ ) a[j] += a[j-1];
    }
    retv = a[r-1];
    free(a);
    return retv;
}

int main(){
    int R, G, B, N;
    cin >> R >> G >> B >> N;
    
    
    if(R == 1 && G == 1 && B == 1){
        cout << nCr(N+1,2,1) << endl;
        return 0;
    }
	  
    ll ans = 0;
    for(int i=0;R*i<=3000;i++){
        for(int j=0;R*i+G*j<=3000;j++){
            for(int k=0;R*i+G*j+B*k<=3000;k++){
                if(R*i+G*j+B*k == N)
                    ans++;
            }
        }
    }
    
    cout << ans << endl;

}
