#include<stdio.h>
#define A 200000
int main(){
	
    int n,i,j,k;
    int R[A];
    
	/* nを格納 */
    scanf("%d",&n);
	
	/* R[i]をn個格納 */
    for(i=0;i<n;i++){
        scanf("%d",&R[i]);
    }
     
    for(i=0;i<n-1;i++){
    	
        if(i==0||j>R[i]){/* 最小値を探し、jに格納 */
            j=R[i];
        }
        if(i==0||k<R[i+1]-j){/* 差の値の大きい方を格納 */
            k=R[i+1]-j;
        }
    }
	
    printf("%d\n",k);/* 最大の差を格納 */
     
    return 0;
}
