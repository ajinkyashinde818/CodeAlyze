#include<iostream>
#include<string>
#include<vector>
using namespace std;

int A[50][50];
int B[50][50];

bool check(int i,int j,int N,int M){
  for(int k=0;k<M;k++)
    for(int l=0;l<M;l++)
      if(A[i+k][j+l]!=B[k][l])
	return false;
  return true;
}

int main(){
  int N,M;
  cin>>N>>M;
  string str;
  
  for(int i=0;i<N;i++){
    cin>>str;
    for(int j=0;j<N;j++)
      if(str[j]=='#')
	A[i][j]=1;
  }
  for(int i=0;i<M;i++){
    cin>>str;
    for(int j=0;j<M;j++)
      if(str[j]=='#')
	B[i][j]=1;
  }
  int matchFlg=false;
  for (int i=0;i<N;i++)
    for(int j=0;j<N;j++)
      if(check(i,j,N,M))
	matchFlg=true;
  if(matchFlg)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
