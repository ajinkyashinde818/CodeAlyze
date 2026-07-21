#include <stdio.h>

int a[100005];
int button[100005];

int main(){

	int N;

	scanf("%d",&N);

	int i;

	for(i=1;i<=N;i++){
	scanf("%d",&a[i]);
	}

	i=1;

	int ans=0;

	while(1){

		if(i==2){break;}

		if(button[i]==1){
			printf("-1\n");
			return 0;
		}

		button[i]=1;
		i=a[i];
		ans++;
	
	}

	printf("%d\n",ans);

	return 0;
}
