#include <iostream>
#include <vector>
#include <algorithm>

int main(){
   int N;
   std::cin >> N;
   std::vector<int> a(N);
   long long sum = 0;
   long long suma[N];
   for(int i=0; i<N; ++i){
      std::cin >> a[i];
      if(i==0) suma[i] = a[i];
      else suma[i] = suma[i-1] + a[i];
      sum += a[i];
   }
   long long ans = suma[0]*2 - sum;
   if(ans<0) ans *= -1;
   for(int i=1; i<N-1; ++i){
      long long tmp = suma[i]*2 - sum;
      if(tmp<0) tmp *= -1;
      ans = std::min(ans,tmp);
   }
   std::cout << ans << std::endl;
   return 0;
}
