#include<iostream>
#include<string>
#include<vector>
#include<algorithm>//sort,reverse
#include<utility>//pair
#include<queue>//queue,priority queue
#include<deque>//double_ended queue
using namespace std;
int main()
{ 
    int n;
    cin>>n;
    long long int k;
    int sgn=0;
    long long int a[n];
    for(int i=0;i<n;i++){
        cin>>k;
        if(k<0){
            k=-k;
            sgn=1-sgn;
        }
        a[i]=k;
    }
    sort(a,a+n);
    long long int ans=0;
    if(sgn==0){
        ans=a[0];
    }
    else{
        ans=-a[0];
    }
    for(int i=1;i<n;i++){
        ans=ans+a[i];
    }
    cout<<ans<<endl;
    return 0;
}
