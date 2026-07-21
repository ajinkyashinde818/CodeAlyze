#include<bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  long long tmp, ans=0, minabs=1e9, mincnt=0;
  for (int i=0; i<N; i++) {
    cin >> tmp;
    ans+=abs(tmp);
    minabs = min(minabs, abs(tmp));
    if (tmp<0) mincnt++;
  }
  if(mincnt%2==0) cout << ans << "\n";
  else cout << ans-2*minabs << "\n";
}
