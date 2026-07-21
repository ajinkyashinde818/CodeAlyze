#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long N; cin >> N;
    long long K = 1;
    bool exist = false;
    for (K = 1; K <= N; ++K) {
        if (K * (K+1) / 2 == N) {
            exist = true;
            break;
        }
    }
        
    if (!exist) puts("No");
    else {
        puts("Yes");
        cout << K+1 << endl;
        vector<vector<long long> > res(K+1, vector<long long>());
        long long sum = 1;
        for (int k = K; k >= 1; --k) {
            for (int i = 0; i < k; ++i) {
                res[K-k].push_back(sum + i);
                res[K-k + i + 1].push_back(sum + i);
            }
            sum += k;
        }
            
        for (int i = 0; i < K+1; ++i) {
            cout << res[i].size();
            for (int j = 0; j < res[i].size(); ++j) cout << " " << res[i][j];
            cout << endl;
        }
    }
}
