#include<iostream>
#include<iomanip>
#include<algorithm>
#include<string>
#include<vector>
#include<deque>
#include<queue>

using std::cout;
using std::cin;
using std::setw;
using std::setfill;
using std::string;
using std::pair;
using std::make_pair;
using std::vector;
using std::queue;
using std::deque;
using std::priority_queue;
using std::next_permutation;
//using std::iota;
using std::sort;
using std::greater;
using std::max;
using std::min;

using lli = long long int;
using ulli = unsigned long long int;

#define INF 999999999;
#define MOD 1000000007;

#define EVEL 1

#ifndef EVEL
#define dbug(X) std::cout << #X << ":" <<X<<" " ;
#define dbugf(s) std::cout << s << " ";
#define dbugln std::cout<<"\n";
#else
#define dbug(X) {}
#define dbugf(s) {}
#define dbugln {}
#endif



lli N;
lli A;
vector<lli> sum;
int cntm;
lli ans;

int main(void){
	cin.tie(0);
	std::ios::sync_with_stdio(false);

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> A;
		if(A<0){
			A *= -1;
			cntm++;
		}
		sum.push_back(A);
		ans += A;
	}
	if(cntm % 2 == 0){
		cout << ans;
	}else{
		sort(sum.begin(), sum.end());
		cout << ans - sum[0]*2;
	}

	return 0;
}
