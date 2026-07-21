#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int b[n];
    int c[n-1];
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
    scanf("%d",&b[i]);
    for(int i=0;i<n-1;i++)
    scanf("%d",&c[i]);
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=b[a[i]-1];
       // printf("%d    %d\n",i,sum);
        if(i!=0 && (a[i]-1)==a[i-1]){
            sum+=c[a[i-1]-1];

           // printf(" .%d. ",c[a[i-1]]);
        }
      //  printf("%d   %d\n",i,sum);
    }
    printf("%d",sum);
}
