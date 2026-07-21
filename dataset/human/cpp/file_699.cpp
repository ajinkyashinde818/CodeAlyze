#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
using tpl = tuple<int, int, int>;
typedef pair<int,int> pii;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

int R, G, B, N;

int main(){
    
    cin >> R >> G >> B >> N;
    ll sum = 0;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            int k = N - (i*R + j*G);
            if(k >= 0 && k % B == 0){
                sum++;
                // cout << i << " " << j << " " << k << endl;
            }
        }
    }
    cout << sum << endl;


    return 0;
}
