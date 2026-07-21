#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

int main(void){
    int n, a[200005];
    cin >> n;
    long long snuke=0, arai=0;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(i==0){
            snuke += a[i];
        }else{
            arai += a[i];
        }
    }
    long long ans = abs(snuke-arai);
    for(int i=1; i<n-1; i++){
        snuke += a[i];
        arai -= a[i];
        ans = min(ans, abs(snuke-arai));
    }
    cout << ans << endl;
    return 0;
}
