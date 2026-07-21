#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int> >;
 
int main(){
  int N, R; cin >> N >> R;
  if(N >= 10) cout <<  R << endl;
  else cout << R + 100*(10-N) <<endl;
}
