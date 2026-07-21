#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <tuple>

using namespace std;

int solve(int R, int G, int B, int N) {
  int count = 0;
  int rmax = (N / R) + 1;
  int gmax = (N / G) + 1;
  int bmax = (N / B) + 1;

  vector<int> bvec;
  for(int b = bmax-1; b >= 0; b-- ){
    bvec.push_back(N - b * B);
  }

  for(int r = 0; r < rmax; r++){
    if( r * R > N ){ break; }
    for(int g = 0; g < gmax; g++){
      if( r * R + g * G > N ){ break; }

      if(binary_search(bvec.begin(), bvec.end(), r * R + g * G )){
        count++;
      }
    }
  }

  return count;
}

int main(int argc, char const *argv[]) {
  int R, G, B, N;

  cin >> R;
  cin >> G;
  cin >> B;
  cin >> N;

  cout << solve(R, G, B, N);

  return 0;
}
