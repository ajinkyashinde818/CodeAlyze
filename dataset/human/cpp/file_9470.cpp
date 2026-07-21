#include <iostream>
#include <string>

constexpr int MAX_NM = 50;

bool solve(int i, int j);

std::string A[MAX_NM], B[MAX_NM];
int n, m;

int main(){
	std::ios::sync_with_stdio(false);

	std::cin >> n >> m;

	for(int i = 0; i < n; ++i){
		std::cin >> A[i];
	}


	for(int i = 0; i < m; ++i){
		std::cin >> B[i];
	}

	bool ans = false;
	for(int i = 0; i <= (n - m); ++i){
		for(int j = 0; j <= (n - m); ++j){
			if(solve(i, j)){
				ans = true;
			}	
		}
	}

	if(ans){
		std::cout << "Yes\n";
	}
	else{
		std::cout << "No\n";
	}

	return 0;
}

bool solve(int i, int j){
	for(int k = 0; k < m; ++k){
		for(int l = 0; l < m; ++l){
			if(A[i + k][j + l] != B[k][l]){
				return false;
			}
		}
	}
	return true;
}
