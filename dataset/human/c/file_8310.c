#include <stdio.h>

int main(void)
{

    int n,k;
    char dif;
    
    scanf("%d",&n);
    char array[n];
    scanf("%s",array);
    scanf("%d",&k);

    dif=array[k-1];

    for(int i=0;i<n;i++){
        if(array[i]!=dif){
            array[i]='*';
        }
    }

    for(int i=0;i<n;i++){
        printf("%c",array[i]);
    }

    return 0;
}
