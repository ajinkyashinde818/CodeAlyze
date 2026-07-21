#include<stdio.h>
#include<math.h>
int main(){
    double i,j,k,l,r;
    scanf("%lf %lf",&i,&j);
    k = i * j;
    if(i<j){
        l = i;
        i = j;
        j = l;
    }
    r=fmod(i,j);
    while(r != 0){
        i=j;
        j=r;
        r=fmod(i,j);
    }
    printf("%.0f",k/j);


}
