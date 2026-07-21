#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<map>
#include<vector>
#include<queue>
#include<climits>
#include<set>
#include<utility>
using namespace std;
typedef long long int ll;

int main(){

	ll n, a[200000], arai=0, sunuke=0, diff=1e15;
	cin >> n;
	for(int i=0; i<n; i++){
		cin >> a[i];
		arai+=a[i];
	}

	for(int i=0; i<n-1; i++){
		sunuke+=a[i];
		arai-=a[i];
		diff=min(diff, abs(sunuke-arai));
	}
	cout << diff << endl;

	return 0;
}
