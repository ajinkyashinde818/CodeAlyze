#include <cmath>
#include<vector>
#include<iostream>
using namespace std;

long long abs_sub(long long a, long long b){
  return abs(a - b);
}

int main(){
  int n;
  while(cin >> n){
    vector<long> cards;
    long long sum_a = 0;
    long long sum_b = 0;
    long long min = 10e10;
    
    for(int i = 0; i < n; i++){
      int card;
      cin >> card;
      cards.push_back(card);
      sum_b += card;
    }

    for(int i = 0; i < n - 1; i++){
      sum_b -= cards[i];
      sum_a += cards[i];
      long long tmp = abs_sub(sum_a, sum_b);
      min = tmp < min ? tmp : min;
    }

    cout << min << endl;
  }

  return 0;
}
