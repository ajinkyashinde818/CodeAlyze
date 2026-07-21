#include <iostream> // cout, endl, cin
#include <string> // string, to_string, stoi
#include <cstring>
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
#include <cmath>
#include <numeric>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef unsigned long long ll;


int main(){
	int N ;
	vector<int> c(3); cin >> c[0] >>c[1] >> c[2] >> N;
	int count = 0;
	sort(c.begin(),c.end());
	if(c[0] != 1){
	rep(i,N /c[0]+1){
		rep(j,N/c[1]+1){
			rep(k,N/c[2]+1){
				
				if(i*c[0]+j*c[1]+k*c[2] == N) count++;
			}
		}
	}
	}
	else{
		rep(j,N/c[1]+1){
			rep(k,N/c[2]+1){		
				if(j*c[1]+k*c[2] <= N) count++;
			}
		}
	}
	cout << count << endl;
}
