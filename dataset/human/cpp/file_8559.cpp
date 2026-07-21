#include<bits/stdc++.h>
using namespace std;
int main()
{	int a,b;
  cin>>a>>b;bool ok=true;
 char A[a][a];char B[b][b];
 for(int i=0;i<a;i++)
   for(int j=0;j<a;j++)cin>>A[i][j];
 for(int i=0;i<b;i++)
   for(int j=0;j<b;j++)cin>>B[i][j];
 for(int i=0;i<a-b;i++)
 {
   for(int j=0;j<a-b;j++)
   {	ok =true;
     for(int k=0;k<b;k++)
     {
       for(int l=0;l<b;l++)
       {
         	ok=ok & (A[i+k][j+l] == B[k][l]);
       }
     }
    if(ok)break;
   }
   if(ok)break;
 }
 if(ok)cout<<"Yes";
 else cout<<"No";
}
