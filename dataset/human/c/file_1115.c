#include <stdio.h>

int mtoi(char *str)
{
    int i;
    int ret;
    
    i = ret = 0;
    while (str[i] != '\0'){
        switch(str[i]){
            case 'm':
            ret += (i - 1 >= 0 && '0' <= str[i - 1] && str[i - 1] <= '9' ? str[i - 1] - '0' : 1) * 1000;
            break;
            
            case 'c':
            ret += (i - 1 >= 0 && '0' <= str[i - 1] && str[i - 1] <= '9' ? str[i - 1] - '0' : 1) * 100;
            break;

            case 'x':
            ret += (i - 1 >= 0 && '0' <= str[i - 1] && str[i - 1] <= '9' ? str[i - 1] - '0' : 1) * 10;
            break;

            case 'i':
            ret += (i - 1 >= 0 && '0' <= str[i - 1] && str[i - 1] <= '9' ? str[i - 1] - '0' : 1);
            break;
        }
        i++;
    }
    
    return (ret);
}

void itom(int t, char *ret)
{
    int len;
    
    len = 0;
    if (t / 1000){
        if (t / 1000 != 1){
            ret[len++] = t / 1000+ '0';
        }
        ret[len++] = 'm';
        t %= 1000;
    }
    if (t / 100){
        if (t / 100 != 1){
            ret[len++] = t / 100+ '0';
        }
        ret[len++] = 'c';
        t %= 100;
    }
    if (t / 10){
        if (t / 10 != 1){
            ret[len++] = t / 10+ '0';
        }
        ret[len++] = 'x';
        t %= 10;
    }
    if (t){
        if (t != 1){
            ret[len++] = t + '0';
        }
        ret[len++] = 'i';
    }
    ret[len] = '\0';
}

int main(void)
{
    int a, b;
    char str[128];
    int i, t;
    
    scanf("%d", &t);
    
    for (i = 0; i < t; i++){
        scanf("%s", str);
        a = mtoi(str);
        scanf("%s", str);
        b = mtoi(str);
        
        itom(a + b, str);
        printf("%s\n", str);
    }
    
    return (0);
}
