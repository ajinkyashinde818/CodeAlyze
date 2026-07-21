#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>


typedef long long ll;

using namespace std;

int main() 
{ 

	int a, b;
	cin >> a >> b;

	if (a >= 10){
		cout << b << endl;
	} else {
		cout << b + (100 * (10 - a)) << endl;
	}

	return 0; 
}
