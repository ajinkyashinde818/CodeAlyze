#include <iostream>

using namespace std;

int main(){
  int r,g,b,n;
 cin >> r >> g >> b >>n;
  int res=0;

  for(int i=0;i<=n/r;i++){
    for(int j=0;j<=(n-r*i)/g;j++){
   
      if((n-r*i-g*j)%b==0){
       res++;
      }
      
    }
  }

 cout << res <<endl;

}
