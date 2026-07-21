#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
int compare(const void *a,const void *b){
    if(*(int *)a>*(int *)b)return 1;
    return -1;
}
int main()
{   char s[100001];
    scanf("%s",s);
    int q;
    scanf("%d",&q);
    int flag=0,fn=0,rn=0;
    int  fadd[200001]={-1},radd[200001]={-1};
    for(int i=0;i<q;i++){
        int tmp;
        scanf("%d",&tmp);
        if(tmp==1){
            if(flag==1)flag=0;else flag=1;
        }else{
            int f;
            char a[2];
            scanf("%d",&f);
            scanf("%s",a);
            if(f==1&&flag==0){
                fadd[fn]=a[0]-'a';
                fn++;
            }else if(f==1&&flag==1){
                radd[rn]=a[0]-'a';
                rn++;
            }else if(f==2&&flag==0){
                radd[rn]=a[0]-'a';
                rn++;
            }else{
                fadd[fn]=a[0]-'a';
                fn++;
            }
        }
    }
  if(flag==0){
        for(int i=fn-1;i>=0;i--){
            printf("%c",fadd[i]+'a');
        }
        printf("%s",s);
        for(int i=0;i<rn;i++){
            printf("%c",radd[i]+'a');
        }
    }else{
        for(int i=rn-1;i>=0;i--){
        printf("%c",radd[i]+'a');
        }
        int l=strlen(s);
        for(int i=l-1;i>=0;i--){
            printf("%c",s[i]);
        }
        for(int i=0;i<fn;i++){
            printf("%c",fadd[i]+'a');
        }
    }
    

    return 0;
}
