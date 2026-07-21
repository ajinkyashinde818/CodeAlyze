#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;


int main(){
    long long int n,sum=0,ans=2000000000;
    cin>>n;
    vector<long long int>a(300000);
    vector<long long int>b(300000);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }
    b[0]=a[0];
    for(int i=1;i<n-1;i++){
        b[i]=a[i]+b[i-1];        
    }
    for(int i=0;i<n-1;i++){
        if(abs((sum-b[i])-b[i])<ans){
            ans=abs((sum-b[i])-b[i]);
        }      
    }
    cout<<ans<<endl;


    return 0;
}
