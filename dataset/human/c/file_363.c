#include<stdio.h>



void getData(int *n,int *r){
	fscanf(stdin,"%d%d",n,r);
}

int selectRate(int n, int r){
	if(n >= 10){
		return r;
	}
	else{
		return r + 100*(10-n);
	}
}

void solv(){
	int n,r;
	int Rate;
	getData(&n,&r);
	Rate = selectRate(n,r);
	printf("%d\n",Rate);
}	


int main(){
	solv();
	return 0;
}
