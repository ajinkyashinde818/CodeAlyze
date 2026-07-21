#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include<math.h>
int main(){
    int n;
    scanf("%d", &n);
    int cont=0, yes=0;
    for(int i =0;i< n;++i){ 
        int a=0, b=0;
        scanf("%d %d", &a, &b);
        if(a==b)
            cont++;
        else
            cont=0 ; 
        if(cont>=3){
            yes=1;
        }
    }
    if(yes == 1)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
