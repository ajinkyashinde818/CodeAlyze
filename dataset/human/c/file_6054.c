#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    int i;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    int min=a[0];
    int samax=-1000000000;
    for(i=1;i<n;i++){
        if(samax<a[i]-min)
            samax=a[i]-min;
        if(min>a[i])
            min=a[i];
    }
    
    printf("%d\n",samax);
}
