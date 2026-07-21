#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
int main(void){
    int n;
    ll mi = 0,sum = 0,ab_mn = 9223372036854775807;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i] < 0) mi++;
        if(abs(a[i]) < ab_mn) ab_mn = abs(a[i]);
        sum += abs(a[i]);
    }
    ll ans = 0;
    if(mi % 2 == 0) cout << sum << endl;
    else cout << sum - 2*ab_mn << endl;
    return 0;
}
