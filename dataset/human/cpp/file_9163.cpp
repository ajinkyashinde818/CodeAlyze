#include<bits/stdc++.h>
constexpr long long INFL = 1LL << 60;
constexpr int INF = 1 << 30;

using namespace std;

using ll = long long;
using P = tuple<int, int>;
using iarr = valarray<int>;

int main()
{
    int N,M;
    cin >> N >> M;
    vector<string> a(N),b(M);
    for(int i = 0; i < N; ++i) cin >> a[i];
    for(int i = 0; i < M; ++i) cin >> b[i];

    for(int i = 0; i < N-M+1; ++i){
        for(int k = 0; k < N-M+1; ++k){
            bool contain = true;
            for(int j = 0; j < M; ++j){
                for(int l = 0; l < M; ++l){
                    if(a[i+j][k+l] != b[j][l]){
                        contain = false;
                        break;
                    }
                }
                if(!contain) break;
            }
            if(contain){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
    return 0;
}
