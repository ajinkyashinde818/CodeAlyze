#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll l;
    cin >> n >> l;
    int trie[200005][2];
    for(int i = 0; i < 200005; i++) trie[i][0] = trie[i][1] = -1;
    ll b[100005]{0};
    int e = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        int c = 0;
        bool f = false;
        for(ll j = 0; j < (int)s.size(); j++){
            if(trie[c][s[j] - '0'] == -1){
                e++;
                trie[c][s[j] - '0'] = e;
                if(!f){
                    b[j]++;
                    b[s.size()]++;
                    f = true;
                }
            }
            c = trie[c][s[j] - '0'];
        }
    }
    for(ll i = 1; i < 100002; i++) b[i] += b[i - 1];
    ll x = 0;
    for(ll i = 0; i < 100003; i++){
        if(b[i] % 2){
            x ^= ((l - i) & (i - l));
        }
    }
    if(x) cout << "Alice" << endl;
    else cout << "Bob" << endl;
}
