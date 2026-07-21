#include <stdio.h>
int main(void){
int n;
int A[2*n];
int i;
int temp;
temp=0;
scanf("%d",&n);
for (i=0;i<2*n;i++){
    scanf("%d",&A[i]);
}
for (i=0;i<2*n-5;){
    if (((A[i]==A[i+1])&&(A[i+2]==A[i+3]))&&(A[i+4]==A[i+5]))
        temp=1;
    i+=2;
}
if (temp==1)
    printf("Yes");
else
    printf("No");
}
