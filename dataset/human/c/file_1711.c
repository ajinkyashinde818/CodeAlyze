#include <stdio.h>

int main()
{
	int n, s = 0, i;
	int a[20], b[50], c[50];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}
	for(i = 0; i < n - 1; i++){
		scanf("%d", &c[i]);
	}
	for(i = 0; i < n; i++){
		s += b[a[i] - 1];
		if(i > 0 && a[i] == a[i - 1] + 1){
			s += c[a[i - 1] - 1];
		}
	}
	printf("%d\n", s);
	return 0;
}
