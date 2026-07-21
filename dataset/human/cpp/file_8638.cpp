#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
 
using namespace std;
 
int main()
{
	int_least32_t n, m;
	cin >> n >> m;
 
	vector<string> a( n ), b( m );
	for(auto& x : a) {
		cin >> x;
	} 
 
	for(auto& x : b) {
		cin >> x;
	}
 
	int_least32_t dif{ n - m + 1 };
	string temp;
	bool isok;
	for(auto i = 0; i < dif; ++i) {
		for(auto j = 0; j < dif; ++j) {
			isok = true;
			for(auto k = 0; k < m; ++k) {
				if(b[k] != a[i + k].substr(j, m)) {
					isok = false;
					break;
				}
			}
			if(isok) {
				goto end;
			}
		}
	}

end:
	if(isok) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
