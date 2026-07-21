#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592653589793
#define MOD 1000000007

long int combination(long int n, long int r);

//qsort用、昇順
int compare_int(const void *a, const void *b)
{
	return *(int*)a-*(int*)b;
}
//qsort(data, 10, sizeof(int), compare_int)

long int combination(long int n, long int r)
{
	if(r>n-r) r = n-r;
	if(r == 0) return 1;
	else if(r == 1) return n;
	return (combination(n-1, r) + combination(n-1, r-1));
	//大きくなるとき
	/*
	long int tmp1, tmp2, tmp3;
	tmp1 = combination(n-1, r);
	if(tmp1>=MOD) tmp1 = tmp1%MOD;
	tmp2 = combination(n-1, r-1);
	if(tmp2>=MOD) tmp2 = tmp2%MOD;
	tmp3 = tmp1+tmp2;
	if(tmp3>=MOD) tmp3 = tmp3%MOD;
	return (tmp3);
	*/
}


int main(){
	int h, w;
	scanf("%d%d", &h, &w);
	char tehon[h+2][w+2];
	int count=0;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			scanf(" %c", &tehon[i][j]);
			//count++; printf("%d:(%d, %d) %c\n", count, i, j, tehon[i][j]);
		}
	}

	int ok=1;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(tehon[i][j] == '#'){
				if((tehon[i+1][j]=='.') && (tehon[i][j+1]=='.') && (tehon[i-1][j]=='.') && (tehon[i][j-1]=='.')){
					ok = -1;
				}
			}
		}
	}
	if(ok==1) printf("Yes\n");
	else printf("No\n");
		
	return 0;
}
