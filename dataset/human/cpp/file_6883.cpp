#include <bits/stdc++.h>
using namespace std;
int main(){
  uint64_t n;
  cin>>n;
  vector<int>a(n+1,0);
  vector<int>b(n+1,0);
  vector<int>A(n);
  vector<int>B(n);
  int curr_a=1;
  int curr_b=1;
  for(int i=0;i<n;i++){
    cin>>A[i];
    for(int j=curr_a;j<A[i];j++){
      a[j]=i;
    }
    curr_a=A[i];
  }
  for(int i=curr_a;i<=n;i++){
    a[i]=n;
  }
  for(int i=0;i<n;i++){
    cin>>B[i];
    for(int j=curr_b;j<B[i];j++){
      b[j]=i;
    }
    curr_b=B[i];
  }
  for(int i=curr_b;i<=n;i++){
    b[i]=n;
  }
  int x=0;
  for(int i=1;i<=n;i++){
    if(a[i]-a[i-1]+b[i]-b[i-1]>n){
      cout<<"No"<<endl;
      return 0;
    }else if(a[i]-b[i-1]>x){
      x=a[i]-b[i-1];
    }
  }
  cout<<"Yes"<<endl;
  for(int i=n-x;i<n;i++){
    cout<<B[i]<<" ";
  }
  for(int i=0;i<n-x;i++){
    if(i<n-x-1){
      cout<<B[i]<<" ";
    }else{
      cout<<B[i];
    }
  }
  cout<<endl;
}
