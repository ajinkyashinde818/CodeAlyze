#include <iostream>
#include <bits/stdc++.h>
#include <math.h>

using namespace std;

int main(){
    int n,r;
    cin>>n>>r;
    
    if(n>=10) cout<<r<<endl;
    else {
        int hoge=(10-n)*100;
        cout<<r+hoge<<endl;
    }
    
    return 0;
}
