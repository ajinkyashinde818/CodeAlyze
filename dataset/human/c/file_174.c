// Aizu Vol-2 0268: Kongo Type
// 2017.8.17

#include <stdio.h>
#include <stdlib.h>

char *gets();
char buf[20], *p;

int frac[7] = { 78125, 156250, 312500, 625000, 1250000, 2500000, 5000000 };

int x2d(char c) { if (c <= '9') return c - '0'; return c - 'a' + 10; }

int main(void)
{
	int Q, i, d, f;

	gets(buf); Q = atoi(buf);
	while (Q-- > 0) {
		gets(p = buf);
		if (*p >= '8') putchar('-');
		d = x2d(*p++); if (d >= 8) d -= 8;
		for (i = 0; i < 5; i++) d = (d << 4) + x2d(*p++);
		d <<= 1;
		f = x2d(*p++);
		if (f >= 8) d |= 1;
		printf("%d.", d);
		f = (f << 4) + x2d(*p);
		for (d = i = 0; i < 7; i++, f >>= 1) if (f & 1) d += frac[i];
		sprintf(buf, "%07d", d);
		p = buf + 6;
		while (p > buf && *p == '0') p--;
		*(p + 1) = 0;
		puts(buf);
	}
	return 0;
}
