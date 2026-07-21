#include <iostream>
using namespace std;
int main(void){
    int n;
    long long a[200000],b;
    cin>>n>>a[0];
    for(int i=1;i<n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    b=abs(a[0]*2-a[n-1]);
    for(int i=1;i<n-1;i++){
        b=min(b,abs(a[i]*2-a[n-1]));
    }
    cout<<b<<endl;
    
}
