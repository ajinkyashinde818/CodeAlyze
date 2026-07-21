#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

  
int main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
  	long A[N];
  	int idx = 0;
  	while(cin >> A[idx])
    {
      idx++;
    }
  	
  	std::vector<long> dp_p(N+1);
  	std::vector<long> dp_n(N+1);
  
	dp_n[0] = -1e10;
 
  	for (int i=0; i<N; i++) {
    	dp_p[i+1] = std::max(dp_p[i]+A[i], dp_n[i]-A[i]);
    	dp_n[i+1] = std::max(dp_p[i]-A[i], dp_n[i]+A[i]);
      	cerr << dp_p[i+1] << ":" << dp_n[i+1] << endl;
  	}
  	cout << dp_p[N] << endl;
	return 0;
}
