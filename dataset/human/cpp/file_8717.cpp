#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll MOD = 1000000007;

int main(){
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(N);
    for(int i=0;i<N;i++){
        cin >> A[i];
    }
    for(int i=0;i<M;i++){
        cin >> B[i];
    }
    for(int ai=0;ai<N;ai++){
        for(int aj=0;aj<N;aj++){
            bool ok = true;
            for(int bi=0;bi<M;bi++){
                for(int bj=0;bj<M;bj++){
                    if(N <= ai + bi || N <= aj + bj || A[ai+bi][aj+bj] != B[bi][bj]){
                        ok = false;
                        break;
                    }
                }
                if(!ok) break;
            }
            if(ok){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
