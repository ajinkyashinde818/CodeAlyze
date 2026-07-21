#include <stdio.h>
void print_chessboard(int h, int w) {
	int x, y;
	int i = 0;
	char c[] = "#.";
	for (y = 0; y < h; y++) {
		i = y % 2;
		for (x = 0; x < w; x++) {
			putchar(c[i]);
			i ^= 1;
		}
		putchar('\n');
	}
}
int main() {
	int h, w;
	scanf("%d %d", &h, &w);
	while (h != 0 || w != 0) {
		print_chessboard(h, w);
		putchar('\n');
		scanf("%d %d", &h, &w);
	}
	return 0;
}
