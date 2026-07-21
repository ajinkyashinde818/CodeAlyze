#include <bits/stdc++.h>
using namespace std;
long long N, A[101010];
int main(){
    cin >> N;
    long long mn = 1e18;
    long long sum = 0;
    long long neg = 0;


    for(int i = 0; i < N; i++){
        cin >> A[i];
        if(A[i] < 0)neg++;
        mn = min(mn, abs(A[i]));
        sum += abs(A[i]);
    }

    if(neg % 2 == 0)cout << sum << endl;
    else cout << sum - 2 * mn << endl;
}
