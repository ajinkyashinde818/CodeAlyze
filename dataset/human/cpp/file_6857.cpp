#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int n;
int A[maxn], B[maxn]; 
int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", &A[i]);
	for(int i = n; i; --i) scanf("%d", &B[i]);
	int j = 1;
	for(int i = 1; i <= n; ++i)
		if(A[i] == B[i])
		{
			bool f = 0; 
			for(; j <= n; ++j)
				if(B[j] != A[i] && B[i] != A[j])
				{
					swap(B[i], B[j]);
					f = 1;
					break;
				} 
			if(!f)
			{
				puts("No");
				return 0;
			}
		}
	puts("Yes");
	for(int i = 1; i <= n; ++i) printf("%d ", B[i]);
	return 0;
}
