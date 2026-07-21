#include <iostream>

typedef long long ll;

const ll Div = 1000000007;

int main(){
   ll N;
   std::cin >> N;
   std::string S;
   std::cin >> S;


   ll sum = 1;
   for(char ch='a'; ch<='z'; ++ch){
      ll count = 0;
      for(int i=0; i<N; ++i){
	 if(S[i]==ch) ++count;
      }
      sum *= count+1;
      sum %= Div;
   }
   if(sum>0) sum--;
   else sum = Div-1;
   std::cout << sum%Div << std::endl;

   return 0;
}
