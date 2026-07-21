#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

//for
#define REP(i,n) for(int i=0,i##_len=(int)(n);i<i##_len;i++)
#define REPS(i,n) for(int i=1,i##_len=(int)(n);i<=i##_len;i++)
#define RREP(i,n) for(int i=(int)(n)-1;i>=0;i--)
#define RREPS(i,n) for(int i=(int)(n);i>0;i--)

//printf
#define PRINTD(d) printf("%d\n",(d))
#define PRINTS(s) printf("%s\n",(s))

//memset
#define m0(s) memset(s,0,sizeof(s))
#define ml(s) memset(s,63,sizeof(s))
#define fill(s,c) memset(s,c,sizeof(s))

typedef long long ll;
int Min(int a, int b) {
	return a<b ? a : b;
}

void Swap(char x[], int i, int j)
{
	int temp;

	temp = x[i];
	x[i] = x[j];
	x[j] = temp;
}

void ShowData(int x[], int left, int right)
{
	int i;
	for (i = left; i <= right; i++)printf("%d  ", x[i]);
	printf("\n");
}
void QSort(char x[], int left, int right, int n) {
	int i, j;	//左端,右端
	int pivot;	//軸

	i = left;
	j = right;
	pivot = x[(left + right) / 2];

	while (1) {
		if (n > 0) {				//n>0なら昇順、n<=0なら降順
			while ((x[i] < pivot) && (i <= right))i++;	//軸値より大きい要素
			while ((pivot < x[j]) && (i <= right))j--;	//軸値より小さい要素
		}
		else {
			while ((x[i] > pivot) && (i <= right))i++;	//軸値より小さい要素
			while ((pivot > x[j]) && (i <= right))j--;	//軸値より大きい要素
		}
		if (i >= j)	break;
		Swap(x, i, j);
		i++; j--;
	}
	//ShowData(x, left, right);

	if (left < i - 1)QSort(x, left, i - 1, n);
	if (j + 1 <  right)QSort(x, j + 1, right, n);
}


int main() {
	char s[101], t[101];
	scanf("%s %s", s, t);
	QSort(s, 0, strlen(s) - 1, 1);
	QSort(t, 0, strlen(t) - 1, 0);
	//ShowData(s, 0, strlen(s) - 1);
	int flag = 0;
	REP(i, Min(strlen(s), strlen(t))) {
		if (s[i] < t[i]) {
			flag = 1;
			break;
		}
		else if (s[i]>t[i]) {
			break;
		}
		if (i == strlen(s) - 1 && i != strlen(t) - 1) {
			flag = 1;
			break;
		}
	}
	if (flag)PRINTS("Yes");
	else PRINTS("No");
}
