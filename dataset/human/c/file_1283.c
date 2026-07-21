#include <stdio.h>

int dim(int a,int b){
	return (a > b) ? 0 : (b-a);
}

int check(int *data,int *num,int p){
	int i,n;

	n = 0;
	for(i = 0;i < 8;i++){
		n += dim(data[(i+p)%8],num[i]);
	}

	return n;
}

int main(){
	int i,j,min,n,num,tmp,ans;
	int p[8],c[8];

	while(scanf("%d",&p[0]) != EOF){
		min = p[0];
		c[0] = 1;
		num = 2121414;
		for(i = 1;i < 8;i++){
			scanf("%d",&p[i]);
			min += p[i];
			c[i] = num%10;
			num /= 10;
		}

		for(i = 0;i < 8;i++){
			n = check(c,p,i);
			tmp = 0;
			for(j = 0;j < 8;j++){
				tmp *= 10;
				tmp += c[(i+j)%8];
			}

			if(min > n){
				min = n;
				num = tmp;
				ans = i;
			}else if(min == n){
				if(num > tmp){
					num = tmp;
					ans = i;
				}
			}
		}

		for(j = 0;j < 8;j++){
			printf("%d%c",c[(ans+j)%8],(j == 7) ? '\n' : ' ');
		}
	}

	return 0;
}
