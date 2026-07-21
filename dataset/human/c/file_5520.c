#include <stdio.h>

int isprime(int num){
	int i;

	for(i = 3;i*i <= num;i += 2){
		if(num%i == 0){
			return 0;
		}
	}

	return 1;
}

int main(){
	int n,cnt,num,sum;

	while(1){
		scanf("%d",&n);
		if(n == 0){
			break;
		}

		cnt = 1;
		sum = 2;
		num = 3;
		while(cnt != n){
			if(isprime(num)){
				sum += num;
				cnt++;
			}
			num += 2;
		}

		printf("%d\n",sum);
	}

	return 0;
}
