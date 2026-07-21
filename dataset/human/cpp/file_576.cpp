#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<functional>


using namespace std;

class Main{
public:
  void input();
  void run();

private:
  int R;
  int G;
  int B;
  int N;
  vector<int> v;
};


void Main::input(){
  cin >> R >> G >> B >> N;
  v.emplace_back(R);
  v.emplace_back(G);
  v.emplace_back(B);
  sort(v.begin(), v.end(), greater<int>());
  return;
}


void Main::run(){
  int sum = 0;
  for( int i = 0; i <= N; i+=v[0] ){
    for( int j = 0; i+j <= N; j+=v[1] ){
      int c = (N-i-j) % v[2];
      if( c == 0 ){ ++sum; }
      // cout << i << "," << j << "," << c << endl;
    }
  }
  cout << sum << endl;
  return;
}






int main(){
  Main m;
  m.input();
  m.run();
  return 0;
}
