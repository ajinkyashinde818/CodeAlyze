#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_MAX 1000010

int min( int a, int b ){
    if ( a<b ) return a;
    else return b;
}

char s[N_MAX];
int d[N_MAX][2];

int main(){
    
    //整数を文字列として入力
    scanf("%1000000s",s);
    int len = strlen(s);
    
    int x = s[len-1] - '0';
    d[len-1][0] = x;
    d[len-1][1] = 11 - x;
    
    for ( int i=len-2; i>=0; i-- ){
        x = s[i] - '0';   //xにi桁目の数字を代入
        d[i][0] = min( d[i+1][0] + x, d[i+1][1] + x );
        d[i][1] = min( d[i+1][0] + 11 - x, d[i+1][1] + 9 - x );
    }
    
    int ans = min( d[0][0] , d[0][1] );
    printf("%d\n",ans);
    
    return 0;
    
}
