#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <map>
#include <numeric>
using namespace std;

const int MOD = 1000000007;
typedef long long ll;


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  long long N;
  cin>>N;
  long long K=0;
  for(int i=0;i<N;i++){
    if(i*(i+1)/2==N){
      K=i;
      break;
    }
  }
  if(N==1){
    cout<<"Yes"<<endl;
    cout<<2<<endl;
    cout<<"1 1"<<endl;
    cout<<"1 1"<<endl;
  }else{
    if(K==0){
      cout<<"No"<<endl;
    }else{
      cout<<"Yes"<<endl;
      cout<<K+1<<endl;
      vector<vector<long long> > res(K+1, vector<long long>());
      long long sum = 1;
      for (int k = K; k >= 1; --k) {
        for (int i = 0; i < k; ++i) {
          res[K-k].push_back(sum + i);
          res[K-k + i + 1].push_back(sum + i);
        }
        sum += k;
      }

      for (int i = 0; i < K+1; ++i) {
        cout << res[i].size();
        for (int j = 0; j < res[i].size(); ++j) cout << " " << res[i][j];
        cout << endl;
      }
    }
  }
}
