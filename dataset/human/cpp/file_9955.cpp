#include <iostream>

using namespace std;
typedef long long ll;

const int MAX = 1e5+10;
const int MOD = 1e9+7;

int N;
string S;
int count[MAX];

int main () {
    cin >> N >> S;
    for (int i = 0; i < N; i++) count[S[i] - 'a']++;
    ll ans = 1;
    for (int i = 0; i < 26; i++) {
        (ans *= (count[i]+1)) %= MOD;
    }
    cout << ans-1 << endl;
}
