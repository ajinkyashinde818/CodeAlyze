#include<iostream>
using namespace std;

int main(){

    int r,g,b,n,ans=0;
    cin >> r >> g >> b >> n;

    for(int i =0; i <= n; i++){
        for(int j = 0; j <= n;j++){
            int t =r*i + g*j;
            if((n -t) % b == 0 && n -t >= 0){
                ans++;                
            }
        }
    }

    cout << ans << endl;
}
