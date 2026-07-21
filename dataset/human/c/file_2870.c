#include<stdio.h>
int main(){
    int k,s;
    scanf("%d %d",&k,&s);
    int sum=0;
    for(int x=0;x<=k;x++){
        for(int y=0;y<=k;y++){
        
            if(0<=(s-x-y)&&(s-x-y)<=k) sum++; 
        }
    }
    printf("%d",sum);
    printf("\n");
    return 0;
}
