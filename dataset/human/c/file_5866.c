#include<stdio.h>
#define N 200000 

int main(void){
int Rt[N], RMAX = 0, RANS = 0, R;
int n, s;
int i, j, k = -1;

scanf("%d",&n);
for(i = 0; i < n; i++){
scanf("%d", &s);
Rt[i] = s;
}	
	RANS = Rt[1] - Rt[0];
for( i = 0; i < n-1; i++){
	RMAX = Rt[i + 1];
		if (k < i){
for( j = i + 1; j < n; j++){
	if( Rt[j] > RMAX) {
		RMAX = Rt[j];
		k = j;
}
		}
		}
			else RMAX = Rt[k];
	R = RMAX - Rt[i] ;
	if(RANS < R)RANS = R;
}
printf("%d\n", RANS);



return 0;
}
