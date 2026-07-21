#include <iostream>

using namespace std;


inline long Aabs(long a)
{
	return (a>0) ? a: -a;
}

void solve()
{
	long N, minuses=0; cin >> N;
	long *A = new long[N];
	long long ans = 0;
	long absmin = 0;


	cin >> A[0];
	if(A[0]<0)
		minuses++;
	ans += Aabs(A[0]);
	absmin = Aabs(A[0]);

	for(long i=1; i<N; i++){
		cin >> A[i];
		if(A[i]<0)
			minuses++;
		ans += Aabs(A[i]);
		if(absmin > Aabs(A[i]))
			absmin = Aabs(A[i]);
	}

	if(minuses%2)
		ans += (-2)*absmin;
	
	cout << ans;
	return ;
}

int main()
{
	solve();

	return 0;
}
