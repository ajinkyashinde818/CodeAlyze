#include <bits/stdc++.h>
 
using namespace std;
inline void prep ()
{
  cin.tie (0);
  cin.sync_with_stdio (0);
};
// 32 mil = ~1 sec 
long long mod = 1e9+7;
const int biggg = 1000000001;
const long long bigggest = 1000000000000000000LL;
const double eps = .0000000001;

int main(){
    prep();
    int n;
    cin >> n;
    int startind[n+1];
    memset(startind, -1, sizeof(int)*(n+1));
    int a[n];
    for (int i=0; i<n; i++) cin >> a[i];
    int b[n];
    for (int i=0; i<n; i++) cin >> b[i];
    int maxpush = 0;
    for (int i=0; i<n; i++){
    	startind[a[i]] = i;
	}

	for (int i=0; i<n; i++){
		if (i > 0 && b[i] == b[i-1]) continue;
		if (startind[b[i]] == -1) continue;
		if (startind[b[i]] >= i){
			maxpush = max(maxpush, (startind[b[i]]-i+1)%n);
		}
	}
	//cout << maxpush << '\n';
	int newarr[n];
	for (int i=maxpush; i<n; i++){
		newarr[i] = b[i-maxpush];
	}
	for (int i=0; i<maxpush; i++){
		newarr[i] = b[i+n-maxpush];
	}
	string printt = "";
	for (int i=0; i<n; i++){
		if (newarr[i] == a[i]){
			cout << "No";
			return 0;
		}
		printt += to_string(newarr[i]);
		printt += " ";
	}
	cout << "Yes\n" << printt;
	/*6
	1 2 2 3 4 4
	1 2 2 2 3 3*/
	
	//3 3 1 2 2 2
    return 0;
}
