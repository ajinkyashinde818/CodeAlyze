#include <stdio.h>
#include <inttypes.h>

int main(void) {
	uint64_t N;
#if 0
	uint64_t soinsu[128];
#endif
	int64_t soinsuNum[128];
	int soinsuCount = 0;
	uint64_t cur, chk;
	int kotae;
	int i;
	if (scanf("%" SCNu64, &N) != 1) return 1;
	for (cur = N, chk = 2; chk * chk <= cur; chk++) {
		if (cur % chk == 0) {
#if 0
			soinsu[soinsuCount] = chk;
#endif
			soinsuNum[soinsuCount] = 0;
			while (cur % chk == 0) {
				soinsuNum[soinsuCount]++;
				cur /= chk;
			}
			soinsuCount++;
		}
	}
	if (cur > 1) {
#if 0
		soinsu[soinsuCount] = cur;
#endif
		soinsuNum[soinsuCount] = 1;
		soinsuCount++;
	}

	kotae = 0;
	for (i = 0; i < soinsuCount; i++) {
		int delta = 1;
		int hp = soinsuNum[i];
		while (hp >= delta) {
			kotae++;
			hp -= delta;
			delta++;
		}
	}
	printf("%d\n", kotae);
	return 0;
}
