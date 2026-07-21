#include <iostream>
#include <algorithm>
using namespace std;

long long l(long long z)
{
 if(z < 0) return -z;
 else return z;
}

int main()
{
 int N;
 int A[100000+5];
 long long ans = 0;
 cin >> N;
 for(int i = 0; i < N; i++) cin >> A[i];
 bool fa = true;
 bool f0 = false;
 int o0 = 0;//プラスの数
 long long minA = 1LL << 60; //絶対値の最小値
 //数列が全て正
 for(int i = 0; i < N; i++){
  if(A[i] < 0) fa = false;
 }
 if(fa == true){
  for(int i = 0; i < N; i++) ans += A[i];
  cout << ans;
  return 0;
 }
 else{
  //数列に0がある
  for(int i = 0; i < N; i++){
   if(A[i] == 0) f0 = true; 
  }
  if(f0){
   for(int i = 0; i < N; i++) ans += l(A[i]);
   cout << ans;
   return 0;
  }
  //偶奇判定
  else
  {
   for(int i = 0; i < N; i++){
    if(A[i] > 0) o0++;
   }
   //nが偶数
  // if(N%2 == 0){
    if((N-o0)%2 == 0){
     for(int i = 0; i < N; i++) ans += l(A[i]);
     cout << ans;
     return 0;
    }
    else{
     for(int i = 0; i < N; i++) minA = min(l(A[i]),minA);
     for(int i = 0; i < N; i++) ans +=l(A[i]);
     ans -= 2*minA;
     cout << ans;
     return 0;
    }
   }
 // }
 }
 return 0;
}
