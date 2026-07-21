#include <stdio.h>
#include <math.h>
 
int main(void){
    int R,G,B;
    int N;
  	 scanf("%d", &R);
   	scanf("%d", &G);
   	scanf("%d", &B);
    scanf("%d", &N);//数値の取得
  	int i,j,k;
  int v;
  	int ans = 0;
  int sum = 0;
  
	for(i=0;i<N+1;i++){
		for(j=0;j<N+1;j++){
          v = i*R + G*j;
            if(v <= N && (N -v)%B == 0){
              ans++;
            }
          
        }
    }
    
    printf("%d",ans);
 
    return 0;
}
