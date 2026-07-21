#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	int a[100000];
  int z[100000];
  bool sign[100000];
  int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
    z[i] = abs(a[i]);
    if(a[i] >= 0){
      sign[i] = 0;
    }else{
      sign[i] = 1;
      count++;
    }
	}

  if(count%2 == 0){
    ll sum=0;
    for(int i=0;i<n;i++){
      sum+=z[i];
    }
    cout<<sum;
  }else{
    ll sum=0;
    int min=INT_MAX;
    for(int i=0;i<n;i++){
      sum+=z[i];
      if(min>z[i]){
        min=z[i];
      }
    }
    sum -= min*2;
    cout << sum;
  }
	return 0;
}
