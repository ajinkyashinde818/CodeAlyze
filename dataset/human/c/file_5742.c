#include<stdio.h>
#include<math.h>

int main() {
	int i,n,Rt[200000],max,min;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &Rt[i]);
	}
	min= Rt[0];
	max = Rt[1]-Rt[0];
	for (i = 1; i < n; i++) {
		if (max < Rt[i] - min) {
			max = Rt[i] - min;
		}
		if (min > Rt[i]) {
			min = Rt[i];
		}
	}
	printf("%d\n", max);

}
