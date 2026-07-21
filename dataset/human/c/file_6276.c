#include <stdio.h>
int main(){
    int str[200000],max,min;
    int j,i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",&str[i]);
    min=str[0];
    max=str[1]-str[0];
    for(j=1;j<n;j++){
        if(max<str[j]-min)
            max=str[j]-min;
         
        if(min>str[j])
            min=str[j];
    }
    printf("%d\n",max);
     
    return 0;
}
