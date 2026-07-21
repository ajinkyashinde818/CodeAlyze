#include <iostream>
#include <algorithm>

std::string a[51], b[51];
int n, m;

bool match(int offset_x, int offset_y){
	int min_x = std::max(0, offset_x);
	int min_y = std::max(0, offset_y);
	int max_x = std::min(n, m + offset_x);
	int max_y = std::min(n, m + offset_y);

	for(int y = min_y; y < max_y; y++){
		for(int x = min_x; x < max_x; x++){
			if(a[y][x] != b[y - offset_y][x - offset_x])
				return false;
		}
	}
	return true;
}
int main(int argc, char *argv[]){
	std::cin >> n >> m;
	std::string s;
	std::getline(std::cin, s);
	for(int i = 0; i < n; i++){
		std::getline(std::cin, a[i]);
	}
	for(int i = 0; i < m; i++){
		std::getline(std::cin, b[i]);
	}
	bool flag = false;
	for(int y = 0; y <= n - m && !flag; y++){
		for(int x = 0; x <= n - m; x++){
			if(match(x, y)){
				flag = true;
				break;
			}
		}
	}
	std::cout << (flag ? "Yes" : "No") << std::endl;
	return 0;
}
