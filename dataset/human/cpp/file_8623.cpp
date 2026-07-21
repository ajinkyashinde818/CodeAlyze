//インクルード
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

//型宣言
typedef long long ll;
typedef unsigned long long ull;
typedef std::string string;
typedef string answerType;

//変数宣言
ll N;
ll M;
std::vector<string> Ai;
std::vector<string> Bi;
answerType answer;

//関数のプロトタイプ宣言
//入力の取得
void getInput();
//答えを求める
answerType calcAnswer();

//メイン関数
int main() {
	//入力の取得
	getInput();

	//答え
	answerType answer = calcAnswer();

	//答えの出力
	std::cout << answer << std::endl;

	//正常終了
	return EXIT_SUCCESS;
}

//入力の取得
void getInput() {
	std::cin >> N >> M;

	string temp;
	std::getline(std::cin, temp);

	for(ll i=0; i<N; ++i) {
		string A;
		std::getline(std::cin, A);
		Ai.push_back(A);
	}

	for(ll i=0; i<M; ++i) {
		string B;
		std::getline(std::cin, B);
		Bi.push_back(B);
	}
}

//答えを求める
answerType calcAnswer() {
	for(int i=0; i<=N-M; ++i) {
		size_t temp = string::npos;
		for(int j=0; j<M; ++j) {
			string A = Ai[i+j];
			string B = Bi[j];
			size_t temp2;
			if(temp == string::npos) {
				temp2 = A.find(B);
				temp = temp2;
			} else {
				temp2 = A.find(B, temp);
			}
			if(temp2 == string::npos || temp != temp2) {
				temp = string::npos;
				break;
			}
		}
		if(temp != string::npos) {
			return "Yes";
		}
	}
	return "No";
}
