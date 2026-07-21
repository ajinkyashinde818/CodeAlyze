#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>

typedef struct{
    int parent;
    int depth;
    int height;
    int right;
    int left;
    int deg;
    char *type;
    int sibling;
    bool done_f;
}Node;

void input(Node*,int);
void allprint(Node*,int);
void depthjud(Node*,int);
void heightjud(Node*,int,int);
void _depthjud(Node*,int);

const char* root="root";
const char* internal="internal node";
const char* leaf="leaf";

int main(){
    int max;
    Node *np;

    scanf("%d",&max);
    np=malloc(sizeof(Node)*max);
    for(int i=0;i<max;i++){
        (np+i)->parent=-1;
        (np+i)->sibling=-1;
    }
    input(np,max);
    _depthjud(np,max);
    //depthjud(np,max);
    allprint(np,max);


    return 0;

}

void input(Node* np,int max){
    int node_num;
    int left;
    int right;
    int deg_c;

    for(int i=0;i<max;i++){
        deg_c=0;
        scanf("%d",&node_num);
        scanf("%d%d",&left,&right);
        (np+node_num)->right=right;
        (np+node_num)->left=left;
        if(left!=-1){
            (np+left)->parent=node_num;
            deg_c++;
        }
        if(right!=-1){
            (np+right)->parent=node_num;
            deg_c++;
        }
        (np+node_num)->deg=deg_c;
    }
    for(int i=0;i<max;i++){
        if((np+i)->parent==-1){
            (np+i)->type=root;
            (np+i)->done_f=true;
            continue;
        }
        (np+i)->sibling=(np+(np+i)->parent)->left==i?(np+(np+i)->parent)->right:-1;
        if((np+i)->sibling==-1){
            (np+i)->sibling=(np+(np+i)->parent)->right==i?(np+(np+i)->parent)->left:-1;
        }

        if((np+i)->left==-1&&(np+i)->right==-1){
            (np+i)->type=leaf;
            continue;
        }
        (np+i)->type=internal;
    }
}


void allprint(Node* np, int max){
    Node* npnext;
    for(int i=0;i<max;i++){
        npnext=np+i;
        printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n",i,npnext->parent,npnext->sibling,npnext->deg,npnext->depth,npnext->height,npnext->type);
    }
}

void depthjud(Node* np,int max){
    int depth_max=0;
    //printf("in depthjud root node_num %d parent %d\n",np[0].node_num,np[0].parent);
    for(int i=0;i<max;i++){
        //printf("in depthjud i %d node_num %d parent %d\n",i,(np+i)->node_num,(np+i)->parent);
        if(strcmp((np+i)->type,"root")==0){
            continue;
        }
        if(!(np+(np+i)->parent)->done_f){
            continue;
        }
        if((np+i)->right==-1&&(np+i)->left==-1){
            (np+i)->depth=(np+(np+i)->parent)->depth+1;
            (np+i)->done_f=true;
        }
        else{
            (np+i)->depth=(np+(np+i)->parent)->depth+1;
            (np+i)->done_f=true;
        }
    }
    for(int i=0;i<max;i++){
        printf("in depthjud i %d node_num %d parent %d depth %d\n",i,i,(np+i)->parent,(np+i)->depth);
        if((np+i)->type==root){
            continue;
        }
        if((np+i)->done_f){
            continue;
        }
        if((np+i)->right==-1&&(np+i)->left==-1){
            (np+i)->depth=(np+(np+i)->parent)->depth+1;
        }
        else{
            (np+i)->depth=(np+(np+i)->parent)->depth+1;
        }
        
        /*if(depth_max<(np+i)->depth){
            depth_max=(np+i)->depth;
        }*/
    }

    for(int i=0;i<max;i++){
        if(depth_max<(np+i)->depth){
            depth_max=(np+i)->depth;
        }
    }
    heightjud(np,max,depth_max);
    //printf("in depthjud root node_num %d parent %d\n",np[0].node_num,np[0].parent);
}

void _depthjud(Node* np,int max){
    int leafs[20];
    int deepleafs[20];
    int leafc=0;
    int dleafc=0;
    int depthc=0;
    int depmax=0;
    int mostdeep;
    int num;
    int dep1;
    int dep2;
    int root_num;

    for(int i=0;i<max;i++){
        if((np+i)->type==leaf){
            leafs[leafc]=i;
            leafc++;
        }
        if((np+i)->type==root){
            root_num=i;
        }
    }
    leafs[leafc]=393939;

    for(int i=0;leafs[i]!=393939;i++){
        num=(np+leafs[i])->parent;
        depthc=0;
        while((np+num)->type!=root){
            depthc++;
            num=(np+num)->parent;
        }
        (np+leafs[i])->depth=depthc+1;
        if(depmax<depthc+1){
            depmax=depthc+1;
        }
    }

    heightjud(np,max,depmax);

    for(int i=0;leafs[i]!=393939;i++){
        num=(np+leafs[i])->parent;
        dep1=(np+leafs[i])->depth-1;
        while((np+num)->type!=root){
            (np+num)->depth=dep1;
            dep1=(np+num)->depth-1;
            num=(np+num)->parent;
        }
    }




}

void heightjud(Node* np,int max,int depth_max){
    bool flag=false;
    int leafs[20];
    int leaf_c=0;
    int height_counter=0;
    int num=0;
    int i;

    for(i=0;i<max;i++){
        if((np+i)->type==root){
            (np+i)->height=depth_max;
            flag=true;
            continue;
        }
        if((np+i)->type==leaf){
            //printf("i %d\n",i);
            (np+i)->height=0;
            leafs[leaf_c]=i;
            leaf_c++;
        }
    }
    leafs[leaf_c]=393939;
    for(i=0;leafs[i]!=393939;i++){
        //printf("leaf num %d\n",leafs[i]);
        num=(np+leafs[i])->parent;
        height_counter=0;
        //printf("leafs %d \n",leafs[i]);
        while((np+num)->type!=root){
            //printf("height_counter %d num %d (np+num)->height %d\n",height_counter,num,(np+num)->height);
            height_counter++;
            if((np+num)->height<height_counter){
                (np+num)->height=height_counter;
            }
            num=(np+num)->parent;
        }
    }

}
