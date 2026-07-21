#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
ll num[30],ans = 1;
ll mod = 1000000007;
int main(void){
    int n;
    string s;
    cin >> n >> s;
    for(auto c:s) num[c-'a']++;
    for(int i = 0;i < 26;i++){
        ans *= (num[i]+1);
        ans %= mod;
    }
    cout << ans-1 << endl;
    return 0;
}
