#include<iostream>
using namespace std;
int main(){
  int n,m; cin >> n >> m;
  char a[55][55];
  char b[55][55];
  for(int y=0;y<n;y++){
    for(int x=0;x<n;x++) cin >> a[y][x];
  }
  for(int y=0;y<m;y++){
    for(int x=0;x<m;x++) cin >> b[y][x];
  }
  
  bool ans = false;
  // Bの平行移動を考える.
  for(int dy=0;dy<n;dy++){
    for(int dx=0;dx<n;dx++){
      // BがAから出てしまう場合.
      if(dy+m-1>n-1 || dx+m-1>n-1) continue;
      
      bool match = true;
      for(int y=0;y<m;y++){
        for(int x=0;x<m;x++){
          if(a[dy+y][dx+x]!=b[y][x]) match = false;
        }
      }
      //この平行移動でAとBが一致したかどうか
      if(match) ans = true;
    }
  }
  if(ans) cout << "Yes" << endl;
  else cout << "No" << endl;
  
  return 0;
}
