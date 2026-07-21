//
//  main.c
//  King's Inspection
//
//  Created by x15071xx on 2016/06/17.
//  Copyright ?? 2016??´ AIT. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, const char * argv[]) {
    
    while (1) {
        
        int n,i,j,k,x,sa_keka;
        int key[100];
        char abc[101];
        char st[53];
        int len = 0,b=0;
        for (i=0; i<26; i++) {
            st[i] = 97 + i;
            st[i+26] = 65 + i;
        }
        
        for (i=0; i<26; i++) {
            st[i] = 97 + i;
            st[i+26] = 65 + i;
        }
        
        for (i=0; i< 52; i++) {
            key[i] = 0;
        }
        for (i=0; i<101; i++) {
            abc[i] = 0;
        }
        
        
        
        scanf("%d",&n);
        
        if (n==0) {
            break;
        }
        
        for (i=0; i<n; i++) {
            scanf("%d",&key[i]);
        }
        
        scanf("%s",abc);
        
        len = strlen(abc);
        for (i=0; i < len; i+=n) {
            
            for (j=0; j<n; j++) {
                if (i+j >= len) {
                    b=1;
                    break;
                }
                if (abc[i+j] >= 65 && abc[i+j] <=90) {
                    x = abc[i+j] - 65+26;
                    sa_keka = x - key[j];
                } else {
                    x = abc[i+j] - 97;
                    sa_keka = x - key[j];
                }
                
                if (sa_keka < 0) {
                    sa_keka +=52;
                }
                
                if (sa_keka > 52) {
                    sa_keka -= 52;
                }
                
                abc[i+j] = st[sa_keka];
            }
            if (b==1) {
                break;
            }
        }
        
        printf("%s\n",abc);
        
    }
    return 0;
}
