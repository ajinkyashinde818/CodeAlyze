#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>
#include <cinttypes>
#include <bits/stdc++.h>

#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define abs(a) (((a) < 0) ? -(a) : (a))

#define FOR(var, to)          for (register int var = 0; var < to; var++)
#define FROMTO(var, from, to) for (register int var = from; var <= to; var++)

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;
typedef int64_t s64;

static inline int ri() {
	int a;
	scanf("%d", &a);
	return a;
}

static inline s64 rs64() {
	s64 a;
	scanf("%" SCNd64, &a);
	return a;
}

static inline void wi(int a) {
	printf("%d", a);
}

static inline void wu64(u64 a) {
	printf("%" PRIu64, a);
}

bool judge(s64 a,s64 b,s64 c,s64 d) {
	if (a<b) return false;
	if (b > d) return false;
	if (b == d) return ((a%b) <= c);
	if (b <= c) return true;
	// if (a == b) return true; // WA
	// a >= b
	// b < d
	// b > c
	s64 first = c-(b-(a-c-1)%b-1);
	// printf("  first : %" PRId64 "\n", first);
	if (first < 0) return false;
	s64 gc;
	{
		s64 b_ = b;
		s64 d_ = d;
		while(b_&&d_){
			if (b_>d_) b_%=d_;
			else d_%=b_;
		}
		gc = max(b_,d_);
	}
	// printf("  gc : %" PRId64 "\n", gc);
	if (b-c-1 >= gc) return false;
	if (b-c <= 1) return true;
	s64 bb = (b-1)%gc;
	s64 cc = (c+1)%gc;
	if (bb == cc)
		return !(first%gc == bb);
	else if (bb < cc)
		return !(first%gc >= bb || first%gc <= cc);
	else
		return !(first%gc >= bb && first%gc <= cc);
	
}

int main() {
	int t = ri();
	s64 a[t];
	s64 b[t];
	s64 c[t];
	s64 d[t];
	FOR(i,t) {
		a[i] = rs64();
		b[i] = rs64();
		c[i] = rs64();
		d[i] = rs64();
	}
	
	FOR(i,t)
		printf("%s\n", judge(a[i],b[i],c[i],d[i]) ? "Yes" : "No");
	
	
	
	return 0;
}
