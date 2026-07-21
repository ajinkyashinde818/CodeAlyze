#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <functional>
#include <cmath>
using ll = long long;
using namespace std;
int gcd(int x,int y){
    if(y==0){
        return x;
    }else{
        return gcd(y,x%y);
    }
}
int lcm(int x,int y){
    return x/gcd(x,y)*y;
}
int main(){
    ll r,g,b,n;
    cin >> r >> g >> b >> n;
    ll c=0;
    for(int i=0;i<=3000;i++){
        ll sum=n;
        sum -= i*r;
        if(sum<0){
            break;
        }
        if(sum==0){
            c++;
          //  cout<<i<<" "<<" "<<endl;
            break;
        }
        for(int j=0;j<=3000;j++){
            ll sum1 = sum;
            sum1 -= j*g;
            if(sum1<0){
                break;
            }
            if(sum1==0){
                c++;
             //   cout<<i<<" "<<j<<" "<<0<<endl;
                break;
            }
            if(sum1%b==0){
                c++;
              //  cout<<i<<" "<<j<<" "<<sum1/b<<endl;
                continue;
            }
        }
    }
    cout << c <<endl;
}
