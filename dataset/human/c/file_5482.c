#include<stdio.h>
#include<math.h>
int isprime(int x){
	int i;
	if(x == 2){
 		return 1;
	}
  	if(x<2||x%2==0){
		return 0;
	}
	i = 3;
	while( i <= sqrt(x) ){
		if(x%i==0){
			return 0;
		}
		i = i + 2;
	}
	return 1;
}
int main()
{
	int n,c=0,l[10001]={0},j=0;
	for(int i=0;i<=104730;i++){
		if(isprime(i)){
			c+=i;
			l[j]=c;
			j++;
		}
	}
	while(1){
		scanf("%d",&n);
		if(n==0){
			break;
		}
		printf("%d\n",l[n-1]);
	}
	return 0;
}
