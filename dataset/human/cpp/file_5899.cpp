#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; long long C;
    while(cin >> N >> C){
        vector<long long> x(N), v(N);
        for(int i=0;i<N;i++) cin >> x[i] >> v[i];
        vector<long long> c1(N+1, 0), c2(N+1, 0);
        long long cur = 0;
        long long best = 0;
        long long prePos = 0;
        for(int i=0;i<N;i++){
            cur += v[i] - (x[i] - prePos);
            best = max(best, cur);
            c1[i+1] = best;
            prePos = x[i];
        }
        c2[0] = 0;
        cur = best = 0;
        prePos = C;
        for(int i=N-1;i>=0;i--){
            cur += v[i] - (prePos - x[i]);
            best = max(best, cur);
            c2[N-i] = best;
            prePos = x[i];
        }
        long long res = 0;
        for(int i=0;i<N;i++){
            res = max(res, c1[i+1]);
            res = max(res, c2[i+1]);
            res = max(res, c1[i+1] + c2[N-1-i] - x[i]);
            res = max(res, c2[i+1] + c1[N-1-i] - (C - x[N-1-i]));
        }
        cout << res << endl;
    }
}
