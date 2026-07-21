#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(int i=0; i<N; i++)
        cin >> A[i];
    int cnt = 0;
    for(int i=0; i<N; i++)
        if(A[i] < 0)
            cnt++;
    vector<long long> B(N);
    for(int i=0; i<N; i++)
        B[i] = abs(A[i]);

    sort(B.begin(), B.end());
    long long ans = 0;
    for(int i=0; i<N; i++)
        ans += B[i];
    if(cnt%2==1)
        ans -= 2*B[0];
    cout << ans << endl;
    return 0;
}
