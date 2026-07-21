#include<iostream>
using namespace std;
int main(){
 int m,n,f=0;
 char a[51][51],b[51][51];
 cin>>n>>m;
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)cin>>a[i][j];
 for(int i=0;i<m;i++)
  for(int j=0;j<m;j++)cin>>b[i][j];
                
 for(int i=0;i<n;i++){/*bの左上と一致する場所を調べる*/
  if(f==1)break;
  for(int j=0;j<n;j++){
   if(f==1)break;
   if(a[i][j]==b[0][0]){/*一致した*/
    int f2=0;
    if(i+m<=n&&j+m<=n)
     for(int l=0;l<m;l++){/*ｂの画像と一致するかどうか*/
      if(f2==1)break;
      for(int k=0;k<m;k++)
       if(a[i+l][j+k]==b[l][k])f=1;
       else if(a[i+l][j+k]!=b[l][k]){f=0;f2=1;break;}
      }
    }
  }
 }   
 if(f==1)cout<<"Yes"<<endl;
 else cout<<"No"<<endl;
 return 0;
}
