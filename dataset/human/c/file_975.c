#include <stdio.h>
int main() {
int a = 0, b, E, Y;
scanf("%d", &E);
scanf("%d", &Y);
if (E == 0) {
if (Y >= 1868 && Y <= 1911) {
 a = Y - 1868;
printf("M%d\n", a+1); 
} else if (Y >= 1912 && Y <= 1925) {
 a = Y - 1912;
printf("T%d\n", a+1);
} else if (Y >= 1926 && Y <= 1988) {
 a = Y - 1926;
printf("S%d\n", a+1);
} else if (Y >= 1989 && Y <= 2016) {
 a = Y - 1989;
printf("H%d\n", a+1);
}
} 	else if (E == 1) {
		b = 1867 + Y;
		printf("%d\n", b);
	} else if (E == 2) {
		b = 1911 + Y;
		printf("%d\n", b);
	} else if (E == 3) {
		b = 1925 + Y;
		printf("%d\n", b);
	} else if (E == 4) {
		b = 1988 + Y;
		printf("%d\n", b);
} return 0;
}
