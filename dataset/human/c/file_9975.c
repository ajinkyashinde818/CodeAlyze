#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define N 200001
#define MAX 100005
#define NI -1

typedef struct node{
    int l,p,r;
} node;
node T[MAX];
int n,D[MAX];
void print(int u){
    int i,c;
    printf("node %d: parent = %d, depth = %d, ",u,T[u].p,D[u]);
    if(T[u].p == NI){printf("root, ");}
    else if(T[u].l == NI){printf("leaf, ");}
    else{printf("internal node, ");}
    printf("[");

    for(i=0,c=T[u].l;c != NI;i++,c=T[c].r){
        if(i)
            printf(", ");
        printf("%d",c);
    }
    printf("]\n");
}

int rec(int u,int p){
    D[u]=p;
    if(T[u].r != NI){rec(T[u].r,p);}
    if(T[u].l != NI){rec(T[u].l,p+1);}
}


int main(void){
    int o,d,z,c,l,r,i;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        T[i].p=T[i].l=T[i].r=NI;
      }
    for(i=0;i<n;i++){
        scanf("%d %d",&z,&d);
        for(o=0;o<d;o++){
            scanf("%d",&c);
            if(!o){T[z].l=c;}
            else{ T[l].r=c;}
            l=c;
            T[c].p=z;
        }
    }
    for(i=0;i<n;i++){
        if(T[i].p == NI){r=i;}
          }
    rec(r,0);
    for(i=0;i<n;i++)
        print(i);
    return 0;
}
