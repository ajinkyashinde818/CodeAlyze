#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N,R;
    cin>>N>>R;
    int ans=0;
    if (N<=10){
         ans = R + 100*(10-N);
    }
    else{
        ans = R;
    }
    cout<<ans;
}
