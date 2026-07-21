#include<iostream>
#include<algorithm>
using namespace std;
int N_MAX = 200001;
int main()
{
  int n,i,j,c=0;
  int a[N_MAX],b[N_MAX],ca[N_MAX],cb[N_MAX];
  cin >> n;
  fill(ca+1,ca+n+1,0);
  fill(cb+1,cb+n+1,0);
  for(i=0;i<n;i++){
    cin >> a[i];
    ca[a[i]]++;
  }
  for(i=0;i<n;i++){
    cin >> b[i];
    cb[b[i]]++;
  }
  for(i=1;i<=n;i++)
    if(ca[i]+cb[i]>n){
      cout << "No" << endl;
      return 0;
    }
  cout << "Yes" << endl;
  for(i=0;i<n;i++){
    if(a[i]!=b[i])
      continue;
    if(b[i]!=c){
      j=0;
      c=b[i];
    }
    for(;j<n;j++)
      if(a[j]!=c&&b[j]!=c){
        b[i]=b[j];
        b[j]=c;
        j++;
        break;
      }
  }
  for(i=0;i<n;i++)
    cout << b[i] << " ";
  cout << endl;
  return 0;
}
