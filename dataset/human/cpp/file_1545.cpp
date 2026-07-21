#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include<climits>
#include<set>
#include<bitset>
#include<random>
using namespace std;

typedef long long ll;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define ff first
#define ss second
#define maxs(a,b) a = max(a,b)
#define mins(a,b) a = min(a,b)
#define rep(i,n) for(int i = 0;i < n;i++)

int main(void){
   int n;scanf("%d",&n);
   int k = 0;
   bool possible = false;
   for(k = 0;k*(k+1) <= 2 * n;k++){
      if(k * (k + 1) == 2* n){possible = true;break;}
   }
   if(!possible){
      cout << "No" << endl;return 0;
   }else{
      cout << "Yes" << endl;
      cout << k + 1 << endl;
   }
   
   vector<int> a[1000];
  int start = 0;
  int block_num = 1;
  for(int i = 0;i < k;i++){
     for(int j = 0;j < block_num;j++){
        a[j].push_back(start + j + 1);
     }
     for(int j = 0;j < block_num;j++){
        a[i + 1].push_back(start + j + 1);
     }
     start += block_num++;
  }
  for(int i = k;i >= 0;i--){
     cout << k << " ";
     for(auto j : a[i]) cout << j << " ";
     cout << endl;
  }
  return 0;
}
