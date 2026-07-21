#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int ans=0;
    for(int i=0;i<=3000;i++){
        for(int j=0;j<=3000;j++){
            int v = i * r + j * g;
            if(n >= v && (n - v) % b == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
