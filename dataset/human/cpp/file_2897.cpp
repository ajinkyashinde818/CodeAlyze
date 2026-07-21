#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,i,kosuu=0,min=1000000001,max=-1000000001;
  cin >> n;
  long int a[n],kotae=0;
  for(i=0;i<n;i++){
    cin >> a[i];
    kotae+=a[i];
    if(a[i]<0){
      kosuu++;
      kotae-=2*a[i];
      a[i]=(-1)*a[i];
    }
    if(a[i]<min){
      min=a[i];
    }
  }
  kotae=kotae-2*(kosuu%2)*min;
  printf("%ld",kotae);
}
