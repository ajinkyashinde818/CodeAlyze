#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int a,b,c;
    long long n;
    cin >> a >> b >> c >> n;
    long long ans=0;
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            if((n-(i*a+j*b))<0)break;
            if((n-(i*a+j*b))%c==0)ans++;
        }
    }
    cout << ans;
}
