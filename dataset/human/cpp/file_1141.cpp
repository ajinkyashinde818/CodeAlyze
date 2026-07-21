#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main(){
  int R, G, B, N;
  cin >> R >> G >> B >> N;
  long long int count = 0;
  int rmax = N/R;
  for(int r = 0; r <= rmax; r++){
	int n = N - r * R;
    int gmax = n / G;
    for(int g = 0; g <= gmax; g++){
      if((n - g*G) % B == 0){
        count++;
      }
    }
  }
  
  cout << count << endl;
  return 0;
}
