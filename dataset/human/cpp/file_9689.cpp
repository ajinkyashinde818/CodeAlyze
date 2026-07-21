#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
  int n,m;
  cin >> n >> m;
  char a[n][n]={};
  char b[m][m]={};
  string A,B,ans="No";
  for(int i=0;i<n;i++){
	  cin >> A;
	  for(int j=0;j<n;j++){
	  a[i][j]=A[j];
	  }
  }
  for(int i=0;i<m;i++){
	  cin >> B;
	  for(int j=0;j<m;j++){
	  b[i][j]=B[j];
	  }
  }
  for(int i=0;i<=n-m;i++){
	  for(int l=0;l<=n-m;l++){
		  int judge=1;
		  for(int j=0;j<m;j++){
			  for(int k=0;k<m;k++){
				  if(a[j+i][k+l]!=b[j][k]){
					  judge=0;
				  }
			  }
		  }
		  if(judge==0);
		  else if(judge==1) ans="Yes";
	  }
  }
  cout << ans << endl;
}
