#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#ifndef U_L_LONG
typedef unsigned long long U_L_LONG;
#endif
#ifndef L_LONG
typedef long long L_LONG;
#endif

#define LL_ABS(x) (((((x) < 0) ? ((x) * (-1)) : (x))))

static void ABC120D_DecayedBridges();
static void ABC119D_LazyFaith();

#if 1
int main()
{
	//ABC120D_DecayedBridges();
	ABC119D_LazyFaith();

	fflush(stdout);
	return 0;
}
#endif


static int binSearch(const L_LONG& xpoint, const L_LONG* container, int contCount, int & secondIdx)
{
	int startPoint = 0, endPoint = contCount;
	int bsTarget = 0, tmpTarget = 0;
	L_LONG dist = 0, tmpDist = 0;
	while (1) {
		bsTarget = (startPoint + endPoint) / 2;

		if ((endPoint - startPoint) < 2) {
			secondIdx = -1;

			if ((container[bsTarget] < xpoint) && ((bsTarget + 1) < contCount)) {
				secondIdx = bsTarget + 1;
			}
			else if ((container[bsTarget] >= xpoint) && ((bsTarget - 1) >= 0)) {
				secondIdx = bsTarget - 1;
			}
		
			break;
		}
		else if (container[bsTarget] < xpoint) {
			startPoint = bsTarget;
		}
		else if (container[bsTarget] > xpoint) {
			endPoint = bsTarget;
		}
	}
	return bsTarget;
}

static void search(const L_LONG& xpoint, const L_LONG* shrine, int sCount, const L_LONG* temple, int tCount, L_LONG& answer)
{
	int sh1stIdx = 0, sh2ndIdx = 0;
	int tm1stIdx = 0, tm2ndIdx = 0;

	sh1stIdx = binSearch(xpoint, shrine, sCount, sh2ndIdx);
	tm1stIdx = binSearch(xpoint, temple, tCount, tm2ndIdx);

	L_LONG shDist[2] = { 0 };
	L_LONG tmDist[2] = { 0 };

	int shCount = 1;
	shDist[0] = xpoint - shrine[sh1stIdx];
	if (sh2ndIdx >= 0) {
		shCount = 2;
		shDist[1] = xpoint - shrine[sh2ndIdx];
	}
	
	int tmCount = 1;
	tmDist[0] = xpoint - temple[tm1stIdx];
	if (tm2ndIdx >= 0) {
		tmCount = 2;
		tmDist[1] = xpoint - temple[tm2ndIdx];
	}

	L_LONG total = 0;
	L_LONG totalMin = LLONG_MAX;
	for (int s = 0; s < shCount; s++) {
		for (int t = 0; t < tmCount; t++) {
			if (((shDist[s] < 0) && (tmDist[t] < 0)) || ((shDist[s] >= 0) && (tmDist[t] >= 0))) {
				if (LL_ABS(shDist[s]) > LL_ABS(tmDist[t])) {
					total = LL_ABS(shDist[s]);
				}
				else {
					total = LL_ABS(tmDist[t]);
				}
			}
			else if (LL_ABS(shDist[s]) > LL_ABS(tmDist[t])) {
				total = LL_ABS(tmDist[t]) * 2 + LL_ABS(shDist[s]);
			}
			else {
				total = LL_ABS(tmDist[t]) + LL_ABS(shDist[s]) * 2;
			}

			if (totalMin > total) {
				totalMin = total;
			}
		}
	}
	answer = totalMin;
}

static void ABC119D_LazyFaith()
{
	static L_LONG shrine[100000] = { 0 };
	static L_LONG temple[100000] = { 0 };
	static L_LONG xpoint[100000] = { 0 };
	static L_LONG answer[100000] = { 0 };

	int A = 0, B = 0, Q = 0;

	scanf(" %d %d %d", &A, &B, &Q);

	for (int i = 0; i < A; i++) {
		scanf(" %lld", &shrine[i]);
	}
	for (int i = 0; i < B; i++) {
		scanf(" %lld", &temple[i]);
	}
	for (int i = 0; i < Q; i++) {
		scanf(" %lld", &xpoint[i]);
	}

	for (int i = 0; i < Q; i++) {
		search(xpoint[i], shrine, A, temple, B, answer[i]);
		printf("%lld\n", answer[i]);
	}
}
