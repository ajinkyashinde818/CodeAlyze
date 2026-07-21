#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main(){

    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int64_t ans = 0;
    int Amin = 1e9, minus = 0;
    for(int i = 0; i < N; i++){
        ans += abs(A[i]);
        Amin = min(Amin, abs(A[i]));
        if(A[i] < 0) minus++;
    }

    if(minus % 2) cout << ans - (2 * Amin) << endl;
    else cout << ans << endl;

    return 0;
}
