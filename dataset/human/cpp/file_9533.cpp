#include"bits/stdc++.h"
#include<boost/multi_array.hpp>
#include<boost/optional.hpp>
#include<boost/range/irange.hpp>
#include<boost/range/algorithm.hpp>
#include<boost/range/adaptors.hpp>
using namespace std;
namespace adaptor = boost::adaptors;


#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep3(i,m,n) for(int (i)=m;(i)<=(n);(i)++)
#define rep3rev(i,m,n) for(int (i)=m;(i)>=(n);(i)--)
#define cy cout << "Yes" << endl
#define cn cout << "No" << endl

typedef long long ll;

void Main(){
   int N,M;
   cin >> N >> M;
  vector<string>A(N), B(M);
  rep(i,N)cin>>A[i];
  rep(i,M)cin>>B[i];
   
  // 探索
  // 0,0 から 0,M-N
  // M-N,0 から M-N,M-N
  int flag = 0;
  rep(j,N-M+1){
     rep(k,N-M+1){
        if(A[j].substr(k,M)==B[0]){
           // check(j,k)
           flag=1;
           rep3(i,1,M-1) {
              if(A[j+i].substr(k,M)!=B[i]){
                 flag=0;
                 break;
              }
           }
           if(flag){
              cy;
              return;
           }
        }
     }  
  }
  cn;
  return;
 }
  
int main(){
 cin.tie(nullptr);
 ios_base::sync_with_stdio(false);
 cout << fixed << setprecision(15);
 Main();
 return 0;
 }
