#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n,b=0;
    long ans=0;
    cin >> n;
    vector<long> a(n);
    for (int i=0;i<n;i++){
        cin >> a.at(i);
        if (a.at(i)<0) {
            b++;
            a.at(i)=a.at(i)*(-1);
        }
        ans=ans+a.at(i);
    }
    sort(a.begin(), a.end());
    if (b%2==0) cout << ans << endl;
    else cout << ans-2*a.at(0) << endl;
}
