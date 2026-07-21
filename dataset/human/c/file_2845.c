# include"stdio.h"
int main(){
    int k,s,cou=0,x;
    scanf("%d %d",&k,&s);
    for(int i=0;i<k+1;i++)
        for(int j=0;j<k+1;j++){
               x=s-i-j;
                if(x>=0&&x<=k)  cou++;
        }
    printf("%d\n",cou);
}
