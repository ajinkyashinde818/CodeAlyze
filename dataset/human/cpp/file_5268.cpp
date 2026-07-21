#include<iostream>
#include<algorithm>
#include<limits>
#include<iomanip>
#include<string>
#include<map>
#include<vector>
#include<string.h>

using namespace std;

int main(void) {
	int n, r;
	cin >> n >> r;
	if(n >= 10) {
        cout << r << endl;
	} else {
        cout << r + (100 * (10 - n)) << endl;
	}
    
}
