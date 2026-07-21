#include <bits/stdc++.h>
#include <numeric>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int r,g,b,n,c=0,x,y;
    cin >> r >> g >> b >> n;
    for(int i=0;i*r<=n;i++){
        for(int j=0;i*r+j*g<=n;j++){
            x=i*r;
            y=j*g;
            if((n-(x+y))%b==0) c++;
        }
    }
    cout << c << endl;
}
