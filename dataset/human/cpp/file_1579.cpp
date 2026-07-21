#include<bits/stdc++.h>
using namespace std;
using LL=long long;
int mp[1000][1000];
void fill(int N,int s,int x,int y){
  int n=N;
  if(s<=3){
    if(s==1){
      for(int j=0;j<=1;j++)
        mp[x+j][y]=n;
    }
    if(s==2){
      for(int j=0;j<=2;j++){
        for(int k=0;k<s;k++){
          mp[x+j][y+k]=n++;
        }
        n--;
        if(j==2)mp[x+j][y+s-1]=N;
      }
    }
    if(s==3){
      for(int j=0;j<=2;j++){
        for(int k=0;k<s;k++){
          mp[x+j][y+k]=n++;
        }
        n--;
        if(j==2)mp[x+j][y+s-1]=N;
      }
      for(int k=0;k<s;k++)
        mp[x+3][y+k]=N+1+2*k;
    }
    return;
  }
  for(int j=0;j<=2;j++){
    for(int k=0;k<s;k++){
      mp[x+j][y+k]=n++;
    }
    n--;
    if(j==2)mp[x+j][y+s-1]=N;
  }
  for(int j=3;j<=s;j++){
    for(int k=0;k<3;k++)
      mp[x+j][y+k]=(N+1)+k*(s-1)+j-3;
  }
  return fill(n,s-3,x+3,y+3);
}
int main(){
  int N;
  cin>>N;
  if(N==2){
    printf("No\n");
    return 0;
  }
  int s=sqrt(N*2);
  if(s*(s+1)==N*2);
  else if(s*(s-1)==N*2)s--;
  else if((s+1)*(s+2)==N*2)s++;
  else if((s-1)*(s-2)==N*2)s-=2;
  else{
    cout<<"No"<<endl;
    return 0;
  }
  fill(1,s,0,0);
  cout<<"Yes"<<endl<<s+1<<endl;
  for(int j=0;j<s+1;j++){
    cout<<s;
    for(int k=0;k<s;k++)
      cout<<' '<<mp[j][k];
    cout<<endl;
  }
}
