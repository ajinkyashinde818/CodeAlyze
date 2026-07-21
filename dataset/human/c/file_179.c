#include <stdio.h>
#include <string.h>

int main(void)
{
    int Q;
    unsigned int s;
    double out;
    int i, j;
    double a;
    char outs[100];
    
    scanf("%d", &Q);
    for (i = 0; i < Q; i++){
        scanf("%x", &s);
        
        out = (s & 0x7fffffff) >> 7;
        if ((s & 0x80000000) != 0){
            printf("-");
        }
        
        a = 0.5;
        for (j = 0; j < 7; j++){
            if ((s & (0x40 >> j)) != 0){
                out += a;
            }
            a /= 2;
        }
        
        sprintf(outs, "%.8lf", out);
        for (j = strlen(outs) - 1; outs[j] == '0'; j--){
            outs[j] = '\0';
        }
        if (outs[j] == '.'){
            outs[j + 1] = '0';
        }
        printf("%s\n", outs);
    }
    
    return (0);
}
