#include <cstdio>
#include <cstdlib>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <iostream>
#include <limits>
#include <climits>
#include <functional>
#include <numeric>

using namespace std;

#define alloc(type,n) (type*)calloc(sizeof(type),(n));
typedef long long lli;

int n,m;
char a[55][55];
char b[55][55];

bool check(int x,int y){
	for(int i = 0;i < m;i++){
		for(int j = 0;j < m;j++){
			if(a[i+x][j+y] != b[i][j]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	cin >> n >> m;
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	for(int i = 0;i < m;i++){
		cin >> b[i];
	}
	for(int i = 0;i <= n-m;i++){
		for(int j = 0;j <= n-m;j++){
			if(check(i,j)){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
