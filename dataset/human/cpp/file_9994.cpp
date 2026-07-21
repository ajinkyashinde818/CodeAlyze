//
// Created by Naman Bhalla on 2019-03-23.
//

#include <cstdio>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main(){
  	int n{0};
  	string s{};

  cin >> n >> s;

  long long int charsa[26] {};

  for(auto chars: s){
    charsa[chars - 'a']++;
  }

  long long int answer {1};

  for(auto vals: charsa){
  	answer *= (vals + 1);
  	answer= answer % (1000000007LL);
  }

  printf("%lld\n", answer -1);

 	return 0;
}
