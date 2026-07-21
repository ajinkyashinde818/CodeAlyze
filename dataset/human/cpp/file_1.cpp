#include<bits/stdc++.h>
using namespace std;
int main(){
int R,G,B,N;
cin>>R>>G>>B>>N;
int ans = 0;
for(int r=0;r<N/R+2;r++){
  for(int g=0;g<N/G+2;g++){
    int X=N-G*g-R*r;
    if(X==0){
      ans++;
    }
    else if(X>0&&X%B==0){
      ans++;
    }
  }
}
cout<<ans;
}
