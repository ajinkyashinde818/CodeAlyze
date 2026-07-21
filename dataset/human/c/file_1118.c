#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int todec(char mcxi[]);
void tom(char res[], int num);

int main(void)
{
    int i, n;
    scanf("%d", &n);
    getchar();

    for(i = 0; i < n; i++){
        char line[100];
        gets(line);
        char *p = line;
        while(*p != ' ')
            p++;
        char mcxi1[100], mcxi2[100];
        *p = '\0';
        p++;
        strcpy(mcxi1 + 1, line);
        strcpy(mcxi2 + 1, p);

        int res = todec(mcxi1 + 1) + todec(mcxi2 + 1);

        char result[100];
        tom(result, res);
        printf("%s\n", result);
    }

    return 0;
}

int todec(char mcxi[])
{
    char *p = mcxi;
    int ret = 0;
    while(*p != '\0'){
        if(isalpha(*p)){
            int base;
            switch(*p){
                case 'm':
                    base = 1000;
                    break;
                case 'c':
                    base = 100;
                    break;
                case 'x':
                    base = 10;
                    break;
                case 'i':
                    base = 1;
                    break;
                default:
                    printf("err\n");
                    break;
            }
            if(isdigit(*(p - 1))){
                    char ch = *(p - 1);
                    ret += (ch - '0') * base;
            }else{
                ret += base;
            }
        }
        p++;
    }
    return ret;
}

void tom(char res[], int num)
{
    int m, c, x, i;
    i = num % 10;
    num /= 10;
    x = num % 10;
    num /= 10;
    c = num % 10;
    num /= 10;
    m = num % 10;
    //printf("m: %d\n", m);
    //printf("c: %d\n", c);
    //printf("x: %d\n", x);
    //printf("i: %d\n", i);

    char ms[3];
    char cs[3];
    char xs[3];
    char is[3];
    res[0] = '\0';

    if(m == 1){
        ms[0] = 'm';
        ms[1] = '\0';
        strcat(res, ms);
    }else if(m > 1){
        ms[0] = m + '0';
        ms[1] = 'm';
        ms[2] = '\0';
        strcat(res, ms);
    }
    if(c == 1){
        cs[0] = 'c';
        cs[1] = '\0';
        strcat(res, cs);
    }else if(c > 1){
        cs[0] = c + '0';
        cs[1] = 'c';
        cs[2] = '\0';
        strcat(res, cs);
    }
    if(x == 1){
        xs[0] = 'x';
        xs[1] = '\0';
        strcat(res, xs);
    }else if(x > 1){
        xs[0] = x + '0';
        xs[1] = 'x';
        xs[2] = '\0';
        strcat(res, xs);
    }
    if(i == 1){
        is[0] = 'i';
        is[1] = '\0';
        strcat(res, is);
    }else if(i > 1){
        is[0] = i +'0';
        is[1] = 'i';
        is[2] = '\0';
        strcat(res, is);
    }
}
