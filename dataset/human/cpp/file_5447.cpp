#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
#include<map>
using namespace std;
int main() {
    int n,r;
    cin >> n >> r;
    if(n < 10){
        int ans = 100 * (10 - n);
        ans += r;
        cout << ans << endl;
    }else{
        cout << r << endl;
    }
}
