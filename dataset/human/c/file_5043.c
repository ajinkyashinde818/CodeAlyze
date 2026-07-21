#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int p;
    int l;
    int r;
}Node;

Node node[28];

void getDep(int n){
    int depth = 0;
    while(node[n].p!=-1){
      depth++;
      n = node[n].p;
    }
    printf("depth = %d, ",depth);
}


int getHeight(int i){
    int p1 = 0;
    int p2 = 0;
    if(node[i].l==-1 && node[i].r==-1) return 0;
    if(node[i].l!=-1){
        p1=getHeight(node[i].l)+1;
    }
    if(node[i].r!=-1){
        p2=getHeight(node[i].r)+1;
    }
    if(p1>p2){
        return p1;
   }
    else{
        return p2;
    }

}

void judge(int i){
    if(node[i].p==-1){
        printf(" root\n");
    }
    else if(node[i].l==-1 && node[i].r==-1){
            printf(" leaf\n");
        }
    else printf(" internal node\n");
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        node[i].p = -1;
    }

    int id;
    for(int i=0; i<n; i++){
        scanf("%d", &id);
        scanf("%d %d", &node[id].l, &node[id].r);
        if(node[id].l!=-1 && node[id].r!=-1){
            node[node[id].l].p = id;
            node[node[id].r].p = id;
        }
        else{
            if(node[id].l!=-1 && node[id].r==-1){
                node[node[id].l].p = id;
            }
            if(node[id].l==-1 && node[id].r!=-1){
                node[node[id].r].p = id;
            }
        }
    }

    for(int i=0; i<n; i++){
        printf("node %d: parent = %d, ", i, node[i].p);
        if(node[i].p == -1){
            printf("sibling = -1, ");
        }
        else if(node[node[i].p].l == i){
                printf("sibling = %d, ",node[node[i].p].r);
        }
        else printf("sibling = %d, ",node[node[i].p].l);

        printf("degree = ");
        if(node[i].l!=-1 && node[i].r!=-1){
            printf("2, ");
        }
        else if(node[i].l==-1 && node[i].r==-1){
            printf("0, ");
            }
        else printf("1, ");

        getDep(i);
        printf("height = ");
        int h = getHeight(i);
        printf("%d,", h);
        judge(i);
    }
    return 0;
}
