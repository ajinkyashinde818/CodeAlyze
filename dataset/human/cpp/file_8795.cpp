#include<iostream>
#include<vector>
#include<string>

using namespace std;

int N, M;
bool match = false;
char picA[50][51], picB[50][51];

void pfind(int sx,int sy) {
	for (int i = 0; i <M ; i++) {
		for (int j = 0; j < M; j++) {
			if (picB[i][j] != picA[i+sy][j+sx]) return;
		}
	}
	match = true;
	return;
}

int main() {
	
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < N; j++) picA[i][j]=str[j];
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str; 
		for (int j = 0; j < M; j++) picB[i][j]=str[j];
	}

	for (int i = 0; i <= N - M; i++) {
		for (int j = 0; j <= N - M; j++) {
			pfind(j,i);
			if (match)break;
		}
		if (match)break;
	}

	if (match)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}
