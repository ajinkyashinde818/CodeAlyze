#include<stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	int a[n],b[n];
	int i,same=0;
	for (i=0;i<n;i++) scanf("%d",&a[i]);
	for (i=n-1;i>=0;i--) scanf("%d",&b[i]);
	int left=0, right=n-1;		
	i=0;
	//находим левую и правую границу одинаковых значений
	while ((a[i]!=b[i])&&(i<n)) i++;
	left=i;
	i=n-1;
	while ((a[i]!=b[i])&&(i>=0)) i--;
	right=i;
//	printf("left=%d right=%d\n", left,right);
	//если нет пересечений то форму пролетают и сразу печатаем массив
	int k,j;
	for (i=0,j=0;(i<left)&&(left+j<=right); i++) { 
		if((b[i]!=b[left+j])&&(a[i]!=b[left+j])){
			k=b[i]; 
			b[i]=b[left+j];
			b[left+j]=k;
			j++;
		}
	}
	i=j+left;
//	printf("i=%d\n",i);
//	for (i=0;i<n;i++) printf("%d ", b[i]);
	for (j=0;(i<=right)&&(right+j+1<n);j++) { 
		if ((b[i]!=b[right+j+1])&&(a[right+j+1]!=b[i])){
			k=b[i];
			b[i]=b[right+j+1];
			b[right+j+1]=k;
			i++;
		}
	}
	if (i<=right) printf("No\n");
	else {
		printf("Yes\n");
		for (i=0;i<n;i++) printf("%d ", b[i]);
	}
	return 0;
}
