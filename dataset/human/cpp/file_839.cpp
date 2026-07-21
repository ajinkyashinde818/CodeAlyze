#include<iostream>
using namespace std;

int main(){
        int r, g, b, n;
        cin >> r >> g >> b >> n;
        int ans = 0;
        for(int r_num=0; r_num <= n/r; r_num++){
                for(int g_num=0; g_num <= (n-r*r_num)/g; g_num++){
                        if((n-r*r_num-g*g_num)%b == 0) ans++;
                }
        }
        cout << ans << endl;

        return 0;
}
