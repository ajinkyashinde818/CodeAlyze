#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    int a[n];for(int i=0;i<n;i++)cin>>a[i];
    long int m[n]={0};
    m[0]=a[0];
    for(int i=1;i<n;i++){
        m[i]=a[i]+m[i-1];
        //cout<<m[i];cout<<endl;
    }//cout<<endl;
    long long  min=9999999999999;
    for(int i=0;i<n-1;i++){
        if(abs((-m[i]+m[n-1])-m[i])<min) min=abs((-m[i]+m[n-1])-m[i]);
    }
    cout<<min<<endl;
}
