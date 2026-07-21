#include<stdio.h>

int main(void){
        int e, y;
        scanf("%d %d", &e, &y);

        if(e==1) printf("%d\n", 1867+y);
        else if(e==2) printf("%d\n", 1911+y);
        else if(e==3) printf("%d\n", 1925+y);
        else if(e==4) printf("%d\n", 1988+y);
        else{
                if(1988<y) printf("H%d\n", y-1988);
                else if(1925<y) printf("S%d\n", y-1925);
                else if(1911<y) printf("T%d\n", y-1911);
                else printf("M%d\n", y-1867);
        }
        return 0;
}
