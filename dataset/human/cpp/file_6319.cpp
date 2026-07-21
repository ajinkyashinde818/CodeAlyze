#include <iostream>

const int MOD = 1000000007;

int main(){
   int N;
   std::cin >> N;
   std::string S;
   std::cin >> S;

   long long ans = 1;
   long long left = 0;
   for(int i=0; i<N*2; ++i){
      if(left%2==1) S[i] = (S[i]=='B' ? 'W' : 'B');
      if(S[i]=='B') ++left;
      else ans = ans * (left--) % MOD;
   }
   if(left==0) {
      for(int i=1; i<=N; ++i) ans = ans * i % MOD;
      std::cout << ans%MOD << std::endl;
   } else {
      std::cout << 0 << std::endl;
   }

   return 0;

}
