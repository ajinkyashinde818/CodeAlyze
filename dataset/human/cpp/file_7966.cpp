#include <iostream>
using namespace std;
typedef long long ll;
int n;
ll arr[200001];
ll prefSum[200001];
int main(int argc, const char * argv[]) {
    ios_base::sync_with_stdio(false);
    cin >> n;
    ll sum = 0;
    for(int i =0 ; i < n; i ++){
        cin >> arr[i];
        sum += arr[i];
        prefSum[i] = sum;
    }
    ll mnn = (1LL << 60LL);
    ll A = 0, B;
    for(int i = 0; i + 1 < n; i ++){
        A += arr[i];
        B = prefSum[n - 1] - A;
        mnn = min(mnn, abs(A - B));
    }
    cout << mnn << endl;
    return 0;
}
