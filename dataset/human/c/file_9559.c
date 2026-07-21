#include <stdio.h>

int main()
{
    int pop;
    int days;
    int last;
    int eat[100];
    int cnt = 0;
    
    scanf("%d",&pop);
    scanf("%d %d",&days,&last);
    
    while(cnt < pop){
        scanf("%d",&eat[cnt]);
        cnt++;
    }
    
    cnt = 0;
    
    while(cnt < pop){
        last += 1 + (days-1)/eat[cnt];
        cnt++;
    }
    
    printf("%d",last);

    return 0;
}
