#include <bits/stdc++.h>
using namespace std;
std::vector<int> a[3000];
int main() {

  int n ;
  cin >> n ;
  int cnt = 0 ;
  while ( ((cnt) * (cnt - 1 ) / 2)  < n )
    cnt++;

  if (  ((cnt) * (cnt - 1 ) / 2)  > n) {
    cout << "No";
    return 0 ;
  }
  int pnt = 1 ;
  for (int i = 0; i < cnt; ++i)
  {
    for (int j = i + 1; j < cnt; ++j)
    {
      a[i].push_back(pnt);
      a[j].push_back(pnt);
      pnt++;
    }
  }
  cout << "Yes\n";
  cout << cnt << endl;
  for (int i = 0; i < cnt; ++i)
  {
    cout << a[i].size() << " ";
    for (int j = 0; j < a[i].size(); ++j)
    {
      cout << a[i][j] << (( j == a[i].size() -1 )?  "": " ");
    } 
    cout << endl;
  }

}
