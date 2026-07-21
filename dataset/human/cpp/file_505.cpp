#include<iostream>
#include <algorithm>
#include<string>
#include <bitset>
#include <vector>
#include <functional>
#include <climits>
#include <iomanip>
#include <utility>
#include <stack>
#include <queue>
#include <math.h>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <numeric>
#include <stack>
#include <map> // pair
#include <cstdlib>  // abs() for integer
#include <cmath>    // abs() for float, and fabs()
typedef std::stack<int> IntStack;
typedef std::stack<char> charStack;
#define START 0
#define FORWARD 1
#define BACK 2
using namespace std;
using ll = long long;
typedef pair <ll, ll > pll;
//*********************************************************
// 最大公約数（Greatest Common Divisor）を返す。
// 引数に０がある場合は０を返す。
//*********************************************************
ll gcd(ll a, ll b)
{
	ll tmp, r;
	if (a<b) {
		tmp = a;
		a = b;
		b = tmp;
	}

	/* ユークリッドの互除法 */
	r = a % b;
	while (r != 0) {
		a = b;
		b = r;
		r = a % b;
	}
	return b;
	//// 引数に０がある場合は０を返す
	//if ((0 == m) || (0 == n))
	//	return 0;

	//// ユークリッドの方法
	//while (m != n)
	//{
	//	if (m > n) m = m - n;
	//	else         n = n - m;
	//}
	//return m;
}//gcd
int main()
{
	ll a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, ans = 0;
	ll x[100004] = {};
	ll y[100004] = {};
	ll z[100004] = {};
	string s;
	string s1, s2;
	//IntStack yStack;
	//charStack Stack;
	//vector<pair<int, int> > pairs(a);

	cin >> a;
	cin >> b;
	cin >> c;
	if (a<b)
	{
		e = a;
		a = b;
		b = e;
	}
	if (b<c)
	{
		e = c;
		c = b;
		b = e;
	}

	cin >> d;
	for (int i = 0; i*a <= d; i++)
	{
		for (int k = 0; i*a+k*b <= d; k++)
		{
			if ((d-i*a - k*b)%c==0)
			{
				ans++;
			}
		}
	}

	cout << ans << endl;



	//cout << ans << endl;

	////std::cout << std::fixed;
	//cout << std::setprecision(20) << << endl;
	//cout << d+1 << endl;
	//cout << "" << endl;

	return 0;
}
//sort(x, x + a, std::greater<ll>());

//char型の文字数字は、-'0'で数値に変換できる
//accumulate(x, x + a, 0);//int型までの配列の合計
//memcpy(x, visited, sizeof(ll)*n);
//void kansuu(ll num, ll visited[10]) {}
//kansuu(1, zz);
//cout << setprecision(15) << v << endl;
//cout << char(z - 'a');
//log10(i) + 1 //10進数の桁数を取得
//
//int temp;
//for (int i = 0; i < n - 1; i++) {
//	for (int j = n - 1; j > i; j--) {
//		if (w[j - 1] < w[j]) {  /* 前の要素の方が大きかったら */
//			temp = w[j];        /* 交換する */
//			w[j] = w[j - 1];
//			w[j - 1] = temp;
//		}
//	}
//}
//
//最小公倍数
//ll x = a * b;
//ll tmp;
///* 自然数 a > b を確認・入替 */
//if (a<b) {
//	tmp = a;
//	a = b;
//	b = tmp;
//}
///* ユークリッドの互除法 */
//ll r = a % b;
//while (r != 0) {
//	a = b;
//	b = r;
//	r = a % b;
//}
//a = x / b;//答え
