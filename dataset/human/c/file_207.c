#include<stdio.h>
#include<stdlib.h>

int main(void){
    int num;
    double a[100000];
    unsigned int minus_cnt=0;
    double sum=0;
    double min;
    
    scanf("%d",&num);
    if(num<2) return -1;
    for(int i=0; i<num; i++){
        scanf("%lf",&a[i]);
    }
    min = abs(a[0]);
    
    for(int i=0; i<num; i++){
        if(a[i]<0){
            minus_cnt++;
        }
        sum += abs(a[i]);
        
        if(min > abs(a[i])) min=abs(a[i]);
    }
    
    if(minus_cnt%2==0){
        printf("%.0lf\n",sum);
    }else{
        printf("%.0lf\n",sum-(2*min));
    }
  
    return 0;
}
