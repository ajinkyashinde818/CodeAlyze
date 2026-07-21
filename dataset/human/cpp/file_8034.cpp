#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 先頭から連続n枚 合計 と 残りカード合計 での比較 !!
int main(int argc , char **argv)
{
	(void)argc;
	(void)argv;

	vector<int64_t> v;
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		int64_t a;
		cin >> a;
		v.push_back(a);
	}

	int64_t Sum = 0;
	for(int i=0,iMax=v.size();i<iMax;i++){ Sum += v[i]; }

	int64_t min_Ans = LLONG_MAX;
	int64_t A_sum = 0;
	for(int i=0,iMax=v.size()-1;i<iMax;i++){
		A_sum += v[i];
		int64_t b = Sum-A_sum;
		int64_t ans = abs(A_sum - b);
//		printf("A:%ld , B:%ld , ans:%ld\n",A_sum,b,ans);
		if ( ans < min_Ans ) { min_Ans = ans;}
	}
	printf("%ld\n",min_Ans);

	return 0;
}
