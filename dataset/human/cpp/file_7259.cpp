#include <cstdio>
#include <algorithm>
using std::min;

long long abs(long long a)
{
	return a>=0? a:-a;
}

const int SIZE = 200000+10;
long long A[SIZE];

int main (void)
{
	int N;
	long long sum=0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%lld",A+i);
		sum += A[i];
	}
	
	long long MIN = 100000000000000000;
	long long now = 0;
	for(int i=0;i<N-1;i++){
		now += A[i];
		MIN = min( MIN , abs(  (now) - (sum-now) ) );
	}
	printf("%lld\n",MIN);
	
	return 0;
}
