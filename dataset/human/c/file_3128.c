#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
static int desc(const void *a, const void *b);
static int asc(const void *a, const void *b);
 
int main (void){
    int n,k,i,j;
    int x,y,z;
    int a,b,m;
    int min = 2000000000;
    int mina = 2000000000;
    int minb = 2000000000;
    a = b = m = z = 0;
    int count = 0;
    double dx;
    int box_a[200001]={};
    int box_b[200001]={};
    char text[200001]={};
    char s[200001]={};
    char t[200001]={};
    char alf[256] = {"abcdefghijklmnopqrstuvwxyz"};
    char alfb[256] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char sample_text[256];
 
    // Input Area //
    scanf("%d %d",&k,&n);
    box_a[0] = 0;
    for (i = 1; i <= n; i++){
        scanf("%d",&box_a[i]);
        box_b[i-1] = box_a[i] - box_a[i - 1]; 
    }
    
    box_b[n] = k - box_a[n]; 

    
    qsort(box_b,n + 1,sizeof(int),asc);
    for (i = 0; i < n; i++){
       z = z + box_b[i];
    }
    if (box_a[n] - box_a[1] > z){
        printf("%d",z);
    }else{
        printf("%d",box_a[n] - box_a[1]); 
    }
    


    //scanf("%s %s",s,t);
    //scanf("%d %d",&x,&y);
    //scanf("%s",text);
 
    /*
    if(strcmp(text,s)==0){
        x--;
    }else if(strcmp(text,t)==0){
        y--;
    }
    */
    //printf("%d %d",x,y);
    //scanf("%s",&sample_text);
    //scanf("%s",&text);
 
    /*
    scanf("%d",&n);
    for(i = 0; i < n; i++){
        scanf("%d",&box[i]);
    }
    for(i = 0; i < n; i++){
        printf("%d",box[i]);
    }
    printf("\n");
    qsort(box,n,sizeof(int),desc);
    
    */
    // Output Area //
    
    /*
    for(i = 0; i < n; i++){
        printf("%d",box[i]);
    }
    */
 
}
 
static int desc(const void *a, const void *b){
    return *(int *) b - *(int *) a;
}
 
static int asc(const void *a, const void *b){
    return *(int *) a - *(int *) b;
}
 
 
/* KonoLvBANK
 
配列降順ソート
qsort(box,n,sizeof(int),desc);
配列昇順ソート
qsort(box,n,sizeof(int),asc);
 
アルファベットを次の単語に変えるやつ
    while(1){
        if (text[i] == '\0'){
            break;
        }
        for(j = 0; j < 26; j++){
            if (text[i] == alf[j]){
                if (j != 25){
                    text[i] = alf[j + 1];
                }else{
                    text[i] = alf[0];
                }
                break;
            }
        }
        i++;
    }
    */
