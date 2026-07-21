#include<stdio.h>
#include<stdlib.h>
int main(){
	int w, h, n, x1, y1, x2, y2, kx, ky, cnt = 0;
	scanf("%d%d%d%d%d", &w, &h, &n, &x1, &y1);
	for (int i = 0; i < n - 1; i++){
		scanf("%d%d", &x2, &y2);
		kx = x2 - x1;
		ky = y2 - y1;
		while (kx > 0 && ky > 0){
			cnt++;kx--;ky--;
		}
		while (kx < 0 && ky < 0){
			cnt++; kx++; ky++;
		}
		cnt += abs(kx) + abs(ky);
		x1 = x2;y1 = y2;
	}
	printf("%d\n", cnt);
	return 0;
}
