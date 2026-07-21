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
#include <limits>

using namespace std;

#define ll long long

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

template<typename T> void input(T *data, int n){
	For(i, n){
		cin >> data[i];
	}
}

template<typename T> void input(vector<T> &vec, int n){
	T temp;
	For(i, n){
		cin >> temp;
		vec.push_back(temp);
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
	Vec(int _x, int _y):
	x(_x), y(_y){}
};

template<typename T> void print(T *x, int n){
	For(i, n){
		cout << x[i] << " ";
	}
	cout << endl;
}

template<typename T> void print(vector<T> &x){
	For(i, (int)x.size()){
		cout << x[i] << " ";
	}
	cout << endl;
}

int gcd(int n, int m){
	if(n % m == 0){
		return m;
	}
	else{
		return gcd(m, n % m);
	}
}

unsigned ll func(unsigned ll n, unsigned ll i){

	n++;
	if(n >> i == 0){
		return 0;
	}
	unsigned ll num_one = (n / (2 << i)) * (1 << i);

	if((n % (2 << i)) != 0 && (n % (2 << i)) - (1 << i) > 0){
		num_one += (n % (2 << i)) - (1 << i);
	}

	return num_one;

}

int main(){

	int r, g, b, n;
	cin >> r >> g >> b >> n;

	int count = 0;

	int num1, num2;

	for(int i = 0;; i++){
		num1 = r * i;
		if(num1 > n){
			break;
		}
		for(int j = 0;;j++){
			num2 = num1 + g * j;
			if(num2 > n){
				break;
			}
			if((n - num2) % b == 0){
				count++;
			}
		}
	}

	out(count);

	return 0;

}
