#include <iostream>
#include <array>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;

typedef  pair<int,int> P;
typedef long long LL;

const LL  INF=1<<31;
const LL MOD=1000000007;



int main(){
     int m,n;
     cin>>n>>m;
     string a[55];
     string b[55];
     for(int i=0;i<n;++i)cin>>a[i];
     for(int i=0;i<m;++i)cin>>b[i];

     bool han=false;
     
     for(int i=0;i<n-m+1;++i){
          for(int j=0;j<n-m+1;++j){
               bool han2=true;
               for(int k=0;k<m;++k){
                    for(int l=0;l<m;++l){
                         if(b[k][l]!=a[i+k][j+l]){
                              han2=false;
                         }
                    }

               }
               if(han2){
               han=true;
               }
          }
     }
     if(han)cout<<"Yes"<<endl;
     else cout<<"No"<<endl;
}
