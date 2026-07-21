#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin>>N;
    
    long long a[N];
    long long sum=0,mae=0,ans=1e18;
 
    for(int i=0;i<N;i++){
        cin >>a[i];
        sum+=a[i];
    }
    for(int i=0;i<N;i++){
        mae+=a[i];
        if(i+1<N)ans=min(ans,abs(sum-mae*2));
    }
        cout<<ans<<endl;
}
