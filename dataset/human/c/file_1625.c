#include<stdio.h>
#define rep(i,n) for(int i=0;(i)<(n);(i)++)
int count(int i,char s[1000][1052]){
    int ans=0;
    for(int j=0;;j++){
        if(s[i][j]==' '){
            ans++;
        }
        else{
            break;
        }
    }
    return ans;
}
/*void space(int i,char s[1000][1052]){
    for(int j=0;j<1052;j++){
        if(s[i][j]=='.'){
            s[i][j]=' ';
        }
    }
}*/
void space(int i,char s[1000][1052]){
    for(int j=0;;j++){
        if(s[i][j]=='.'){
            s[i][j]=' ';
        }
        else{
            break;
        }
    }
}
char s[1000][1052]={0};
int main(void){
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0) break;
        getchar();
        rep(i,n) fgets(s[i],1052,stdin);
        rep(i,n) space(i,s);
        //rep(i,n) printf("%s",s[i]);
        for(int i=1;i<n;i++){
            int idx=count(i,s);
            s[i][idx-1]='+';
            //直信
            if(count(i-1,s)<=idx-1);
            else{
                for(int j=i-1;j>=0;j--){
                    if(s[j][idx-1]=='+'){
                        break;
                    }else{
                        s[j][idx-1]='|';
                    }
                }
            }
        }
        rep(i,n) printf("%s",s[i]);
    }
}
