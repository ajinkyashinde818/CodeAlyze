#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <functional>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define in(x) cin >> x
#define out(x) cout << x << endl

#define PI acos(-1)
#define pp push_back

#define Yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define No cout << "No" << endl
#define NO cout << "NO" << endl

#define vec2(type) vector<vector<type>>
#define vec3(type) vector<vector<vector<type>>>

#define For(i, n) for(int i = 0; i < n; i++)

#define Tcmp(X, Y) (abs(aryvec[i]->x) == X && abs(aryvec[i]->y) == Y)

template<typename T> void input(T *data, int n){
	For(i, n){
		cin >> data[i];
	}
}

template<typename T> void sort(vector<T> &ary){
	sort(ary.begin(), ary.end());
}

template<typename T> void rsort(vector<T> &ary){
	sort(ary.rbegin(), ary.rend());
}

void rstring(string &str){
	string temp = str;

	For(i, (int)str.size()){
		str[i] = temp[(str.size() - 1) - i];
	}
}

struct Vec{
	int x, y;
	Vec():
	x(0), y(0){}
};

int main(){

	long long n;
	long long *a;

	in(n);
	a = new long long [n];
	input(a, n);

	long long max = 0;

	bool flag = false;

	long long min = abs(a[0]);

	For(i, n){
		max += abs(a[i]);
		if(a[i] < 0){
			flag = !flag;
		}
		if(min > abs(a[i])){
			min = abs(a[i]);
		}
	}

	if(flag){
		max -= min * 2;
	}

	out(max);
	
	return 0;

}
