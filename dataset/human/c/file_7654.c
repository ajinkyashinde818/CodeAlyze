#include<stdio.h>
  
#define MAX_COUNT 10000
#define MIN_X     1
#define MAX_X     10000
  
int main(void)
{
    int x[MAX_COUNT];
    int i, j, tmp;
  
    for(i=0;i<MAX_COUNT;i++)
    {
        scanf("%d", &tmp);
 
        if(tmp == 0) break; 
        if(tmp < MIN_X || tmp > MAX_X) return -1;
  
        x[i] = tmp;
    }
  
    for(j=0;j<i;j++)
    {
        printf("Case %d: %d\n", j+1, x[j]);
    }
  
    return 0;
}
