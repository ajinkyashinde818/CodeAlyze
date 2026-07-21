#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m;
  char a[50][50], b[50][50];
  cin >> n >> m;
  for(int x=0;x<n;x++) 
    for(int y=0;y<n;y++) 
      cin >> a[x][y];
  for(int x=0;x<m;x++) 
    for(int y=0;y<m;y++) 
      cin >> b[x][y];
  bool exit = false;
  for(int x=0;x<=n-m && !exit;x++){
    for(int y=0;y<=n-m && !exit;y++){
      bool f = true;
      for(int dx=0;dx<m && f;dx++){
        for(int dy=0;dy<m && f;dy++){
          if(b[dx][dy] != a[x+dx][y+dy]) f = false;
        }
      }
      if(f) exit = true;
    }
  }
  cout << (exit?"Yes":"No") << endl;
}
