#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <string>
#include<algorithm>
#include<map>
#include <vector>
#include <cassert>
#include<cmath>
using namespace std;



int main() {
	int N, R;
	cin >> N >> R;
	if (N >= 10) {
		cout << R << endl;
	}
	else {
		cout << R + 100 * (10 - N) << endl;
	}
}
