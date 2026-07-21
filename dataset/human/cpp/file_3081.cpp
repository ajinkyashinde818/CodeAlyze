#include<iostream>
#include<cstdint>
using namespace std; // 575

const int MAX = 100000;
const int INF = 1073741823; // 10^30-1、使わない辺とかに用いる
int main() {
	int N;
	static int A[MAX], mi = INF, neg = 0, zero = 0;
	int64_t sum = 0;
	cin >> N;
	for (int i = 0;i < N;++ i) {
		cin >> A[i];
		if (A[i] < 0) ++ neg;
		mi = min(mi, abs(A[i]));
		sum += abs(A[i]);
	}
	
	if (neg & 1) sum -= mi << 1;
	cout << sum;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

操作によって負数の位置は移動させることができ、偶数個は消すことができる
よって負数が奇数個のとき、最小要素に負を押し付けて終わり！
*/
