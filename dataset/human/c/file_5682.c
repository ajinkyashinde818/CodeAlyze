#include <stdio.h>

#define ARRAY_SIZE 200000

int main()
{
	int n = 0;
	scanf("%d", &n);

	int Array[ARRAY_SIZE] = { 0 };

	for (int i = 0; i < n; ++i) {
		scanf("%d", &Array[i]);
	}

	int maxv = Array[1] - Array[0]; // 最大の利益が負になる可能性があるので,0で初期化してはいけない.
	int minv = Array[0];

	for (int i = 1; i < n; ++i) {
		maxv = Array[i] - minv > maxv ? Array[i] - minv : maxv;
		minv = minv > Array[i] ? Array[i] : minv;
	}
	
	printf("%d\n", maxv);

	return 0;
}
