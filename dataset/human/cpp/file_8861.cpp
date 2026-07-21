#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <math.h>
#include <stdlib.h>
#include <numeric>

int main(){
	int m, n;
	std::cin >> n >> m;
	char a[50][50], b[50][50];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			std::cin >> a[i][j];
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < m; j++){
			std::cin >> b[i][j];
		}
	}
	for(int i = 0; i < n - m + 1; i++){
		for(int j = 0; j < n - m + 1; j++){
			bool how = true;
			for(int k = 0; k < m; k++){
				for(int l = 0; l < m; l++){
					if(how){
						how = (a[i+k][j+l] == b[k][l]);
					}
				}
			}
			if(how){
				std::cout << "Yes" << std::endl;
				return 0;
			}
		}
	}
	std::cout << "No" << std::endl;
	return 0;
}
