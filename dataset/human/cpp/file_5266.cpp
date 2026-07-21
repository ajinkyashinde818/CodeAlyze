#include <stdio.h>
#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;
int main(){
    int n, r;
    int ans;
    cin>>n>>r;
    if (n < 10){
        ans = r + 100 * (10 - n);
    }else{
        ans = r;
    }
    cout<<ans<<endl;
}
