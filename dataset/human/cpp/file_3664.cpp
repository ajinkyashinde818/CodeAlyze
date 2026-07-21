#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <vector>
#include <stack>
#include <set>

using namespace std;

typedef long long ll;

ll arr[100010];

int main() {
	int n,negat=0;
  	ll sum=0,temp;
  	cin>>n;
  	for (int i=0;i<n;i++){
      cin>>temp;
      arr[i]=abs(temp);
      sum+=arr[i];
      if (temp<0) ++negat;
    }
  	sort(arr,arr+n);
  	if (negat%2) sum-=(2*arr[0]);
    cout<<sum<<endl;
}
