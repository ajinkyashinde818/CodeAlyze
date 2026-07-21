#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define num sizeof(a)/sizeof(int)
#define N 100000

int main(){
    char s[3*N],add[2],sagyou[3*N],emp[3*N];
    int q,size,t,f,number=0,i,ins,distin=0;
    scanf("%s%d",s,&q);
    s[N-1]='\0';
    strcpy(sagyou,s);
    for(size=0;s[size]!='\0';size++);

    while(q!=0){
        scanf("%d",&t);
        if(t==1){//反転
            distin+=1;
            distin%=2;
        }else if(t==2){//追加
            scanf("%d",&f);
            if((f==1 && distin%2==0) || (f==2 && distin%2)==1){
                //先頭追加(末尾追加でないと遅いので二つの配列を用いる)
                scanf("%s",add);
                strcat(emp,add);
                number++;
            }else if((f==2 && distin%2==0) || (f==1 && distin%2==1)){
                //末尾追加
                scanf("%s",add);
                strcat(sagyou,add);
                size++;
            }
        }
        q--;
    }

    if(distin%2==0){//後ろからか前からか
        for(i=number-1;i>=0;i--){
            putchar(emp[i]);
        }
        printf("%s\n",sagyou);
    }else{
        for(i=size-1;i>=0;i--){
            putchar(sagyou[i]);
        }
        printf("%s\n",emp);
    }
    return 0;
}
