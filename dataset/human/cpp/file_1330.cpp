#include <iostream>
using namespace std;

int main() {
	int r, g, b, n;
	cin >> r >> g >> b >> n;

	int count=0;

	for(int i=0;i<=n/r;++i){
		for(int j=0;j<=(n-r*i)/g;++j){
			if((n-i*r-j*g)%b==0){
				count += 1;
			}
		}
	}

	cout << count << endl;

}
