#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N;
  cin >> N;

  string S;
  cin >> S;

  vector<bool> field(2 * N + 2);
  field[0] = field[2 * N + 1] = false;
  for(int i = 1; i <= 2 * N; i++){
    if(S[i - 1] == 'B'){
      field[i] = true;
    }
  }

  vector<bool> op(2 * N, false); // true for ')'
  for(int i = 0; i < 2 * N; i++){
    bool cond1 = false;
    if(i > 1 && op[i - 1] == true){
      cond1 = true;
    }
    bool cond2 = (field[i] == field[i + 1]);
    if(cond1 == cond2){
      op[i] = false;
    }else{
      op[i] = true;
    }
  }

  int left_cnt = 0, right_cnt = 0;
  for(auto b: op){
    if(b){
      right_cnt++;
    }else{
      left_cnt++;
    }
  }
  if(left_cnt != right_cnt){
    cout << 0 << endl;
    return 0;
  }

  const long long mod = 1e9 + 7;
  long long ans = 1;
  for(int i = 1; i <= N; i++){
    ans *= i;
    ans %= mod;
  }
  long long left_cnt_now = 0;
  for(auto b: op){
    if(b == false){
      left_cnt_now++;
    }else{
      ans *= left_cnt_now;
      left_cnt_now--;
      ans %= mod;
    }
  }
  cout << ans << endl;

}
