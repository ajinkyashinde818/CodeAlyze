#include <stdio.h>
#include <string.h>
int main(void){
    int sa[120],ta[120] ;
    char s[120],t[120],z[30]="abcdefghijklmnopqrstuvwxyz" ;
    scanf ("%s%s",s,t) ;
    for (int i=0; i<strlen(s); i++ ){
        for (int j=0; j<30; j++ ){
            if ( s[i]==z[j] ){
                sa[i] = j ;
            }
        }
    }
    for (int i=0; i<strlen(s); i++ ){
        for (int j=i+1; j<strlen(s); j++){
            int tmp=0 ;
            if ( sa[i]>sa[j] ){
                tmp = sa[i] ;
                sa[i] = sa[j] ;
                sa[j] = tmp ;
            }
        }
    }
    for (int i=0; i<strlen(t); i++ ){
        for (int j=0; j<30; j++ ){
            if ( t[i]==z[j] ){
                ta[i] = j ;
            }
        }
    }
    for (int i=0; i<strlen(t); i++ ){
        for (int j=i+1; j<strlen(t); j++){
            int tmp=0 ;
            if ( ta[i]<ta[j] ){
                tmp = ta[i] ;
                ta[i] = ta[j] ;
                ta[j] = tmp ;
            }
        }
    }
    for (int i=strlen(s); i<120; i++){
        sa[i] = -999 ;
    }
    for (int i=strlen(t); i<120; i++){
        ta[i] = -999 ;
    }
    int cnt = 0;
    for (int i=0; i<120; i++){
        if ( sa[i]<ta[i] ){
            printf ("Yes\n") ;
            break ;
        } else if ( sa[i]>ta[i] ){
            printf ("No\n") ;
            break ;
        } else if ( cnt==119 ){
            printf ("No\n") ;
            break ;
        } else {
            cnt ++ ;
        }
    }
    return 0 ;
}
