#include<bits/stdc++.h>

long long abs(long long n){
  return (n > 0) ? n : -n;
}

int main(){
  int n;
  long long a;
  long long snuke[200000], arai[200000];
  long long sum = 0, mindiff, temp;

  std::cin >> n;
  for(int i = 0; i < n; i++){
    std::cin >> a;
    sum += a;
    snuke[i] = sum;
  }

  for(int i = 0; i < n; i++) arai[i] = sum - snuke[i];

  mindiff = LLONG_MAX;
  for(int i = 0; i < n-1; i++)
    if(mindiff > (temp = abs(snuke[i]-arai[i])))
      mindiff = temp;

  std::cout << mindiff;

  return 0;
}
