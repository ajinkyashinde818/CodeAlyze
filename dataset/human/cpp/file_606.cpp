#include<bits/stdc++.h>
using namespace std;

int main(void){
    long long n, r, g, b, cnt=0;
    cin >> r >> g >> b >> n;
    for(int i=0;i*r<=n;++i){
        for(int j=0;j*g<=n-i*r;++j){
            if((n-i*r-j*g)%b==0){
                ++cnt;
            }
        }
    }
    cout << cnt << endl;
}
