#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	long long int n = 0;
/*	long long int i = 0;	*/
	long long int x = 0;
	char* str;
	char* tmp;
	int j;
	long long int k = 1;
	int len;
	long long int div;
	long long int mod;

	str = (char*)calloc(100,sizeof(char));
	tmp = (char*)calloc(100,sizeof(char));
	scanf("%s",str);

	len = strlen(str);

	for(j=len-1; j>=0; j--){
		tmp[0] = str[j];
		tmp[1] = '\0';
		x += (long long int)atoi(tmp)*k;
		k *= 10;
	}

/*	printf("A%lld\n",x);	*/

	div = x/11;
	mod = x%11;

	n = div*2;

	if( mod > 0 ){
		n++;
		mod -= 6;
		if( mod > 0 ) n++;
	}

/*
	while( n < x ){
		i++;
		if( i%2 == 1 ){
			n += 6;
		}else{
			n += 5;
		}
	}
*/

	printf("%lld\n",n);

	return 0;
}
