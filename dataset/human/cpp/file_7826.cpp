#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    vector <long long int> cards (N);
    long long int sum = 0;
    long long int ans = LONG_MAX;
    for(int i = 0; i < N; i++){
        long long int z;
        cin >> z;
        if(i==0){
            cards[i] = z;
        }else{
            cards[i] = (z+cards[i-1]);
        }
        sum = cards[i];
    }
//    cout << sum << "\n";
    for(int i = 0; i < N-1; i++){
        long long int a = cards[i];
        long long int b = sum-a;
  //      cout << a << " " << b << "\n";
        ans = min(ans, abs(a-b));
    }
    cout << ans << "\n";
    return 0;
}
