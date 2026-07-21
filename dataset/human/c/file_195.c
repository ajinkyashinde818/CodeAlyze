/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int A[100000]={};

int main()
{
    int n;
    scanf("%d",&n);
    int i;
    int mc = 0;
    long long sum = 0;
    long long lmin = -1000000000;
    long long rmin = 1000000000;
    long long min = 0;
    for(i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(A[i]<0){
            mc++;
            if(lmin<A[i]){
                lmin = A[i];
            }
        }
        else{
            if(rmin>A[i]){
                rmin = A[i];
            }
        }
    }
    if(lmin==0 || rmin ==0)min = 0;
    else if((-lmin)>rmin)min = rmin;
    else min = -lmin;
    //printf("%d %d\n",lmin,rmin);
    for(i=0;i<n;i++){
        if(A[i]>0)
            sum+=A[i];
        else
            sum+=(-A[i]);
    //printf("%lld\n",sum);
    }
    if(mc%2 != 0){
        
        sum = sum-2*min;
    }
    printf("%lld",sum);
    return 0;
}
