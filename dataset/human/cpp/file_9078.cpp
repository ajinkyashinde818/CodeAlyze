#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

int n, m;
std::vector<std::string> a, b;
bool ans;

int main(){
	std::cin >> n >> m;
	std::string s;
	for(int i=0; i<n; ++i){
		std::cin >> s;
		a.push_back(s);
	}
	for(int i=0; i<m; ++i){
		std::cin >> s;
		b.push_back(s);
	}
	for(int i=0; i+m<=n; ++i)
		for(int j=0; j+m<=n; ++j){
			bool f = true;
			for(int k=0; k<m; ++k)
				for(int l=0; l<m; ++l)
					if(a[i+k][j+l] != b[k][l])
						f = false;
			if(f) ans = true;
		}
	if(ans) std::cout << "Yes" << std::endl;
	else std::cout << "No" << std::endl;
}
