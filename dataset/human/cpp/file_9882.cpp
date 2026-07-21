#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    string s;
    int cnt[26] = {};
    long long int ans = 1;


    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cnt[s[i]-'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i]) {
            ans *= (cnt[i]+1);
        }
        ans %= 1000000007;
    }

    cout << ans-1 << endl;
}
