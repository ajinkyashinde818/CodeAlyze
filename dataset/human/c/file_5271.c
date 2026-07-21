#include<stdio.h>
#include<stdlib.h>

typedef struct node_
{
    int parent;//親
    int sibling;//兄弟
    int degree;//子の数
    int depth;//深さ
    int height;//高さ
    int lf; //左ノード
    int rh; //右ノード
} node;

void init_x(node *X,int no)
{
    X[no].parent = -1;
    X[no].sibling = -1;
}

void input_x(node *X,int no,int rh,int lf)
{
    X[no].lf = lf;
    X[no].rh = rh;
}

void degree_sibling(node *X,int no)
{
    if(X[no].lf==-1&&X[no].rh==-1){
        X[no].degree = 0;
        }else if(X[no].lf>=0&&X[no].rh>=0){
            X[no].degree = 2;
            X[X[no].lf].sibling = X[no].rh;
            X[X[no].rh].sibling = X[no].lf;
        }else {
            X[no].degree = 1;
        }
}

void parent_x(node *X,int No)
{
    switch(X[No].lf){
        case -1:
            break;
        default:
            X[X[No].lf].parent = No;
            //fprintf(stderr,"%d lf=%d chk\n",No,X[No].lf);
            break;
    }
    switch(X[No].rh){
        case -1:
            break;
        default:
            X[X[No].rh].parent = No;
            //fprintf(stderr,"%d rh=%d chk\n",No,X[No].rh);
            break;
    }
}

int depth_chk(node *X,int no)
{
    int cnt=0;
    while(X[no].parent != -1)
    {
        no = X[no].parent;
        cnt ++;
    }
    //fprintf(stderr,"No.%d cnt=%d\n",no,cnt);
    return cnt;
}

int main()
{
    int n,d1=0,d2=0,No,dep=0,cnt;
    scanf("%d",&n);
    node *X = malloc(sizeof(node)*n);
    //fprintf(stderr,"\nchk start\n");
    for(int i=0;i<n;i++) init_x(X,i);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&No,&d1,&d2);
        input_x(X,No,d1,d2);
        degree_sibling(X,No);
        parent_x(X,No);
        //fprintf(stderr,"node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d\n",i,X[No].parent,X[No].sibling,X[No].degree,X[No].depth,X[No].height);
    }
    for(int i=0;i<n;i++){
        X[i].depth = depth_chk(X,i);
        if(X[i].depth > dep) dep = X[i].depth;
    }
    for(int j=dep;j>=0;j--)
    {
        for(int i=0;i<n;i++)
        {
            cnt = 0;
            if(X[i].depth==j)
            {
                if(X[i].lf!=-1)
                {
                    if(cnt<X[X[i].lf].height+1) cnt = X[X[i].lf].height+1;
                }
                if(X[i].rh!=-1)
                {
                    if(cnt<X[X[i].rh].height+1) cnt = X[X[i].rh].height+1;
                }
                X[i].height = cnt;
                //fprintf(stderr,"node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d\n",i,X[i].parent,X[i].sibling,X[i].degree,X[i].depth,X[i].height);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d",i,X[i].parent,X[i].sibling,X[i].degree,X[i].depth,X[i].height);
        if(X[i].parent == -1||X[i].degree != 0)
        {
            if(X[i].sibling==-1&&X[i].parent == -1)    printf(", root");
            else    printf(", internal node");
           
        }else    printf(", leaf");
        printf("\n");
    }
    //fprintf(stderr,"chk end");
    free(X);
}
