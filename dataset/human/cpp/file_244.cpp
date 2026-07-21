#include<iostream>
using namespace std; // 575

int main() {
	int R, G, B, N, ans = 0;
	cin >> R >> G >> B >> N;
	for (int r = 0;r <= N;++ r) {
		for (int g = 0;g <= N;++ g) {
			if (r * R + g * G <= N && (N - r * R - g * G) % B == 0) ++ ans;
		}
	}
	cout << ans;
	return 0;
}
/*
31536000のコメント解説欄
ここテンプレで用意してるから、A問題とかだとこの先空欄の危険あり
また、コンテスト後に https://31536000.hatenablog.com/ で解説していると思うので、良かったら読んでねー

全部数え上げられるのでやるだけ
*/
