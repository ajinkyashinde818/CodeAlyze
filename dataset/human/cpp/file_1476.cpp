#include <iostream>
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <utility>
#include <fstream>
#include <random>
#include <map>
#include <unordered_map>
#include <cstdlib>
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
#define INF 1000000001
#define mod 1000000007
#define p pair<int,int>
#define reverse(s) reverse(s.begin(), s.end());
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
using namespace std;
int POW(int x, int y) { return int(pow(double(x), double(y))); }



int main() {
	int n;
	cin >> n;

	if (n == 1) {
		cout << "Yes" << endl;
		cout << 2 << endl;
		cout << 1 << " " << 1 << endl;
		cout << 1 << " " << 1 << endl;
		return 0;
	}
	int k = 2;
	while (k*k < n*2) {
		if (k*(k + 1) == n*2) {
			cout << "Yes" << endl;
			int a = k + 1;
			int b = k;
			vector<vector<int>> x(a);
			int r = 0;
			int s = 0;
			FOR(i, 1, n + 1) {
				x[r].push_back(i);
				x[s + 1].push_back(i);
				s++;
				if (s == b) {
					if (i == n) {
						break;
					}
					r++;
					s = x[r].size();
				}
			}
			cout << a << endl;
			rep(i, a) {
				printf("%d ", x[i].size());
				rep(j, b) {
					if (j != b - 1) {
						printf("%d ", x[i][j]);
						//cout << x[i][j]<<" ";
					}
					else {
						printf("%d\n", x[i][j]);
						//cout << x[i][j] << endl;
					}
				}
			}
			
			return 0;
		}
		k++;
	}
	cout << "No" << endl;
	return 0;




}
