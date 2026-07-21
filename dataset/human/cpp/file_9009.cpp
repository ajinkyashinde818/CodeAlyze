#include <bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  vector<string> origin(a);
  for(int i=0;i<a;i++){
    cin>>origin[i];
  }
  vector<string> cover(b);
  for(int i=0;i<b;i++){
    cin>>cover[i];
  }
  int count1=0,count2=0;
  while(count2<=a-b){
    bool flag=false;
    for(int i=0;i<b;i++){
      for(int j=0;j<b;j++){
        if(cover[i].at(j)!=origin[i+count1].at(j+count2)){
          count1++;
          if(count1==a-b){
            count1=0;
            count2++;
          }
          flag=true;
          break;
        }
        if(i==b-1&&j==b-1){
          cout<<"Yes"<<endl;
          return 0;
        }
      }
      if(flag) break;
    }
  }
  cout<<"No"<<endl;
}
