#include <stdio.h>

#define NODE_MAX (25)
#define DEPTH_MAX (25)
#define HIGHT_MAX (25)
#define NIL (-1)


struct node {
        int parent;
        int left;
        int right;
};

struct node T[NODE_MAX];
int D[DEPTH_MAX];
int H[HIGHT_MAX];


int
get_depth(int id)
{
        int depth = 0;

        while (T[id].parent != NIL) {
                id = T[id].parent;
                depth++;
        }

        return depth;
}

int
get_height(int id)
{
        int height = NIL;
        int h_r = 0;
        int h_l = 0;
        int i = 0;

        if (T[id].right != NIL)
                h_r = get_height(T[id].right) + 1;
        if (T[id].left != NIL)
                h_l = get_height(T[id].left) + 1;
        if (T[id].left == NIL && T[id].right == NIL)
                height = 0;

        if (height != 0 && h_r <= h_l)
                height = h_l;
        else if (height != 0 && h_l < h_r)
                height = h_r;

        return height;
}

void
print_sibling(int id)
{
        int sibling = NIL;
        int parent;
        int i;

        parent = T[id].parent;
        if (parent == NIL)
                sibling = NIL;
        else if (T[parent].left == id)
                sibling = T[parent].right;
        else if (T[parent].right == id)
                sibling = T[parent].left;

        printf("sibling = %d, ", sibling);
}

void
print_degree(int id)
{
        int degree;

        if (T[id].left == NIL && T[id].right == NIL)
                degree = 0;
        else if (T[id].left != NIL && T[id].right != NIL)
                degree = 2;
        else
                degree = 1;

        printf("degree = %d, ", degree);
}


void
print(int id)
{
        printf("node %d: parent = %d, ", id, T[id].parent);

        print_sibling(id);
        print_degree(id);

        printf("depth = %d, height = %d, ", D[id], H[id]);


        if (T[id].parent == NIL)
                printf("root\n");
        else if (T[id].left == NIL && T[id].right == NIL)
                printf("leaf\n");
        else
                printf("internal node\n");

}

int
main(void)
{
        int node_num;
        int id;
        int id_left;
        int i, j;
        int read_array[3];

        scanf("%d", &node_num);

        for (i = 0; i < node_num; i++)
                T[i].parent = T[i].left = T[i].right = NIL;

        for (i = 0; i < node_num; i++) {
                for (j = 0; j < 3; j++) {
                        scanf("%d", &read_array[j]);
                        id = read_array[0];
                        if (j)
                                T[read_array[j]].parent = id;
                }

                T[id].left = read_array[1];
                T[id].right = read_array[2];
        }

        for (i = 0; i < node_num; i++) {
                D[i] = get_depth(i);
                H[i] = get_height(i);
        }

        for (i = 0; i < node_num; i++)
                print(i);

        return 0;
}
