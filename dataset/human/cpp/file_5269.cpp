#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <map>
typedef long long ll;
#include <cmath>


int main(int argc, char *argv[])
{
	int n,r;
	cin >> n>>r;
	
	if (n<10) r+=(100)*(10-n);

	cout<< r<<endl;
	return 0;
}
