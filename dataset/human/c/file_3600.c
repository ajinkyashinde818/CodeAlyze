#include <stdio.h>

int sosuu_list_num;
int sosuu_list[2000];

void make_sosuu_list(void) {
	char is_sosuu[2000];
	int i,j;
	for(i=0;i<2000;i++)is_sosuu[i]=1;
	is_sosuu[0]=is_sosuu[1]=0;
	for(i=2;i<2000;i++) {
		if(is_sosuu[i]) {
			for(j=i+i;j<2000;j+=i)is_sosuu[j]=0;
		}
	}
	for(i=0;i<2000;i++) {
		if(is_sosuu[i])sosuu_list[sosuu_list_num++]=i;
	}
}

int memo[15][2000][1121];

int tansaku(int rest,int next_use,int rest_num) {
	int i;
	int result=0;
	if(rest<=0)return (rest_num==0)?1:0;
	if(rest_num<0)return 0;
	if(memo[rest][next_use][rest_num]>0) {
		return memo[rest][next_use][rest_num]-1;
	}
	for(i=next_use;i<sosuu_list_num && sosuu_list[i]<=rest_num;i++) {
		result+=tansaku(rest-1,i+1,rest_num-sosuu_list[i]);
	}
	memo[rest][next_use][rest_num]=result+1;
	return result;
}

int main(void) {
	int n,k;
	make_sosuu_list();
	while(1) {
		scanf("%d%d",&n,&k);
		if(n==0 && k==0)break;
		printf("%d\n",tansaku(k,0,n));
	}
	return 0;
}
