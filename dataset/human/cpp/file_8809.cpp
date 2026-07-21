#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,m,dif;
  cin >> n >> m;
  dif = n - m + 1;
  vector<string> A(n),B(m);
  for(int i = 0; i < n; i++)cin >> A.at(i);
  for(int i = 0; i < m; i++)cin >> B.at(i);  
  int flag = 0;
  int ans = 0;
  for(int i = 0; i < dif; i++){//x座標のずれ
    for(int j = 0; j < dif; j++){//y座標のずれ
      //全文字一致するか確認
      flag = 0;
      for(int k = 0; k < m; k++){
        for(int l = 0; l < m; l++){
          if(A.at(l+j).at(k+i)!=B.at(k).at(l)){
            flag = 1;
            break;
          }
        }
        if(flag)break;
      }
      if(flag)continue;
      else{
        ans = 1;
        break;
      }
    }
    if(ans)break;
  }
  if(ans)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
  return 0;
}
