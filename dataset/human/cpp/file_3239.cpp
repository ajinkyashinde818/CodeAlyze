#include <iostream>
#include <vector>
#include <algorithm>

int main(){
  	int n;
  	std::cin >> n;
  	std::vector<long long> a(n);
  	int minus=0;
  	long long sum=0;
  	long long min=10000000000ll;
  	for(auto&e:a){
      	std::cin >> e;
      	sum+=std::abs(e);
      	min = std::min(std::abs(e), min);
      	if(e<0)minus++;
    }
  	if(minus%2==0) std::cout << sum << "\n";
  	else std::cout << sum-2*min << "\n";
  	return 0;
}
