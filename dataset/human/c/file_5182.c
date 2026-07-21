#include<stdio.h>
#include<stdlib.h>
 
#define SIZE 100001
 
enum TYPE{root, node, leaf, null};
char* strtype[] = {"root", "internal node", "leaf"};
 
typedef struct Vec{
    int lenght;
    int size;
    int maxsize;
    int* buff;
}VEC;
 
typedef struct VecIt{
    int i;
    VEC* vp;
}VECIT;
 
struct TREE{
    int parent;   /* ???????????? */
	int sibling;  /* ??????????????? */
    int depth;    /* ??賊??? */
	int height;   /* ?????? */
    int type;     /* ?????????????即???? */
    VEC* vp;      /* ??? */
};
 
struct TREE tree[SIZE];
int treeroot;
 
VEC* newVec(void)
{
    VEC* vp = (VEC*)malloc(sizeof(VEC));
    vp->lenght = 0;
    vp->size = 2;
    vp->maxsize = SIZE;
    vp->buff = (int*)calloc(vp->size, sizeof(int));
    return(vp);
}
 
void delVec(VEC* vp)
{
    free(vp->buff);
    free(vp);
    return;
}
 
void resizeVec(VEC* vp)
{
    vp->size += vp->size;
    vp->buff = (int*)realloc(vp->buff, vp->size*sizeof(int));
    return;
}
 
void addVec(VEC* vp, int n)
{
    if(vp->size <= vp->lenght){
        resizeVec(vp);
    }
    vp->buff[vp->lenght] = n;
    vp->lenght++;
    return;
}
 
int getVec(VEC* vp, int n)
{
    if(n < vp->lenght){
        return(vp->buff[n]);
    }
    return(-1);
}
 
int lenghtVec(VEC* vp)
{
    return(vp->lenght);
}
 
VECIT* newVecIt(VEC* vp)
{
    VECIT* vpit = (VECIT*)malloc(sizeof(VECIT));
    vpit->vp = vp;
    vpit->i = 0;
    return(vpit);
}
 
void delVecIt(VECIT* vp)
{
    free(vp);
    return;
}
 
int nextVecIt(VECIT* vp)
{
    return(getVec(vp->vp, vp->i++));
}
 
void init(void)
{
    int i;
    for(i = 0; i < SIZE; i++){
        tree[i].parent = -1;
		tree[i].sibling = -1;
        tree[i].depth = 0;
		tree[i].height = 0;
        tree[i].type = null;
        tree[i].vp = newVec();
    }
    return;
}
 
void end(void)
{
    int i;
    for(i = 0; i < SIZE; i++){
        delVec(tree[i].vp);
    }
    return;
}
 
void tr(int node, int lv)
{
    int n;
    VECIT* it = newVecIt(tree[node].vp);
    while((n = nextVecIt(it)) != -1){
        tr(n, lv + 1);
    }
    tree[node].depth = lv;
    return;
}

int tr2(int node)
{
	int n, w, max = 0;
	VECIT* it;
	it = newVecIt(tree[node].vp);
	while((n = nextVecIt(it)) != -1){
        w = tr2(n);
		if(max < w){
			max = w;
		}
    }
	tree[node].height = max;
	return(max + 1);
}

int main(int argc, char* argv[])
{
    int i, j, n, id, itn;
	int c[2], l, r;
    VECIT* it;
 
    init();
 
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d %d %d", &id, &c[0], &c[1]);
		for(j = 0; j < 2; j++){
			if(c[j] == -1){
				continue;
			}
			if(tree[c[j]].type == null){
				tree[c[j]].type = leaf;
			}
			tree[c[j]].parent = id;
			addVec(tree[id].vp, c[j]);
		}

        if(0 < lenghtVec(tree[id].vp)){
            tree[id].type = node;
        }else{
            tree[id].type = leaf;
        }

		if(2 <= lenghtVec(tree[id].vp)){
			l = getVec(tree[id].vp, 0);
			r = getVec(tree[id].vp, 1);
			tree[l].sibling = r;
			tree[r].sibling = l;
		}
    }
 
    for(i = 0; i < n; i++){
        if(tree[i].parent == -1){
            treeroot = i;
            break;
        }
    }
    tree[treeroot].type = root;
    tr(treeroot, 0);
	tr2(treeroot);
 
    for(i = 0; i < n; i++){
		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d,", i, tree[i].parent, tree[i].sibling, lenghtVec(tree[i].vp), tree[i].depth);
		printf(" height = %d, %s\n", tree[i].height, strtype[tree[i].type]);
    }
     
    end();
 
    return(0);
}
