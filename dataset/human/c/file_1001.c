#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void){
    int i,keyn,key[101];
    char code[101];
    char station[53]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int kingpos;
    while(scanf("%d",&keyn)!=EOF && keyn!=0){
        for(i=0;i<=keyn;i++){
            scanf("%d ",&key[i]);
        }
        scanf("%s",code);
        for(i=0;i<=strlen(code)-1;i++){
            if(islower(code[i]))kingpos=code[i]-'a'-key[i%keyn];
            else kingpos=code[i]-'A'+26-key[i%keyn];
            if(kingpos<0)kingpos+=52;
            printf("%c",station[kingpos]);
        }
        printf("\n");
    }
    return 0;
}
