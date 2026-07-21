#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];  
    }
    long long ans = 0;
    int cnt_neg = 0;
    int min_num = INT_MAX;
    
    for (int i = 0; i < n; ++i) {
        if (A[i] < 0) {
            ++cnt_neg;  
        }
        ans += abs(A[i]);
        min_num = min(min_num, abs(A[i]));
    }
  //cout << "cnt = " << cnt_neg << endl;  
  //cout << "min = "<<min_num << endl;
    if (cnt_neg % 2 == 1) {
    	ans -= min_num;
        ans -= min_num;
    }
    cout << ans << endl;  
    return 0;
}
