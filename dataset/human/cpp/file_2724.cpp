#include <iostream>
#include <vector>
#include <utility>
#include <math.h>

using namespace std;

int main(int argc, char* argv[]) {

  	int n;
  	cin >> n;

  	int negative_count = 0;
  	long min = 100000000000;
  	long sum = 0;
	vector<long> ar(n);
  	for (int i=0; i<n; i++) {
    	cin >> ar[i];
      	if (ar[i] < 0) {
        	negative_count ++;
        }
      	int r = labs(ar[i]);
      	if (r < min) {
          min = r;
        }
      	sum += r;
    }

    //printf("sum:%ld, min:%ld\n", sum, min);
	
	if (negative_count % 2 != 0) {
		sum -= min * 2;
    }
  
  
  	cout << sum << endl;
  	return 0;
}
