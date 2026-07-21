//B-Templete_Matching
#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,j,k,n,m,sum=0,check=0,d,f,loop_count;
  char a[51][51];
  char b[51][51];

  cin>>n>>m;

  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      cin>>a[i][j];
    }
  }

  for(i=0;i<m;i++){
    for(j=0;j<m;j++){
      cin>>b[i][j];
    }
  }

  d=0;
  f=0;
  loop_count=(n-m+1)*(n-m+1);
  for(i=0;i<loop_count;i++){
    for(j=0;j<m;j++){
      for(k=0;k<m;k++){
	if(a[j+d][k+f]==b[j][k]) sum+=1;
	
      }
    }
     if(sum==m*m) check=1;
      sum=0;
    f++;
    if( (f+m)==n){
      f=0;
      d+=1;
    }
  }
  if(check==1) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;


  return 0;
}
