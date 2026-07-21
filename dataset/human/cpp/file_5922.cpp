#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

ll N, C;
vector<pll> A;
vector<ll> CW[2], CCW[2];

void printAll(){
  cout << "A[0]: ";
  for(int i=0; i<N; i++){
    cout << A[i].first << " ";
  }
  cout << endl;
  cout << "A[1]: ";
  for(int i=0; i<N; i++){
    cout << A[i].second << " ";
  }
  cout << endl;
  cout << "CW[0]: ";
  for(int i=0; i<=N; i++){
    cout << CW[0][i] << " ";
  }
  cout << endl;
}

int main(){
  cin >> N >> C;
  //cout << N << ", " << C << endl;
  A.resize(N);
  for(int i=0; i<2; i++){
    CW[i].resize(N+1);
    CCW[i].resize(N+1);
  }
  for(int i=0; i<N; i++){
    cin >> A[i].first >> A[i].second;
  }

  sort(A.begin(), A.end());
  for(int i=0; i<N; i++){
    CW[0][i+1] = CW[0][i] + A[i].second;
    CW[1][i+1] = CW[0][i+1];
  }
  //printAll();
  for(int i=0; i<N; i++){
    CW[0][i+1] -= A[i].first;
    CW[1][i+1] -= 2*A[i].first;
  }
  //printAll();
  for(int i=0; i<N; i++){
    CW[0][i+1] = max(CW[0][i+1], CW[0][i]);
    CW[1][i+1] = max(CW[1][i+1], CW[1][i]);
  }
  //printAll();

  for(int i=0; i<N; i++){
    CCW[0][i+1] = CCW[0][i] + A[N-i-1].second;
    CCW[1][i+1] = CCW[0][i+1];
  }
  for(int i=0; i<N; i++){
    CCW[0][i+1] -= (C-A[N-i-1].first);
    CCW[1][i+1] -= 2*(C-A[N-i-1].first);
  }
  for(int i=0; i<N; i++){
    CCW[0][i+1] = max(CCW[0][i+1], CCW[0][i]);
    CCW[1][i+1] = max(CCW[1][i+1], CCW[1][i]);
  }

  ll best = 0;
  for(int i=0; i<=N; i++){
    best = max(best, CW[0][i] + CCW[1][N-i]);
    best = max(best, CW[1][i] + CCW[0][N-i]);
  }
  cout << best << endl;

  return 0;
}
