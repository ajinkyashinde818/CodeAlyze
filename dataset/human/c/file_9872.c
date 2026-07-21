#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct ve{
        int num;
        int parent_num;
        int degree;
        int depth;
        char type[128];
        int *child;
};

int n;

int calc_depth(struct ve *, int, int);

int main(){
        int p, i, j, id, k, l, m, root;
        char f;
        struct ve *T;

        scanf("%d", &n);

        T = malloc(n * sizeof(struct ve));

        for(i = 0 ; i < n ;i++){
                T[i].parent_num = -1;
        }

        for(i = 0 ; i < n ; i++){
                m = 0;
                scanf("%d", &id);
                T[id].num = id;
                scanf("%d", &T[id].degree);
                if(T[id].degree == 0){
                        strcpy(T[id].type, "leaf");
                        continue;
                }
                T[id].child = malloc(T[id].degree * sizeof(int));
                for(j = 0 ; j < T[id].degree ; j++){
                        scanf("%d", &p);
                        T[id].child[m] = p;
                        T[p].parent_num = id;
                        m++;
                }
        }

        for(i = 0 ; i < n ; i++){
                if(n == 1)strcpy(T[i].type, "root");
                if(T[i].degree == 0)continue;
                if(T[i].parent_num == -1){
                        strcpy(T[i].type, "root");
                        root = i;                               
                }else strcpy(T[i].type, "internal node");
        }

        for(i = 0 ; i < n ; i++){
                T[i].depth = calc_depth(T, root, i);
        }
        
        for(i = 0 ; i < n ; i++){
                printf("node %d: parent = %d, depth = %d, %s, [", T[i].num, T[i].parent_num, T[i].depth, T[i].type);
                for(j = 0 ; j < T[i].degree ; j++){
                        printf("%d", T[i].child[j]);
                        if(j + 1 < T[i].degree)printf(", ");
                }
                printf("]\n");
        }

        for(i = 0 ; i < n ; i++){
                if(T[i].degree == 0)continue;
                else free(T[i].child);
        }
        free(T);
        return 0;
}

int calc_depth(struct ve *T, int root, int id){
        if(strcmp(T[id].type, "root") == 0)return 0;
        else{
                return 1 + calc_depth(T, root, T[id].parent_num);
        }
}
