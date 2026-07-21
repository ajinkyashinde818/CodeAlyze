#include<stdio.h>
int main(void) {
	int E, Y,s,a=1868,b=1911,c=1912,d=1925,e=1926,f=1988,g=1989,h=2016;
	scanf("%d", &E);
	switch (E) {
	case 0:
		scanf("%d", &Y);
		if (a <= Y && Y <= b) {
			s = b - Y;
			s = 44 - s;
			printf("M%d\n", s);
		}
		else if (c <= Y && Y <= d) {
			s = d - Y;
			s = 14 - s;
			printf("T%d\n", s);
		}
		else if (e <= Y && Y <= f) {
			s = f - Y;
			s = 63 - s;
			printf("S%d\n", s);
		}
		else if (g <= Y && Y <= h) {
			s = h - Y;
			s = 28 - s;
			printf("H%d\n", s);
		}
		break;
	case 1:
		scanf("%d", &Y);
		s = 44 - Y;
		s = b - s;
		printf("%d\n", s);
		break;
	case 2:
		scanf("%d", &Y);
		s = 14 - Y;
		s = d - s;
		printf("%d\n", s);
		break;
	case 3:
		scanf("%d", &Y);
		s = 63 - Y;
		s = f - s;
		printf("%d\n", s);
		break;
	case 4:
		scanf("%d", &Y);
		s = 28 - Y;
		s = h - s;
		printf("%d\n", s);
		break;
	default:
		printf("error");
		break;
	}
	return 0;
}
