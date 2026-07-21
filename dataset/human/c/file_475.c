#include <stdio.h>
        #include <math.h>
         
        int main(void){
        	int n;
        	scanf("%d",&n);
        	double c[n];
        	scanf("%lf",&c[0]);
        	double sum = 0;
        	for (int i = 1 ; i<n ; i++){
        		scanf("%lf",&c[i]);
        		sum += c[i];
        	}
        	double sa = sum - c[0];
        	double min = fabs(sa);
        	 for (int i = 1; i< n-1;i++){
        	 	sa -= c[i]*2;
        	 	if (min > fabs(sa)){
        	 		min = fabs(sa);
        	 	}
        	 }
        	 printf("%.0lf\n",min);
        	return (0);
        }
