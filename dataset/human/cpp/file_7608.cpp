#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void){
    long long N;
    cin >> N;
    vector<long long> a(N);
    vector<long long> resi(N);
    long long sum = 0;
    for(long long i = 0;i < N;i++){
        resi[i] = 0;
    }
    for(long long i = 0;i < N;i++){
        cin >> a[i];
        sum += a[i];
    }
    long long ans = 10000000000;
    long long sunuke = 0;
    long long arai = 0;
    for(long long i = 0;i < N; i++){
        sunuke += a[i];
        arai = sum - sunuke;
        if(i < N - 1){
            ans = min(ans,abs(sunuke - arai));
        }
    }
    cout << ans << endl;
    return 0;
}
