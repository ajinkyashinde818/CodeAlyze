#include <iostream>
#include <cmath>
#include <cstdlib> 
 
using namespace std;
int main(){
	int N = 0;
  	long long ans = 0;
	cin >> N;
	long long  minA = 10000000000;
  	long long  a = 0;
	int nNegative = 0;
  	for(int i=0; i < N; ++i){
		cin >> a;
      	long long absA = std::abs(a);
      	if(a < 0) ++nNegative;
      	if(absA < minA) minA = absA;
		ans += absA;
    }
  
	if(nNegative%2) ans -= 2 * minA;
      
    cout << ans;
	return 0;
}
