#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include <assert.h>

int main(void){
		int a,b;
		int score;
		scanf("%d",&a);
		scanf("%d",&b);

		int c[b];
		for(int i = 0;i<b;i++){
			scanf("%d",&c[i]);
		}
int d[b];
		for(int j = 0;j<b-1;j++){
			d[j] =c[j+1]-c[j];
		}
int max = d[0];
for (int k = 1; k < b-1; k++) {
if (max < d[k]) {
		max = d[k];
}
}
int e;
e = a+c[0]-c[b-1];
if(e>max){
	score = a-e;
}else{
score = a - max;
}


printf("%d\n",score);

		return 0;
}
