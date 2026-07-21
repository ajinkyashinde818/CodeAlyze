#include <stdio.h>

int main()
{
    char s[5000],tmp[60];
    int i,j,H,W;
    int flg = 0;

    scanf("%d%d",&H,&W);
    for(i=0;i<5000;i++){
        s[i] = '.';
    }

    i = W + 3;
    while(i<(W+2)*(H+1)){
        scanf("%s",tmp);
        for(j=0;j<W;j++){
            s[i] = tmp[j];
            i++;
        }
        i += 2;
    }

    if( (H == 1 ) && ( W == 1 ) ){
        if( s[4] == '#' ){
            printf("Yes\n");
            return 0;
        }
        printf("No\n");
        return 0;
    }

    i = W + 3;
    while(i<(W+2)*(H+1)-1){
        for(j=0;j<W;j++){
            if( s[i] == '#' ){
                if( ( s[i-(W+2)] == '.' ) && ( s[i-1] == '.' ) && ( s[i+1] == '.' ) && ( s[i+(W+2)] == '.' ) ){
                    printf("No\n");
                    return 0;
                }
            }
            i++;
        }
        i += 2;
    }

    printf("Yes\n");

    return 0;
}
