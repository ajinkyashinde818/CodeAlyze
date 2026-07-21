#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

int main()
{
	int N;

	int cnt=0;
	int mmin=1e9;
	lint sum=0;

	cin >> N;
	for(int i=0;i<N;i++)
	{
		int A;
		cin >> A;

		if(A<0)
			cnt++;
		A=abs(A);
		sum+=A;
		mmin=min(mmin,A);
	}
	
	if(cnt%2==1)
		sum-=2*mmin;
	
	cout << sum << endl;
	return 0;
}
