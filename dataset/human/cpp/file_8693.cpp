#include<iostream>
#include<string>

using namespace std;

int main(){
 int n,m;
  cin >> n >> m;
 string a[n],b[m];
 
  for(int i=0;i<n;i++) cin >> a[i];
  for(int i=0;i<m;i++) cin >> b[i]; 
  
  
    bool res=false;
    for(int i=0;i<n-m+1;i++){
   for(int j=0;j<n-m+1;j++){
      bool dis=true;
     for(int k=0;k<m;k++){
     if(a[i+k].substr(j,m)!=b[k]) dis=false;
    }
     if(dis) {
       res=true;
      break;
     }
     }
  }

  if(res) cout << "Yes" << endl;
  else cout << "No" << endl;

}
