#include<stdio.h>
#include<math.h>

int main(){
	int n;
	int val[200000];
	int ret = -pow(10,9);
	int max = 0;
	int max_i = 0;
	scanf("%d",&n);
	for(int i = 0; i < n; i++){
		scanf("%d",&val[i]);
		if(max <= val[i]){
			max = val[i];
			max_i = i;
		}
	}
	for(int i = 0; i < n - 1; i++){
		if(max_i == i){
			max = 0;
			max_i = 0;
			for(int u = i + 1; u < n; u++){
				if(max <= val[u]){
					max = val[u];
					max_i = u;
				}
			}
		}
		if(ret < max - val[i]){
			ret = max - val[i];
		}
	}
	
	printf("%d\n",ret);
	return 0;
}
