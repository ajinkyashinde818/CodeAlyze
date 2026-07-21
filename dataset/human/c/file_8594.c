#include <stdio.h>

int main(){
	int N,a[100001];

	scanf("%d",&N);

	int i;
	for(i=1;i<=N;i++){
		scanf("%d",&a[i]);
	}

	int num=0,next=1,flag=0;
	for(i=1;i<=N;i++){

		next=a[next];
		if(next==2){
			num++;
			printf("%d",num);
			flag=1;
			break;
		}
		num++;
	}

	if(flag==0)printf("-1");

}
