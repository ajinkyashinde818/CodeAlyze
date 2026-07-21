#include <iostream>
#include <string>

using namespace std;

const int z = 1e9+7;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int count[26] = {0};
    for (char c : s) {
        count[c-'a']++;
    }

    int ans = 1;
    for (int i = 0; i < 26; i++) {
        ans = 1ll * ans * (count[i] + 1) % z;
    }
    ans--;

    cout << ans << endl;

    return 0;
}
