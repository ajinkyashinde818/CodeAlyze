#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout.precision(12);
    cout.setf(ios_base::fixed, ios_base::floatfield);
    
    int n;
    cin >> n;
    static int64_t a[100000], b[100000], sum = 0;
    for(int i=0;i<n;i++){ cin >> a[i]; b[i] = abs(a[i]); sum += b[i]; }
    
    int cnt = 0;
    for(int i=0;i<n;i++) if(a[i] < 0) cnt++;
    if(cnt % 2 == 0) cout << sum << endl;
    else cout << sum - 2 * *min_element(b, b+n) << endl;

    return 0;
}
