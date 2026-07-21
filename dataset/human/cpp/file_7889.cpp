#include <iostream>
#include <algorithm>
using namespace std;

int a[200010];

int main () {

int n;
cin>>n;
long long int zbr=0;
for (int i=0; i<n; i++) {
	cin>>a[i];
	zbr+=a[i];
}
long long int mini=200000000000001;
long long int br=0;
for (int i=0; i<n-1; i++) {
	br+=a[i];
	if (abs(br-(zbr-br))<mini) {mini=abs(br-(zbr-br));}
}
cout<<mini;

return 0;
}
