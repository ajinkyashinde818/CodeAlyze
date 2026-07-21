#include <iostream>
using namespace std;

int main(){
	int r,g,b,n;
	cin >> r >> g >> b >> n;
	int new_value, constant;
	int count = 0;
	for(int i = 0; i <= n/r;i++){
		new_value = n - r * i ;
                constant = n - r * i;
		for(int j = 0; j <= constant / g; j++){
			new_value = n - r * i - g * j;
			if (new_value % b == 0){
				count++;
			}
		}
	}
	cout << count << endl;
}
