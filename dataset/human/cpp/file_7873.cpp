#include<iostream>
using namespace std;
long long int a[200007];
int main(){
    int n;
    long long int i,j,k;
    long long int c,d,s;
    cin>>n;
    for(i=0,c=0;i<n;i++){
        cin>>a[i];
        c+=a[i];
    }
    s=-1;
    for(i=0,k=0;i<n-1;i++){
        k+=a[i];
        d=c-2*k;
        if(d<0)d=-d;
        if(d<s || s==-1)s=d;
    }
    cout<<s<<endl;
    return 0;
    
}
