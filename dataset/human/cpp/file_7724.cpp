#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    long long sum = 0;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];
    }

    long long ans = __LONG_LONG_MAX__;
    long long L = 0;
    for(int i = 0; i < N; i++){
        L += a[i];
        if(i < N-1){
            ans = min(ans, abs(sum-2*L));
        }
    }

    cout << ans << endl;


    return 0;
}
