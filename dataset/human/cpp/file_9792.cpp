#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1e6;

int main(){
    int n;
    string s;
    cin >> n >> s;
    vector<int> a(30, 1);
    for (int i=0; i<n; i++){
        a[s[i]-'a']++;
    }
    long long int ans=1;
    for (int i=0; i<30; i++){
        ans *= a[i];
        ans = ans%1000000007;
    }

    cout << ans-1 << endl;
}
