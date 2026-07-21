#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<string> a(n), b(m);
	copy_n(istream_iterator<string>(cin), n, a.begin());
	copy_n(istream_iterator<string>(cin), m, b.begin());
	for(int i = 0; i < n - m + 1; i++){
		for(int j = 0; j < n - m + 1; j++){
			bool same = true;
			for(int k = 0; k < m; k++){
				for(int l = 0; l < m; l++){
					if(a[i + k][j + l] != b[k][l]){
						same = false;
						break;
					}else if(!same){
						break;
					}
				}
			}
			if(same){
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}
