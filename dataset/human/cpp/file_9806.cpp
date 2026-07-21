#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <iterator>
#include <cmath>
#include <deque> 
#include <set>

using namespace std;

int n;
char s[100010];
long long counts[30];	//1~26
long long f[30][30];

const long long MOD = 1000000007;

int main()
{
	scanf("%d\n", &n);
	scanf("%s", s);
	
	for (int i = 0 ; i < n ; i++)
		counts[s[i] - 'a' + 1]++;
		
	for (int i = 1 ; i <= 26 ; i++)
		f[1][i] = counts[i];
		
	for (int i = 2 ; i <= 26 ; i++)
	{
		for (int j = i ; j <= 26 ; j++)
		{
			long long sum = 0;
			for (int k = 1 ; k < j ; k++)
				sum = (sum + (counts[j] * f[i - 1][k]) % MOD) % MOD;
			f[i][j] = sum;
		}
	}
	
	long long total = 0;
	for (int i = 1 ; i <= 26 ; i++)
		for (int j = 1 ; j <= 26 ; j++)
			total = (total + f[i][j]) % MOD;
	
	printf("%lld\n", total);
	
	return 0;
}
