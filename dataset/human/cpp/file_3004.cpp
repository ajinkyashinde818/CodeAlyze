#include<bits/stdc++.h>
using namespace std;
int main(void){
  int n;
  int min;
  int minnum=0;
  int minuscount=0;
  unsigned long ans=0;
  cin >> n;
  vector<int> a(n);
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(i==0){
      if(a[0]<0){
        a[0]=-1*(a[0]);
        minuscount++;
      }
      min = a[0];
    }else{
      if(a[i]<0){
        a[i]=-1*(a[i]);
        minuscount++;
      }
      if(a[i]<min){
        min = a[i];
        minnum=i;
      }
    }
  }
  for(int i=0;i<n;i++){
      if(i!=minnum){
        ans+=a[i];
      }else{
        if(minuscount%2==1){
          ans-=a[i];
        }else{
          ans+=a[i];
        }
      }
  }

  cout << ans;
  return 0;
}
