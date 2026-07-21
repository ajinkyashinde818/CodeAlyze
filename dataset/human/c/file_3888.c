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

static void ABC120D_DecayedBridges();
static void ABC119C_SyntheticKadomatsu();
static void ABC120B_KthCommonDivisor();

#if 1
int main()
{
	//ABC120D_DecayedBridges();
	//ABC119C_SyntheticKadomatsu();
	ABC120B_KthCommonDivisor();

	fflush(stdout);
	return 0;
}
#endif

static void ABC120B_KthCommonDivisor()
{
	int A = 0, B = 0, K = 0;

	scanf(" %d %d %d", &A, &B, &K);

	int target = 100;
	int count = 0;
	while (1) {
		if (((A % target) == 0) && ((B % target) == 0)) {
			count++;
			if (count == K) {
				break;
			}
		}
		target--;
	}

	printf("%d\n", target);
}
