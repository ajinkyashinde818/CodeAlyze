#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>
#include <deque>
using ll = long long;
using namespace std;

int main(){
    int n, a, cnt = 0;
    cin >> n;
    vector<int> A;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if(a<0) {
            cnt++;
            A.push_back(-a);
        }
        else A.push_back(a);
    }
    sort(A.begin(), A.end());
    cnt %= 2;
    ll ans = 0;
    if(cnt==1){
        for (int i = 0; i < n; i++) {
            if(!i) ans -= A[i];
            else ans += A[i];
        }
    }
    else{
        for (int i = 0; i < n; i++) {
            ans += A[i];
        }
    }
    cout << ans << endl;
    return 0;
}
