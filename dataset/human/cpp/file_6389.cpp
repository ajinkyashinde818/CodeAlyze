#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MOD = 1e+9 + 7;

int main()
{
    int N;
    cin >> N;
    string S;
    cin >> S;

    // 端は1回しかひっくり返せないので、端が W だったらアウト
    if(S[0] == 'W' or S[2*N-1] == 'W'){
        cout << 0 << endl;
        return 0;
    }

    // ひっくり返す順番は関係ないので、組み合わせに着目する
    // その際、左端として選ばれるか右端として選ばれるかだけが大事
    long long ans = 1;
    int num_L = 1, num_R = 0;
    vector<char> is_LR(2*N);
    is_LR[0] = 'L';
    for(int i = 1; i < 2*N; ++i){
        if(S[i-1] == S[i]) is_LR[i] = (is_LR[i-1] == 'R')? 'L': 'R'; 
        if(S[i-1] != S[i]) is_LR[i] = (is_LR[i-1] == 'R')? 'R': 'L'; 
        if(is_LR[i] == 'L') ++num_L;
        if(is_LR[i] == 'R'){
            ans = ans * (num_L - num_R) % MOD;
            ++num_R;
        }
    }
    for(int i = 1; i <= N; ++i) ans = (ans*i) % MOD;
    if(num_L == num_R) cout << ans << endl;
    else cout << 0 << endl;

    return 0;
}
