#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int r, g, b, n, cnt;
    cin >> r >> g >> b >> n;
    cnt = 0;
    int a[3] = {r, g, b};
    sort(a, a + 3);
    int max = n / a[2];
    while(max >= 0){
        int m = n - max * a[2];
        int tmp = m / a[1];
        while(tmp >= 0){
            int l = m - tmp * a[1];
            if(l % a[0] == 0 || l == 0) cnt++;
            tmp--;
        }
        max--;
    }
    cout << cnt << endl;
    return 0;
}
