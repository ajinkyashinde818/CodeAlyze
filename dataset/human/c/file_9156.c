#include <stdio.h>
int main(void){
    // Your code here!
    int Nin,Hit,Sin[100001],For,Cou;
    
    scanf("%d%d",&Nin,&Hit);
    
    for(For=0;For<Nin;For++)
        scanf("%d",&Sin[For]);
    
    Cou = 0;    
    for(For=0;For<Nin;For++)
        if(Sin[For]>=Hit)
            Cou++;
    
    printf("%d",Cou);
    return 0;
}
