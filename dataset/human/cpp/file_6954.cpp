#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    map<int, int> ma, mb;
    vector<int> cnt[200010];
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i]].push_back(i);
        ma[A[i]]++;
    }
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        mb[B[i]]++;
    }
    for(auto v: mb){
        int t = v.second + ma[v.first];
        if(t > N){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    int now = -1, j;
    for(int i = 0; i < N; i++){
        if(now != A[i]) j = 0;
        if(A[i] == B[i]){
            for(; j < N; j++){
                if(A[i] != A[j] && B[j] != A[i]){
                    swap(B[i], B[j]);
                    break;
                }
            }
        }
        now = A[i];
    }
    for(int i = 0; i < N; i++){
        if(i != N - 1) cout << B[i] << ' ';
        else cout << B[i] << endl;
    }
}
