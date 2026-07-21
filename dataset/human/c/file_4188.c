#include <stdio.h>

int gcd(int a,int b){int r,tmp;if(a < b){tmp = a;a = b;b = tmp;}r = a % b;while(r != 0){a = b;b = r;r = a % b;}return b;}


int main()
{
    int a,b,k,r,cnt = 0,ans = 0,i;
    scanf("%d %d %d",&a,&b,&k);
    r = gcd(a,b);
    i = r;
    while (cnt < k)
    {
        if(r % i == 0)
        {
            cnt++;
            ans = i;
        }
        i--;
    }
    
    printf("%d",ans);
}
