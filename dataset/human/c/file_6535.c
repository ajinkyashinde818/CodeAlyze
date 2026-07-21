#include <stdio.h>

int main(){
        char  line[20], line2[20];
        int   R[200000];
        int   i, n;
    int   min, max = -999999999;

        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &n);

        for(i = 0; i < n; i++){
                fgets(line2, sizeof(line2), stdin);
                sscanf(line2, "%d", &R[i]);
        }
        min = R[0];
        for(i = 1; i < n; i++ ){
                if(max < (R[i] - min)) max = R[i] - min;
                if(min > R[i]) min = R[i];
        }

        //if(max < (R[i] - min)) max = R[i] - min;
        printf("%d\n", max);


        return 0;
}
