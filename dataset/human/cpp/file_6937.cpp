#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v1(n);
    vector<int> v2(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    for(int i=0;i<n;i++){
        cin>>v2[i];
    }
    reverse(v2.begin(),v2.end());
    int c=-1;
    int l=0;
    int r=0;
    for(int i=0;i<n;i++){
        if(v1[i]==v2[i]){
          c=v1[i];
          l=i;
          break;
        }
    }
    for(int i=n-1;i>=0;i--){
         if(v1[i]==v2[i]){
           r=i;
           break;
        }
    }
    for(int i=0;i<n;i++){
       if(v1[i]!=c && v2[i]!=c && l<=r){
           swap(v2[i],v2[l]);
           l++;
       }
    }
    if(l<=r){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
         for(int i=0;i<n;i++){
            cout<<v2[i]<<" ";
        }
    }


}
