#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    long long total=0;
    long long ans = 1000000000000;
    long long totalr=0;
    long long temp;
    for(int i=0;i<n;i++){
        cin >> a[i];
        total+=a[i];
    }
    for(int i=0;i<n-1;i++){
        totalr+=a[i];
        total -= a[i];
        temp=abs(total-totalr);
        ans = min(ans,temp);
    }
    cout << ans << endl;
}
