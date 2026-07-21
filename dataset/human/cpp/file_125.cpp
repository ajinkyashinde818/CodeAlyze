#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    int n,ans=0,b=0;
    vector<int> a(3);
    cin >> a.at(0) >> a.at(1) >> a.at(2) >> n;
    sort(a.begin(), a.end());
    int k=n/a.at(2);
    for (int i=0;i<k+1;i++){
        while (a.at(2)*i+a.at(1)*b<=n){
            if ((n-(a.at(2)*i+a.at(1)*b))%a.at(0)==0) ans++;
            b++;
        }
        b=0;
    }
    cout << ans << endl;
}
