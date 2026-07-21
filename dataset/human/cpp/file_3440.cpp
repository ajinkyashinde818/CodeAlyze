#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
int A[100000];
int main(){
    int n;
    cin >> n;
    bool neg = false;
    bool zero = false;
    for(int i=0;i<n;i++){
        cin >> A[i];
        neg ^= A[i] < 0;
        if(A[i] == 0){
            zero = true;
        }
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        ans += abs(A[i]);
        A[i] = abs(A[i]);
    }
    if(!zero && neg){
        ans -= *min_element(A,A+n)*2;
    }
    cout << ans;
    return 0;
}
