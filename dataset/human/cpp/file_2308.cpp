#include <iostream>
#include<algorithm>
using namespace std;
int main(void){
    long long N,i,count,ans;
    cin>>N;
    long long A[N];
    count=0;ans=0;
    for(i=0;i<N;i++){
        cin>>A[i];
        if(A[i]<0){
            count++;
            A[i]=-A[i];
        }
        ans+=A[i];
    }
    sort(A,A+N);
    if(count%2==1){
        ans=ans-A[0]*2;
    }
    cout<<ans<<endl;
}
