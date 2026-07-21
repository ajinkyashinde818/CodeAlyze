#include<stdio.h>
int main()
{
    int i,j,k,c=0,n,t,fixed,half,m;
    scanf("%d %d",&m,&n);
    int array1[n],array2[n],array[m];
    for(i=0;i<m;i++)
        array[i]=0;
    for(i=0;i<n;i++){
        scanf("%d %d",&array1[i],&array2[i]);
        if(array1[i]==1){
            array[array2[i]-1]=array2[i];
        }
    }
    fixed=m;
    for(i=0;i<n;i++){
        if(array2[i]==fixed){
            if(array[array1[i]-1]==array1[i]){
                c=1;
                break;
            }
        }
    }
    if(c==1)
        printf("POSSIBLE\n");
    else
        printf("IMPOSSIBLE\n");
    return 0;
}
