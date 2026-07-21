#include <iostream>
using namespace std;

int main(){
  int N, R;
  int rate;

  cin >> N;
  cin >> R;

  if(N <= 10 && N >=1 ){
    rate = R+(100*(10-N));
    cout << rate << '\n';
  }else if(N > 10 && N <= 100){
    rate = R;
    cout << rate << '\n';
  }
  return 0;
}
