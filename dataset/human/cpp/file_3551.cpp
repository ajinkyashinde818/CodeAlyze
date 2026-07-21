#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int64_t N,A;
    int64_t minabs;
    int64_t sum = 0;
    int64_t minuscnt = 0;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> A;
        sum += abs(A);
        if(A < 0) minuscnt++;
        if(minabs > abs(A)) {
            minabs = abs(A);
        }
    }

    if(minuscnt%2) cout << sum - minabs - minabs << endl;
    else cout << sum << endl;
    return 0;
}
