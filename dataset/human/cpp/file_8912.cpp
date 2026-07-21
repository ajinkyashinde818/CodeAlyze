#include <iostream>
#include <string>
using namespace std;
int main()
{
  int a,b;
  string c[50],d[50];
  cin>>a;
  cin>>b;
  int flag;
  for(int i=0;i<a;i++)cin>>c[i];
  for(int i=0;i<b;i++)cin>>d[i];

for(int i=0;i<=a-b;i++){
  for(int j=0;j<=a-b;j++){
    flag=0;
    for(int k=0;k<b;k++){
      if(c[i+k].substr(j,b)==d[k])flag++;
    }
    if(flag==b){
      cout<<"Yes"<<endl;
      return 0;
    }
  }
}
  cout<<"No"<<endl;
  return 0;
}
