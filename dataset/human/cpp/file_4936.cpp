#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;

int main() {
	/*
	int a = 0;//整数変数aを作る
	int b = 0;//整数変数bを作る

	cin >> a >> b;//2つの数字を受け取り、a,bに代入

	cout << a * b << endl;//a*bを出力
	*/
	/*
	string S;
	cin >> S;
	if (S[0]=='7'||S[1]=='7'||S[2]=='7') {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	
	int a = 0;
	int b = 0;
	int ans = 0;

	cin >> a >> b;

	int apb = a + b;
	int akb = a * b;
	int amb = a - b;
	ans = apb;
	if (ans < a - b) {
		ans = a - b;
	}


	if (ans < a * b) {
		ans = a * b;
	}
	cout << ans << endl;
	*/
	int N = 0;
	int R = 0;
	int Ans = 0;
	cin >> N >> R;
	if (N >=10) {
		Ans = R;
	}
	else
	{
		Ans = R + (100 * (10 - N));
	}

	cout << Ans << endl;
	return 0;
}
