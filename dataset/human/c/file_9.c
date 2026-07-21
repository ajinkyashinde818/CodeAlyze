#include<stdio.h>


int main(void){
	
	int r,g,b,n;
	int i,j,k;
	int Rn,Gn;
	int count;
	
	scanf("%d %d %d %d",&r,&g,&b,&n);

	count = 0;

	for(i=0;i*r<= n;i++){
		Rn = i * r;
		for(j=0;j*g+Rn <= n;j++){
			Gn = j * g;
			if((n - (Gn + Rn)) % b == 0){
				count++;
//				printf("%d : %d %d %d\n",count,i,j,(n - (Gn + Rn)) / b);
			}
		}
	}

	printf("%d\n",count);


	return 0;
}
