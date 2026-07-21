#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int R,G,B,N;
  cin >>R>>G>>B>>N;
  int ans=0;
  
 for(int i=0;i<=N;i+=R){
 for(int j=0;i+j<=N;j+=G){
   int a=N-(i+j);
   
   if(a%B==0){if(a>=0){ans++;}} 
 }
 }
  
  cout <<ans<<endl;
}
