#include <stdio.h>
#include <string.h>

int main(void)
{
    char S[100001],T[100001]={};
    char *Tc[4]={"dream","dreamer","erase","eraser"}; //Tに入る要素
    int Tclen[4]={5,7,5,6};
    int Slen,count=0,Tlen=0; 

    scanf("%s",S);
    //printf("%s\n",S);
    Slen = strlen(S);

    //for(int i=0;i<4;i++)printf("Tc[%d] = %s\n",i,Tc[i]);

    while(Slen>0){
        count=0;
        for(int i=0;i<4;i++){
            //printf("%s\n",Tc[i]);
            if(strncmp(Tc[i],S+Slen-Tclen[i],Tclen[i])==0){Slen -= Tclen[i];/*printf("%d\n",Slen);*/break;}
            count++;
        }
        if(count ==4)break;
    }
    
    if(Slen==0){
		printf("YES\n");
	}else if(Slen!=0){
		printf("NO\n");
	}
    return 0;

}
