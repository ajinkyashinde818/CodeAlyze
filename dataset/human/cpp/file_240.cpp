#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int long long a,b,c,n;
    int long long ans=0;
    cin >> a >> b >> c >> n;
    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            if((n-i*a-j*b)%c==0 && n-i*a-j*b>=0){
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
