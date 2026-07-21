#include<iostream>
#include<algorithm>
#include<cstdlib>

using namespace std;

int N;
long long int a[2*100000];

int main(){
    long long int suml = 0;
    long long int sumr = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sumr += a[i];
    }
    long long int ans = 2000000000;
    for(int i = 0; i < N-1; i++){
        suml += a[i];
        sumr -= a[i];
        ans = min(ans, llabs(sumr-suml));
    }
    cout << ans;
    return 0;
}
