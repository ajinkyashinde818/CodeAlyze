#include <iostream>
#include <vector> 
#include <algorithm>
using namespace std;
int main(void){
    long long int n,max=0,sum=0,ans=1000000000000;
    cin>>n;
    vector<long long int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        max+=a[i];
    }
    for(int i=0;i<n;i++){
        sum+=a[i];
        if(ans>abs(max-2*sum)&&i+1<n)ans=abs(max-2*sum);
    }
    cout<<ans<<endl;
    return 0;
}
