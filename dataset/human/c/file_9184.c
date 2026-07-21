#include <stdio.h>


int main()
{
    int i,N,k,h,s=0;
    scanf("%d %d", &N, &k);
    int polje[N];
    for (i=0;i<N;i++){
        scanf("%d", &polje[i]); 
    }
    for (i=0;i<N;i++){
       if (polje[i]>=k) s++;
       }
    printf("%d", s);   
    return 0;
}
