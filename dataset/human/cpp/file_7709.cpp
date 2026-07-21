#include <iostream>
#include <vector>

using namespace std;

long long abso(long long n){
    if(n < 0){
        n = -1 * n;
    }
    return n;
}

int main(){

    int N;
    cin >> N;

    vector <int> a(N);
    long long ans = 0, sum1 = 0, sum2 = 0;
    for (int i = 0; i < N; i++){
        cin >> a[i];
        ans += abso(a[i]);
        sum1 += a[i];
    }

    for (int i = N - 1; i >= 1; i--){
        sum1 -= a[i];
        sum2 += a[i];

        if (ans > abso(sum1 - sum2)){
            ans = abso(sum1 - sum2);
        }
    }
    
    cout << ans << endl;

    return 0;
}
