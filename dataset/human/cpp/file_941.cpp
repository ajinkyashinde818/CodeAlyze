#include <iostream>

using namespace std;

int main()
{
    int r,g,b,n;
    int cnt = 0;
    cin >> r >> g >> b >> n;
    if(g > r && g > b){
      int tmp = g;
      g = r;
      r = tmp;
    }
    if(b > g && b > r){
      int tmp = b;
      b = r;
      r = tmp;
    }
    for(int i = 0;i <= n / r; i++){
      for(int j = 0;j <= n / g; j++){
        if(r * i + g * j > n){
          break;
        }
        if((n - (r * i + g * j)) % b == 0){
          cnt++;
        }
      }
    }
    cout << cnt << endl;
    return 0;
}
