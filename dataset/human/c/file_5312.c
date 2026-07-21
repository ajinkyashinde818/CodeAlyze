#include<stdio.h>
#include<string.h>

int c[12];
int a[12][12];
int n,m;
int x;

int func(int num, int cost, int y_base[12]){
	int ret;
	int ret_p,ret_n;
	int i;	
	int f;
	int y[12] = {0,0,0,0,0,0,0,0,0,0,0,0};



	if(num == n-1){
		ret_n = 100000*20;

		f = 1;
		cost += c[num];
		for(i=0;i<m;i++){
			y[i] = y_base[i] + a[num][i];
			if(y[i] < x){
				f = 0;
			}
		}

		if(f==0){
			ret_p = 100000*20;
		}else{
			ret_p = cost;
		}

	}else{

		ret_n = func(num+1,cost,y_base);

		f = 1;
		cost += c[num];
		for(i=0;i<m;i++){
			y[i] = y_base[i] + a[num][i];
			if(y[i] < x){
				f = 0;
			}
		}

		if(f==0){
			ret_p = func(num+1,cost,y);
		}else{
			ret_p = cost;
		}
	}

	if(ret_p < ret_n){
		ret = ret_p;
	}else{
		ret = ret_n;
	}
		
	return ret;
}


int main(void){

	int i,j;
	int y[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int cost = 0;
	int ret;

	scanf("%d %d %d",&n,&m,&x);
	for(i=0;i<n;i++){
		scanf("%d",&c[i]);
		for(j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}


	ret = func(0,cost,y);

	if(ret == 100000*20){
		printf("-1\n");
	}else{
		printf("%d\n",ret);
	}


	return 0;
}
