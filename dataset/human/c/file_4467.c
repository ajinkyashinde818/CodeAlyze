#include <stdio.h>
#include <string.h>

int main()
{
    int N;
    int D1,D2;
    int count,flag;
    int i;

    count=0;
    flag=0;

    scanf("%d\n",&N);

    for(i=0;i<N;i++){
        scanf("%d %d\n",&D1,&D2);

        if(D1==D2){
            count++;

            if(count==3){
                flag++;
            }
        }
        else{
            if(count>0){
                count=0;
            }
        }
    }

    if(flag>0){
        printf("Yes\n");
    }
    else{
        printf("No\n");
    }
 
    return 0;
}
