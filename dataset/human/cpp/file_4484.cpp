#include<iostream>
#include<algorithm>
using namespace std;
int main(){
int n,m,k;
cin>>n>>m;
k=n/2+1;
for(int i=0;i<n;i++){
    if(i<k)cout<<"0";
    else cout<<m;
    if(i<n-1)cout<<" ";
}
cout<<endl;
 return 0;   
}
