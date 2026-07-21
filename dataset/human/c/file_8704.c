#include <stdio.h>
int a[100001];
int main(void){
	int N;
	scanf("%d",&N);
	int i,temp;
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}
	//a[1]から開始して、値が2になったら終了する
	//a[1]に入っている値を添え字にして飛んでいく
	int count = 0;
	int current = 1;
	int next = a[current];
	while(count<=N){
		count++;
		next = a[current];
		current = next;
		if(current == 2)break;
	}
	if(count<=N)printf("%d",count);
	else printf("-1");
	return 0;
}
