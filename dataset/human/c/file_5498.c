#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
 
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<stdarg.h>
#include<malloc.h>


int IsPrime(int);

int p[1000001] = {0};

int main()
{
	int i, j, n, count, sum, buf[1000] = {0};
	for(i=2; i<=1000000; i++)
		p[i] = 1;
	j = 0;
	for(i=0; i<=1000; i++){
		if(IsPrime(i) == 1){
			buf[j] = i;
			j++;
		}
	}
	for(i=0; i<168; i++){
		for(j=2*buf[i]; j<=1000000; j+=buf[i])
			p[j] = 0;
	}

	while(1){
		scanf("%d", &n);
		if(n==0)
			break;
		sum=0;
		i=0;
		count=0;
		while(1){
			if(p[i] == 1){
				sum += i;
				count++;
			}
			if(count == n)
				break;
			i++;
		}
		printf("%d\n", sum);
	}

	return 0;
}


int IsPrime(int n)
{
    int i;
 
    if(n < 2)
        return 0;
    else if(n == 2)
        return 1;
 
    if(n % 2 == 0)
        return 0;
 
	for(i = 3; i * i <= n; i += 2){
         if(n % i == 0)
            return 0;
	}
    return 1;
}
