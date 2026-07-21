#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main() {
    char str[300001];
    char str_mae[300001]={};
    char str_ato[300001]={};
    int Q;
    int q1;
    int q2;
    char q3;
    int count = 0;
    int count_mae = 0;
    int count_ato = 0;
    int count_str = 0;

    scanf("%s", &str);
    count_str = strlen(str);

    scanf("%d", &Q);

    for (int i = 0; i < Q; ++i) {
        scanf("%d",&q1);
        if(q1 == 1){
            count++;
        }
        else{
            scanf("%d %c",&q2,&q3);
            if(( q2 + count) % 2 == 1){
                str_mae[count_mae] = q3;
                count_mae++;
            }
            else{
                str_ato[count_ato] = q3;
                count_ato++;
            }
        }
    }

    if(count % 2 == 0){
        for(int i = 0; i < count_mae; ++i){
            printf("%c",str_mae[count_mae-1-i]);
        }
        printf("%s",str);
        printf("%s",str_ato);
        }
    else{
        for(int i = 0; i < count_ato; ++i){
            printf("%c",str_ato[count_ato-1-i]);
        }
        for(int i = 0; i < count_str; ++i){
            printf("%c",str[count_str-1-i]);
        }
        printf("%s",str_mae);
    }
}

int A(){
    char S[3];
    scanf("%s",&S);
    if(S[0] != S[1] || S[0] != S[2] || S[1] != S[2]){
        printf("Yes");
    }
    else{
        printf("No");
    }
    return 0;
}

int B(){
    long long int  N;
    long long int RED,BLUE;
    long long int count;

    scanf("%lld %lld %lld",&N,&RED,&BLUE);
    count = N /(RED+BLUE) ;
    if(N % (RED +BLUE) >=RED){
        printf("%lld",count*RED +RED);
    }
    else{
        printf("%lld",count*RED + (N%(RED +BLUE)) );
    }
    return 0;
}

int C(){
    int tax8,tax10;
    int a,b;

    scanf("%d %d",&tax8,&tax10);

    for(int i = 1; i <= 10000; ++i){
        a = i * 0.08;
        b = i * 0.1;
        if(tax8 == a && tax10 == b){
            printf("%d",i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}
