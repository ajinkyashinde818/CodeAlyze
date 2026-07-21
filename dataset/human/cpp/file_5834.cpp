#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(void){
  int n;
  ll c;
  cin >> n >> c;
  vector<ll> x=vector<ll>(n, 0), v=vector<ll>(n, 0);
  for(int i = 0; i < n; ++i)
    cin >> x[i] >> v[i];
  vector<ll> cal_1, cal_1_max;
  ll max_cal = 0;
  cal_1.push_back(v[0] - x[0]);
  cal_1_max.push_back(cal_1[0]);
  max_cal = max(max_cal, cal_1[0]);
  //cout << cal_1[0] << endl;
  for(int i = 1; i < n; ++i){
    cal_1.push_back(v[i] + cal_1[i-1] - x[i] + x[i-1]);
    cal_1_max.push_back(max(cal_1[i], cal_1_max[i-1]));
    max_cal = max(max_cal, cal_1[i]);
    //cout << cal_1[i] << endl;
  }

  vector<ll> cal_2=vector<ll>(n, 0), cal_2_max=vector<ll>(n, 0);
  cal_2[n-1] = v[n-1] - c + x[n-1];
  cal_2_max[n-1] = cal_2[n-1];
  max_cal = max(max_cal, cal_2[n-1]);
  //cout << cal_2[n-1] << endl;
  for(int i = n-2; i >= 0; --i){
    cal_2[i] = v[i] + cal_2[i+1] + x[i] - x[i+1];
    cal_2_max[i] = max(cal_2[i], cal_2_max[i+1]);
    max_cal = max(max_cal, cal_2[i]);
    //cout << cal_2[i] << endl;
  }

  for(int i = 0; i < n-1; ++i){
    max_cal = max(max_cal, cal_1[i] - x[i] + cal_2_max[i+1]);
  }

  for(int i = n-1; i > 0; --i){
    max_cal = max(max_cal, cal_2[i] - c + x[i] + cal_1_max[i-1]);
  }
  cout << max_cal << endl;
  return 0;
}
