#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    int N;
    cin >> N;
    ll a[200000], sum = 0;
    for(int i=0;i<N;i++){
        cin >> a[i];
        sum += a[i];
    }
    
    ll snuke = 0, arai, min = LLONG_MAX;
    for(int i=0;i<N-1;i++){
        snuke += a[i];
        arai = sum - snuke;
        if(abs(snuke - arai) < min)
            min = abs(snuke - arai);
    }

    cout << min << endl;
    return 0;
}
