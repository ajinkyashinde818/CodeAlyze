#include<bits/stdc++.h>
using namespace std;
int n,m;
string a[60];
string b[60];
bool match(int x,int y)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[x+i][y+j]!=b[i][j])
                return false;
        }
    }
}

int main()
{
   int i,j;
   cin>>n>>m;

   for(i=0;i<n;i++)
   {
     cin>>a[i];
   }
   for(i=0;i<m;i++)
   {
       cin>>b[i];
   }
   bool f=false;
   for(i=0;i<=n-m;i++)
   {
      for(j=0;j<=n-m;j++)
      {
         if(match(i,j))
            f=true;
      }
   }
   if(f==true)
    cout<<"Yes"<<endl;
   else
    cout<<"No"<<endl;


    return 0;
}
