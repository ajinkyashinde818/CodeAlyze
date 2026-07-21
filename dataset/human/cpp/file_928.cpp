#include <iostream>
using namespace std;

int main()
{
	int r, g, b, n;
	cin >> r >> g >> b >> n;

	int cnt = 0;

	for(int i=0;i<=n/r;i++){
		int rest = n - i*r;
		for(int j=0;j<=rest/g;j++){
			int rest2 = rest - j*g;
			if(rest2 % b == 0){
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}
