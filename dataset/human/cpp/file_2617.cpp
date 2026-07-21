#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for (int i = 0; i < N;i++)
        cin >> a[i];

    vector<long long> dp0(N);
    vector<long long> dp1(N);
    dp0[0] = a[0];
    dp1[0] = -a[0];
    for (int i = 1; i < N;i++){
        dp0[i] = max(dp0[i-1] + a[i], dp1[i-1] - a[i]);
        dp1[i] = max(dp0[i - 1] - a[i], dp1[i - 1] + a[i]);
        }
        cout << dp0[N - 1] << endl;
        return 0;
}
