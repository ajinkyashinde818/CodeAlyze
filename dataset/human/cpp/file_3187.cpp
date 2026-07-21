#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<long long int> A(N);
    long long int ans=0;
    long long int mna=1e9+1;
    bool flag=true;
    for(int n=0; n<N; n++) {
        cin >> A[n];
        mna = min(mna, abs(A[n]));
        ans += abs(A[n]);
        if(A[n]<0) {
            flag = flag ? false : true;
        }
    }
    if(flag) {
        cout << ans << endl;
    } else {
        cout << ans-mna*2 << endl;
    }

    return 0;
    
}
