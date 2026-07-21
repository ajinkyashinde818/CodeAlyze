#include <stdio.h>
const int MAX_SPOTS = 1000;

int abs(int a){
	if(a>=0)
		return a;
	else
		return -a;
}
int max(int a,int b){
	int ret;
	if(a>b)
		ret = a;
	else
		ret = b;
	return ret;
}
int main(){
// initialization phase
	int W,H,N;
	int Xbefore,Ybefore,X,Y;
	int i;
	int sum = 0;
// reading & summarizing phase
	scanf("%d%d%d", &W , &H , &N );
	scanf("%d%d", &Xbefore , &Ybefore );
	for(  i = 0  ;  i < N - 1  ;  i++  ){
		scanf("%d%d", &X , &Y);
		if( ( X - Xbefore ) * ( Y - Ybefore ) >= 0 )
			sum += max(abs(X-Xbefore),abs(Y-Ybefore));
		else
			sum += abs(X-Xbefore)+abs(Y-Ybefore);
		Xbefore = X; Ybefore = Y;
	}
// answer writing phase
	printf("%d\n",sum);
	return 0;
}
