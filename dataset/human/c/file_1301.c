#include <stdio.h>
#include <limits.h>

static int units[8];
static int waitings[8];

void setup() {
	units[0] = 4;
	units[1] = 1;
	units[2] = 4;
	units[3] = 1;
	units[4] = 2;
	units[5] = 1;
	units[6] = 2;
	units[7] = 1;
}

int scan_waitings() {
	return scanf("%d %d %d %d %d %d %d %d",
			&waitings[0], &waitings[1], &waitings[2], &waitings[3],
			&waitings[4], &waitings[5], &waitings[6], &waitings[7]);
}

int count_passengers(int offset) {
	int sum = 0;
	int i;
	for (i = 0; i < 8; i++) {
		sum += (units[(i + offset) % 8] > waitings[i]) ? waitings[i] : units[(i + offset) % 8];
	}
	return sum;
}

void print_result(int offset) {
	int i;
	for (i = 0; i < 8; i++) {
		printf("%d", units[(i + offset) % 8]);
		if (i < 7) {
			printf(" ");
		} else {
			printf("\n");
		}
	}
}

int main() {
	int offset = 0;
	int max = 0;
	int count = 0;
	int max_offset = 0;
	char str[9];
	int num = INT_MAX;
	setup();

	while (scan_waitings() > 0) {
		max = 0;
		count = 0;
		max_offset = 0;
		num = INT_MAX;
		for (offset = 0; offset < 8; offset++) {
			count = count_passengers(offset);
			sprintf(str, "%d%d%d%d%d%d%d%d",
						units[(0 + offset) % 8],
						units[(1 + offset) % 8],
						units[(2 + offset) % 8],
						units[(3 + offset) % 8],
						units[(4 + offset) % 8],
						units[(5 + offset) % 8],
						units[(6 + offset) % 8],
						units[(7 + offset) % 8]
						);
			if (count > max) {
//				printf("新記録   offset = %d, 配置 = %d\n", offset, atoi(str));
				num = atoi(str);
				max_offset = offset;
				max = count;
			} else if (count == max) {
//				printf("タイ記録 offset = %d, 配置 = %d\n", offset, atoi(str));
				if (num > atoi(str)) {
					max = count;
					num = atoi(str);
					max_offset = offset;
				}
			}
		}
		print_result(max_offset);
	}
	return 0;
}
