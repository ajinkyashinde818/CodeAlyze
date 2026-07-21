#include <stdio.h> 
int main(void) 
{ 
    int n, d, x, a[1000], i, j, s=0;
    
    scanf("%d%d%d",&n,&d,&x);
    for(i=0;i<n;i++) scanf("%d",&a[i]);
    
    for(i=0;i<n;i++){
        j=1;
        while(j<=d){
            s++;
            j+=a[i];
        }
    }
    s=s+x;
    printf("%d\n",s);
    return 0;
}
