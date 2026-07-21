#include <iostream>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <math.h>
using namespace std;

typedef pair<int, int> P;
#define ll long long
#define int ll
#define INF (1LL<<60)
#define mod 1000000007
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { 1, 0, -1, 0 };


signed main(){

	int n;
	cin >> n;

	bool yes = false;
	int k;
	for (k = 1; k*(k-1)/2 <= n; k++){
		if (k*(k - 1) / 2 == n){
			yes = true;  break;
		}
	}
	if (!yes){
		cout << "No" << endl;
		return 0;
	}

	// a[k][k]
	int **a = new int*[k];
	for (int i = 0; i < k; i++)
		a[i] = new int[k];

	for (int i = 0; i < k; i++) for (int j = 0; j < k; j++) a[i][j] = 0;

	int c = 1;
	for (int i = 0; i < k; i++){
		for (int j = i+1; j < k; j++){
			a[i][j] = a[j][i] = c;
			c++;
		}
	}

	cout << "Yes" << endl;
	cout << k << endl;
	for (int i = 0; i < k; i++){
		cout << k - 1 << " ";
		for (int j = 0; j < k; j++){
			if (a[i][j] != 0) cout << a[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
