#include <iostream>

int main(){
   int R, G, B, N;
   std::cin >> R >> G >> B >> N;

   int ans = 0;
   for(int i=0; i<=N/R; ++i){
      for(int j=0; j<=N/G; ++j){
	 int k= N - R*i - G*j;
	 if(k>=0 && k%B==0) ++ans;
      }
   }
   std::cout << ans << std::endl;
   return 0;

}
