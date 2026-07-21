#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    int A[114514];
    cin>>N;
    int plus=0,zero=0,minus=0;
    for(int i=0;i<N;i++){
        cin>>A[i];
        if (A[i]>0){
            plus++;
        }
        else if(A[i]==0){
            zero++;
        }
        else{
            minus++;
        }
    }
    if (zero>0){
        long long int ans=0;
        for(int i=0;i<N;i++){
            ans+=abs(A[i]);
        }
        cout<<ans<<endl;
    }
    else{
        if (minus%2==0){
            long long int ans=0;
            for(int i=0;i<N;i++){
                ans+=abs(A[i]);
            }
            cout<<ans<<endl;
        }
        else{
            int m=abs(A[0]);
            long long int ans=0;
            for(int i=0;i<N;i++){
                ans+=abs(A[i]);
                m=min(m,abs(A[i]));
            }
            cout<<ans-2*m<<endl;
        }
    }
    return 0;
}
