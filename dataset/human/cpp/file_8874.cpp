#include<iostream>
#include<string>
using namespace std;
int N_MAX = 50;
int main()
{
  int n,m,i,j,k,l;
  bool f;
  string a[N_MAX],b[N_MAX];
  cin >> n >> m;
  for(i=0;i<n;i++)
    cin >> a[i];
  for(i=0;i<m;i++)
    cin >> b[i];
  for(i=0;i<n-m+1;i++)
    for(j=0;j<n-m+1;j++){
      f=1;
      for(k=0;k<m;k++){
        for(l=0;l<m;l++)
          if(a[k+i][l+j]!=b[k][l]){
            f=0;
            break;
          }
        if(f==0) break;
      }
      if(f==1){
        cout << "Yes" << endl;
        return 0;
      }
    }
  cout << "No" << endl;
  return 0;
}
