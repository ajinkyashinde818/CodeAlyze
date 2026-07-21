#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <deque>
#define NMAX 52
#define MMAX 52

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int ,int > P;
typedef long long ll;

char A[NMAX][NMAX],B[MMAX][MMAX];
int C,N,M,W,H,ans;
string S;
static const int dx[8] = {0,1,1,1,0,-1,-1,-1},
					dy[8] = {1,1,0,-1,-1,-1,0,1};

bool check(int a,int b){
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if(B[i][j] != A[a+i][b+j]){
				return false;
			}
		}
	}
	return true;
}

bool solve(){
	for (int i = 0; i < N-M+1; ++i)
	{
		for (int j = 0; j < N-M+1; ++j)
		{
			if(check(i,j)){
				return true;
			}
		}
	}
	return false;
}

void debug(){

}

void answer(){

}

int main(){
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> A[i][j];
		}
	}
	for (int i = 0; i < M; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> B[i][j];
		}
	}
	if(solve()){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	#ifdef DEBUG
	debug();
	#endif
	answer();

	return 0;
}
