#include<stdio.h>
#include<stdbool.h>

int main(void){

	int n;
	int a[100001];
	int ans = 0;
	int b = 1;
	bool f = false;

	scanf("%d", &n);

	for(int i= 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++){

		b = a[b-1];
		ans++;

		if(b==2){
			f = true;
			break;
		}


		


	}

	if(f == false){
		ans = -1;
	}

	printf("%d", ans);

	return 0;
}
