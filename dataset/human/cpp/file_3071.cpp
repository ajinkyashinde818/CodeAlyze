#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int n;
  
  cin >> n;
  
  int a[n];
  for (int i=0;i<n;++i) {
    cin >> a[i];
  }
  
  unsigned int min_a = 0xffffffff;
  int min_index = n-1;
  for (int i=0;i<n-1;++i) {
    if (a[i] < 0) {
      a[i] *= -1;
      a[i+1] *= -1;
    }
    
    if (a[i] > 0) {
      if (a[i] < min_a) {
        min_a = a[i];
        min_index = i;
      }
    }
  }
  //cout << min_a << ',' << min_index << endl;
  
  int index = n-1;
  if (a[n-2] > 0 && a[n-1] > 0) {
  } else {
    if (a[n-1] < 0) {
      if (abs(a[n-2]) < abs(a[n-1])) {
        a[n-2] *= -1;
        a[n-1] *= -1;
        index = n-2;
      } else {
        index = n-1;
      }
    } else {
      index = n-1;
    }
    
	if (index > min_index) {
      if (abs(a[index]) > abs(a[min_index])) {
        a[index] *= -1;
        a[min_index] *= -1;
      }
    }
  }
  
  
  long long ans = 0;
  for (int i=0;i<n;++i) {
    ans += a[i];
    //cout << a[i] << endl;
  }
  
  cout << ans << endl;

  return 0;
}
