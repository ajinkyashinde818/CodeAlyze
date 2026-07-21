#include<iostream>
using namespace std;

const int MAX = 447; // 447*448/2=99681, 448*449/2=100576
int main() {
	int N;
	cin >> N;
	int K = 1, T[MAX]; // T[i]=i(i+1)/2
	for (int i = 0;i < MAX;++ i) T[i] = i * (i + 1) >> 1;
	for (int max = MAX, mid = max >> 1;max - K > 1;mid = K + (max - K >> 1)) { // T[K]=NとなるようなKを二分探索
		if (T[mid] > N) max = mid;
		else K = mid;
	}
	if (T[K] != N) { // 不可能
		cout << "No";
		return 0;
	}
	cout << "Yes" << endl << K + 1 << endl;
	for (int i = 0;i <= K;++ i) {
		cout << K;
		for (int j = 0;j < K;++ j) cout << " " << (i > j ? i - j : j - i + 1) + T[K] - T[K - min(i, j)];
		cout << endl;
	}
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

まず、最初にkとS_1を決めたとする
するとS_2からS_kまでの全てにはS_1の要素が1個含まれるので、k=|S_1|+1になる
同様の話が他でも成り立つので、|S_1|=|S_2|=...=|S_k|
で、そもそも|S_1|+|S_2|+...+|S_k|は、全ての要素が2個ずつ出てくるので2Nでないといけない→|S_i|=k+1なのでk(k+1)=2N
よってk=N(N+1)/2が成り立つ(そうでなければ-1)
後は構築だが、これはかなり簡単
自分より上の全てのS_iのうち使ってないの1個と、まだ使ってない数字を残りの個数だけ使っていけば良いだけ
例えばN=15ならこんな感じ
1 2 3 4 5
1 6 7 8 9
2 6 10 11 12
3 7 10 13 14
4 8 11 13 15
5 9 12 14 15
*/
