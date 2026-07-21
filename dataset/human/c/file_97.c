#include <stdio.h>
void sort(int *a, int *b)
{
    int temp;
    if(*b>*a) {
        temp = *a;
        *a = *b;
        *b = temp;  
    }
}
int main(void)
{
    int r,g,b,n;
    scanf("%d %d %d %d",&r,&g,&b,&n);
    int first,second,third;
    if(r > g && r > b)  {
        first = r;
        if(g>b) {
            second = g;
            third = b;
        }
        else {
            second = b;
            third = g;
        }
    }

    else
    {
        if(g > b)   {
            first = g;
            if(r>b) {
                second = r;
                third = b;
            }
            else {
                second = b;
                third = r;
            }
        }
        else {
            first = b;
            if(r>g) {
                second = r;
                third = g;
            }
            else {
                second = g;
                third = r;
            }
        }
    }
    int ans,i,j;
    ans = 0;
    for(i = 0; i <= n/first; i ++) {  //i indicates the number of the balls in the box whose capacity is the bigeest//
        for (j = 0; j <= (n-i*first)/second; j ++)   {
            if((n-i*first-j*second) % third == 0)    {
                ans++;
            }
        }
    }
    printf("%d",ans);
}
