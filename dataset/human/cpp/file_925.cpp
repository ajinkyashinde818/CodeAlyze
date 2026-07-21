#include <iostream>

using namespace std;

int main(){
    int r,g,b,n,i,j,ans=0;
    cin >> r >> g >> b >> n;

    for(i=0;i<=n;i++){
        for(j=0;j<=n;j++){
            int a = n-(r*i + g*j);
            if(a >= 0 && a%b == 0){
                ans++;
            }
        }
    }
    cout << ans << endl;

    return 0;
}
