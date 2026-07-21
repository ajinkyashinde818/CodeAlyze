#include<stdio.h>
int main(){
    int g,e;
    int year;
    char c;
    scanf("%d %d",&g,&e);
    if(g==0){
        if(e>1988){
            year=e-1988;
            c='H';
        }else if(e>1925){
            year=e-1925;
            c='S';
        }else if(e>1911){
            year=e-1911;
            c='T';
        }else{
            year=e-1867;
            c='M';
        }
        printf("%c%d\n",c,year);
    }else if(g==1){
        year=e+1867;
        printf("%d\n",year);
    }else if(g==2){
        year=e+1911;
        printf("%d\n",year);
    }else if(g==3){
        year=e+1925;
        printf("%d\n",year);
    }else{
        year=e+1988;
        printf("%d\n",year);
    }
    return 0;
}
