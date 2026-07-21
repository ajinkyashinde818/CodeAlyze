#include <iostream>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int A[N];
    int mini = 1000000005;
    ll sum = 0;
    int cnt = 0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        mini = min(abs(A[i]), mini);
        sum = sum + abs(A[i]);
        if(A[i] < 0) cnt++;
    }

    if(cnt%2 == 0) cout << sum << endl;
    else cout << sum - (ll)2*mini << endl;

    return 0;
}
