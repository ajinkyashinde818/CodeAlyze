#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,k,cnt=0;
  int R,G,B,n;
  cin>>R>>G>>B>>n;
  for(i=0;;i++){
    int p=R*i;
    if(p>n)break;
    for(j=0;;j++){
      int q=p+G*j;
      if(q>n)break;
      for(k=(n-q)/B;;k++){
        int r=q+B*k;
        if(r==n)cnt++;
        if(r>n)break;
      }
    }
  }
  cout<<cnt<<endl;
}
