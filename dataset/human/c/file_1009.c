#include<stdio.h>
#include<string.h>
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
int main(void){
    char alp[53]="";
    rep(i,26){
        alp[i]='a'+i;
    }
    rep(i,26){
        alp[i+26]='A'+i;
    }
    //printf("%s\n",alp);
    while(1){
        int n; int list[100];
        scanf("%d",&n);
        if(n==0) break;
        rep(i,n) scanf("%d",&list[i]);
        getchar();
        char s[102]="";
        scanf("%s",s);
        //printf("%s len:%lu\n",s,strlen(s));
        int len=strlen(s);
        for(int i=0;i<len;i++){
            int key=list[i%n];
            if('A'<=s[i]&&s[i]<='Z'){
                char c=alp[(26+s[i]-'A'-key+52*2)%52];
                s[i]=c;
            }
            else{
                char c=alp[(s[i]-'a'-key+52*2)%52];
                s[i]=c;
            }
        }
        printf("%s\n",s);
    }
}
