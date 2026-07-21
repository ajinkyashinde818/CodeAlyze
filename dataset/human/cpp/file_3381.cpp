#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i=0; i<n; i++){
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i=0; i<n; i++){
    if (a[i]<0) b[i] = (-1)*a[i];
    else b[i]=a[i];
  }
  int mc=0;
  long long int ac=0;
  for (int i=0; i<n; i++) if(a[i]<0) mc++;
  if (mc%2==0){
    for (int i; i<n; i++){
      ac += b[i];
    }
  }
  else{
    int m;
    m=b[0];
    for (int i=1; i<n; i++){
      m=min(m,b[i]);
    }
    for (int i; i<n; i++){
      ac += b[i];
    }
    ac=ac-2*m;
  }
  cout << ac << endl;
}
