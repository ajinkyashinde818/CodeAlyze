/************************************************************
 * ???????????±???????????????
 ***********************************************************/
#include <stdio.h>

int main(){
        int x, count = 1;
        char line[30];
        while(1){

                fgets(line, sizeof(line), stdin );
                sscanf(line, "%d", &x );

                if(x == 0 ) break;
                printf("Case %d: %d\n", count, x);
                ++count;

        }




        return 0;
}
