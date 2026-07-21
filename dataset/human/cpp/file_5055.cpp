#include<bits/stdc++.h>
using namespace std;

inline long long read(){
	long long s = 0, w = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9'){
		if (ch == '-') w = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9'){
		s = s * 10 + ch - '0';
		ch = getchar();
	}
	return s * w;
}

int main(){
	int n = read(), m = read();
	if (n >= 10){
		cout << m;
		return 0;
	}
	cout << m + 100 * (10-n);
	return 0;
}
