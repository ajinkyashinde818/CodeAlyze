#include <string>
#include <iostream>

using namespace std;

const int nmax = 50;
const int mmax = 50;
char N_sq[nmax][nmax], M_sq[mmax][mmax];


bool judge_match(int x, int y, int M){
	for(int i=0;i<M;++i){
		for(int j=0;j<M;++j){
			if(N_sq[y+i][x+j] != M_sq[i][j]) return false;
		}
	}
	return true;
}


int main(void){
	int N,M;

	cin >> N >> M;
	bool exist = false;

	for(int i=0;i < N;++i){
		cin >> N_sq[i];
	}

	for(int i=0;i < M;++i){
		cin >> M_sq[i];
	}

	for(int y=0;y <= N - M;++y){
		for(int x=0;x <= N - M;++x){
			if(judge_match(x, y, M)) exist=true;
		}
	}

	if(exist)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;

}
