#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int r,g,b,n,cnt=0;
    int n1=0,n2=0,n3=0;
    cin >> r >> g >> b >> n;
    for(int i=0;i*r<=n;i++){
        for(int j=0;j*g+i*r<=n;j++){
            int k = (n-r*i-g*j)/b;
            if(k*b+i*r+g*j==n)  cnt++;
        }
    }
    cout << cnt << endl;
}
