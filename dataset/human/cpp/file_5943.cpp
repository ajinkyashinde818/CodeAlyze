#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>

const int INF = 1000000009;
const long LINF = 1123456789012345678;

long n;
long c;
long x[100000];
long v[100000];
long rcost[100000];
long lcost[100000];
long rmax[100000];
long lmax[100000];

int main(){
	scanf("%ld%ld", &n, &c);
	for(int i = 0; i < n; i++){
		scanf("%ld%ld", &x[i], &v[i]);
	}
	for(int i = 0; i < n; i++){
		if(i == 0){
			rcost[0] = v[0] - x[0];
		}else{
			rcost[i] = v[i] - (x[i] - x[i-1]) + rcost[i-1];
		}
	}
	for(int i = n-1; i >= 0; i--){
		if(i == n-1){
			lcost[n-1] = v[n-1] - (c - x[n-1]);
		}else{
			lcost[i] = v[i] - (x[i+1] - x[i]) + lcost[i+1];
		}
	}
	/*
	printf("right\n");
	for(int i = 0; i < n; i++){
		printf("	%ld\n", rcost[i]);
	}
	printf("left\n");
	for(int i = 0; i < n; i++){
		printf("	%ld\n", lcost[i]);
	}
	//*/
	rmax[0] = rcost[0];
	lmax[n-1] = lcost[n-1];
	for(int i = 1; i < n; i++){
		rmax[i] = std::max(rcost[i], rmax[i-1]);
	}
	for(int i = n-2; i >= 0; i--){
		lmax[i] = std::max(lcost[i], lmax[i+1]);
	}
	/*
	printf("right\n");
	for(int i = 0; i < n; i++){
		printf("	%ld\n", rmax[i]);
	}
	printf("left\n");
	for(int i = 0; i < n; i++){
		printf("	%ld\n", lmax[i]);
	}
	//*/
	long max = rmax[n-1];
	for(int i = 0; i < n-1; i++){
		max = std::max(max, rmax[i] + lmax[i+1] - x[i]);
	}
	max = std::max(lmax[0], max);
	for(int i = n-1; i > 0; i--){
		max = std::max(max, lmax[i] + rmax[i-1] - (c - x[i]));
	}
	if(max < 0){
		max = 0;
	}
	printf("%ld\n", max);
	return 0;
}
