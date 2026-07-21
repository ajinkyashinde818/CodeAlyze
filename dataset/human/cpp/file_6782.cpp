#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <ctime>
#include <climits>
#include <cfloat>
#include <cstdint>
#include <cstddef>
#include <cinttypes>
#include <memory>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <array>
#include <valarray>
#include <string>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <bitset>
#include <queue>
#include <complex>
#include <tuple>
#include <utility>
#include <functional>
#include <algorithm>
#include <numeric>

using namespace std;

const double EPS = 1e-10;
const int64_t INF = 1e9;

typedef long long ll;

int A[200000], B[200000];
int ans[200000];

int main()
{
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < N; ++i) {
		scanf("%d", &B[i]);
	}

	int p = 0, q = 0;
	int p1 = -1, q1, p2, q2;
	int cur = 0;
	while (p < N || q < N) {
		int m;
		if (p < N) {
			m = A[p];
			if (q < N && B[q] < A[p])
				m = B[q];
		} else {
			m = B[q];
		}
		int np = p, nq = q;
		while (np < N && A[np] == m) ++np;
		while (nq < N && B[nq] == m) ++nq;
		//printf("m: %d np: %d nq: %d\n", m, np, nq);
		if (np-p + nq-q > N) {
			printf("No\n");
			return 0;
		}

		if (p1 == -1 && np >= N - nq) {
			p1 = p;
			q1 = q;
			p2 = np;
			q2 = nq;
		}
		
		p = np;
		q = nq;
	}

	printf("Yes\n");

	//printf("%d %d %d %d\n", p1, p2, q1, q2);
	int r = min(min(p1, q2-q1), p2-(N-q2));
	int spl = q2 - r;
	for (int i = spl; i < N; ++i) {
		if (i != spl) printf(" ");
		printf("%d", B[i]);
	}
	for (int i = 0; i < spl; ++i) {
		if (spl != N || i != 0) printf(" ");
		printf("%d", B[i]);
	}
	printf("\n");

	return 0;
}
