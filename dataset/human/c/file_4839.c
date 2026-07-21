#include<stdio.h>
#define M 100001

typedef struct{
    int p,l,r;
}Node;

Node N[M];

int depth(int i,int d){
    if(N[i].p==-1)    return d;
    else return depth(N[i].p,++d);
}

int sib(int i){
    if(N[i].p==-1) return -1;
    if(N[N[i].p].r==i) return N[N[i].p].l;
    if(N[N[i].p].l==i) return N[N[i].p].r;
    return -1;
}

int deg(int i){
    int c=0;
    if(N[i].l!=-1) c++;
    if(N[i].r!=-1) c++;
    return c;
}

int hei(int i){
    int a=0,b=0;
    if(N[i].l!=-1) a=hei(N[i].l)+1;
    if(N[i].r!=-1) b=hei(N[i].r)+1;
    if(a>b) return a;
    else      return b;
}

int main(void){
    int i,n,id,c,l,r;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        N[i].p=-1;
        N[i].l=-1;
        N[i].r=-1;
    }
    
    for(i=0;i<n;i++){
        scanf("%d %d %d",&id,&l,&r);
        N[id].l=l;
        N[id].r=r;
        N[l].p=id;
        N[r].p=id;
    }
    
    for(i=0;i<n;i++){
        c=0;
        if(N[i].l!=-1) c++;
        if(N[i].r!=-1) c++;
        
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,N[i].p,sib(i),c,depth(i,0),hei(i));
        if(N[i].p==-1) printf("root");
        else if(N[i].l==-1 && N[i].r==-1) printf("leaf");
        else printf("internal node");
        printf("\n");
    }
    return 0;
}
