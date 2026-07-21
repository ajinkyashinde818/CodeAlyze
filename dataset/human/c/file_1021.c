#include <stdio.h>

int main (void){

        int n, i,j;
        char cryp[101];
        int key[100];
        char c;

        while(1){
                scanf("%d",&n);
                        if(n == 0)
                                break;

                for(i = 0; i < n; i++)
                        scanf("%d ",&key[i]);
                scanf("%s",cryp);

                for(i = 0; cryp[i]; i++){
                        c = cryp[i];
                        for(j = 0; j < key[i%n]; j++){
                                if(c == 'a')
                                        c = 'Z';
                                else if(c == 'A')
                                        c = 'z';
                                else
                                        c -= 1;
                        }
                        printf("%c",c);
                }
                puts("");
        }

        return 0;
}
