#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

int main(int argc, char const *argv[]){
	int n,m;
	char a[57][57],b[57][57];
	int f;
	scanf("%d%d",&n,&m);

	for(int i = 0; i < n; ++i){
		scanf("%s",a[i]);
	}
	for(int i = 0; i < m; ++i){
		scanf("%s",b[i]);
	}
	for(int i = 0; i <= n - m; i++){
		for(int l = 0; l <= n - m; l++){
			f = 0;
			for(int j = 0; j < m; j++){
				for(int k = 0; k < m; k++){
					if(a[j + i][k + l] != b[j][k])
					{
						f = 1;
						break;
					}
				}
			}
			if(f == 0)
			{
				puts("Yes");
				return 0;
			}
		}
	}
	puts("No");
	return 0;
}
