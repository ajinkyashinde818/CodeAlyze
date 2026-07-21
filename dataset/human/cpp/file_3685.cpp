#include <bits/stdc++.h> 
using namespace std;
long long   n, cnt1, cnt, ans;
int main(){
  cin >> n;
  int a[n], b[n];
  for(int i = 0;i < n; i ++){
    cin >> a[i];
    b[i] = a[i];
      if(a[i] < 0)
      cnt ++;
	  }
      if(cnt % 2 == 1){
      for(int i = 0;i < n; i ++){
        if(b[i] < 0)
        b[i] *= (-1);
		}
        sort(b, b + n);
        int cnt1 = b[0];
        for(int i = 0; i < n; i ++){
          if(b[i] == cnt1)
          continue;
          else 
          ans += b[i];
		  }
          ans -= cnt1;
          cout << ans;
		  }
          else {
            for(int i = 0; i < n;i ++){
              if(a[i] < 0){
              a[i] *= (-1);
			}
              ans += a[i];
			}
              cout << ans;
        }
}
