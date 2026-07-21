#include <stdio.h>
#include <string.h>

int main(){
    char    s[100+1]={0}, t[100+1]={0}, x;
    scanf("%s %s", s, t);

    //s
    for(int i=0; s[i]!=0; i++){
        for(int j=i+1; s[j]!=0; j++){
            if( s[i] > s[j] ){
                x    = s[i];
                s[i] = s[j];
                s[j] = x;
            }
        }
    }

    //t
    for(int i=0; t[i]!=0; i++){
        for(int j=i+1; t[j]!=0; j++){
            if( t[i] < t[j] ){
                x    = t[i];
                t[i] = t[j];
                t[j] = x;
            }
        }
    }

    if( strcmp(s,t) < 0 ){ printf("Yes\n"); }
    else                 { printf("No\n");  }
    return 0;
}
