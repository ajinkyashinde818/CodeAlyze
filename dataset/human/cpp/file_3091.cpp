#include <bits/stdc++.h>
using namespace std;


int main(){
    // Your code here!
    int n;
    
    cin >> n;
    
    vector<int> a(n);
    
    int count = 0;
    int sacrifice = pow(10,9)+1;
    long int ans = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        ans=ans+abs(a[i]);
        if (a[i]<0) {
            count++;
        }
        sacrifice = min(abs(a[i]),sacrifice);
        
    }
    
    if (count%2==1) {
        cout << ans-2*sacrifice << endl;
    } else {
        cout << ans << endl;
    }
    
    return 0;
}
