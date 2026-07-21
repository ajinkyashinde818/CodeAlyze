#include<bits/stdc++.h>
using namespace std;
int main(){
int R,G,B,N;
  cin>>R>>G>>B>>N;
  
  int ans=0;
  for(int i=0;i<=N/R;i++){
    int a=N-i*R;
  for(int j=0;j<=a/G;j++){
  if((a-G*j)%B==0)
    ans++;
  
  }
 }cout<<ans<<endl;
   return 0;
}
