#include<bits/stdc++.h>
using namespace std;

int main(void){
    int r,g,b,n;
    int ans = 0;
    cin >> r >> g >> b >> n;
    for(int i = 0;r*i <= n;i++){
        for(int j = 0;g*j <= n;j++){
            int sum = r*i+g*j;
            if((n-sum)% b == 0 && n >= sum)ans++;
        }
    }
    cout << ans;
}
