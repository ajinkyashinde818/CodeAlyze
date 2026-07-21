#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int>A(N),B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    reverse(B.begin(),B.end());
    for(int i = 0; i < N; i++) {
        if(A[i] == B[i]) {
            int now = N,now2 = N;
            for(int j = i+1; j < N; j++){
                if(A[i] != B[j]) now2 = min(now2,j);
                if(A[i] != B[j] && A[i] != A[j]) {now = j;break;}
            }
            int old = now;
            now = -1;
            for(int j = i-1; j >= 0; j--) if(A[i] != B[j] && A[i] != A[j]) {now = j;break;}
            if(!(now+1+N-old < now2-i)) {
                for(int j = i; j < now2; j++){
                    if(j-i < N-old) swap(B[j],B[old+j-i]);
                    else swap(B[j],B[now-(j-i)+(N-old)]);
                }
            }
            else {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    for(int i = 0; i < N; i++) {
        cout << B[i] << ((i+1 == N)?"\n":" ");
    }
}
