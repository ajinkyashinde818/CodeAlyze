#include <bits/stdc++.h>
using namespace std;

long long sum (vector<int> vec) {
    long long ans = 0;
    for (int i = 0; i < vec.size(); i++) ans += vec.at(i);
    return ans;
}

int allmin (vector<int> vec) {
    int ans = 1000000001;
    for (int i = 0; i < vec.size(); i++) {
        ans = min(ans, vec.at(i));
    }
    return ans;
}

int count_minus (vector<int> vec) {
    int ans = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec.at(i) < 0) ans++;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i; i < N; i++) cin >> A.at(i);
    
    vector<int> absA(N);
    for (int i; i < N; i++) absA.at(i) = abs(A.at(i));
  	
    long long ans;
    if (count_minus(A)%2 == 0) ans = sum(absA);
    else ans = sum(absA) - 2 * allmin(absA);
    cout << ans << endl;
}
