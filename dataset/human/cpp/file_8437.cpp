#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<string> vs1(50),vs2(50);

int check_ans(int i,int j,int m){
  for(int t=1;t<m;t++){
    if(vs2[t]!=vs1[i+t].substr(j,m))return 0;
  }
  return 1;
}

int main(){
  int n,m;
  cin>>n>>m;
  for(int i=0;i<n;i++)
    cin>>vs1[i];
  for(int i=0;i<m;i++)
    cin>>vs2[i];
  int flag=0;
  for(int i=0;i<=n-m&&flag==0;i++){
    for(int j=0;j<=n-m&&flag==0;j++){
      if(vs2[0]==vs1[i].substr(j,m)){
	flag=check_ans(i,j,m);
      }
    }
  }
  if(flag)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
