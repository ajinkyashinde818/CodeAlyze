#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,g,b,n;
    cin >> r >> g >> b >> n;
    int a;
    if(b>g){
        a=b;
        b=g;
        g=a;
    }
    if(g>r){
        a=g;
        g=r;
        r=a;
    }
    if(b>g){
        a=b;
        b=g;
        g=a;
    }
    int count=0;
    for(int i=0;i<=(n+r-1)/r;i++){
        for(int j=0;j<=(n-r*i+g-1)/g;j++){
            if((n-r*i-g*j)%b==0&&(n-r*i-g*j)/b>=0)count++;
        }
    }
    cout << count << endl;
}
