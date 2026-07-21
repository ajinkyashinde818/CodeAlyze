#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//素因数
void func(int a,long int list[],int listnum[],int strt) {
	if(strt==0){}else{
		for (int m = strt; m <= a; m++) {
			if (a%m == 0) {
				list[listnum[0]] = m;
				listnum[0]++;
				func(a / m, list, listnum, m);
				break;
			}
		}
	}
	
}

int main(void) {
	long int x;
	long int y;
	scanf("%ld %ld", &x, &y);
	long int listX[100];	int listXnum[1] = { 0 };
	long int listY[100];	int listYnum[1] = { 0 };
	//素因数挽回
	func(x, listX, listXnum, 2);
	func(y, listY, listYnum, 2);
	long int ans = 1;
	for (int k = 0; k < listXnum[0]; k++) {
		for (int m = 0; m < listYnum[0]; m++) {
			if (listX[k] == listY[m]) {
				ans*=listX[k];
				listX[k] = 1;
				listY[m] = 1;

			}

		}

	}
	for (int k = 0; k < listXnum[0]; k++) {
		ans *= listX[k];

	}
	for (int m = 0; m < listYnum[0]; m++) {
		ans *= listY[m];
	}
	printf("%ld", ans);
}
