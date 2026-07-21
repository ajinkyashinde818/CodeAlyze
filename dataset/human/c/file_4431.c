#include <stdio.h>
#include <string.h>
int main()
{
    int n,i,c=0,a,b;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d%d",&a,&b);
        if(a==b){
            c++;
        }
        else{
            if(c<3){
                c=0;
            }

        }
    }
    if(c>=3){
    printf("Yes\n");}
    else{
        printf("No\n");
    }
    return 0;
}
