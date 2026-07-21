#include <stdio.h>

int main(void){

    int s[100000],a1[200000],a2[200000];
    char c;
    int i,q,t,f,counter=1,sp1=0,sp2=0;
    int n = 0;

    while((c=getchar())!='\n'){
        s[n++] = (int)c;
    }
    //rewind(stdin);
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d",&t);
        if(t==1){
            counter*=-1;
        }else{
            scanf("%d %c",&f,&c);
            if(f==1){
                if(counter == 1){
                    a1[sp1++] = (int)c;
                }else{
                    a2[sp2++] = (int)c;
                }
            }else{
                if(counter == 1){
                    a2[sp2++] = (int)c;
                }else{
                    a1[sp1++] = (int)c;
                }
            }
            //rewind(stdin);
        }
        //rewind(stdin);
    }

    if(counter == 1){

        for(i=sp1-1;i>=0;i--){
            printf("%c",(char)a1[i]);
        }

        for(i=0;i<n;i++){
            printf("%c",(char)s[i]);
        }

        for(i=0;i<sp2;i++){
            printf("%c",(char)a2[i]);
        }

    }else{

        for(i=sp2-1;i>=0;i--){
            printf("%c",(char)a2[i]);
        }

        for(i=n-1;i>=0;i--){
            printf("%c",(char)s[i]);
        }

        for(i=0;i<sp1;i++){
            printf("%c",(char)a1[i]);
        }

    }

    return 0;
}
