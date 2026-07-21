#include<stdio.h>
#include<stdlib.h>

typedef struct{
  int left;
  int right;
  int child;
  int p;
  int s;
  int d;
  int h;
}DATA;

DATA id[25];

int depthsearch(int, int);
int heightsearch(int, int);

int main(){
  int i, j, n, idtemp, l, r, maxd;
  
  scanf("%d", &n);
  if(n >= 1 && n <= 25){
    for(i = 0; i < n; i++) {
      id[i].p = -1;
      id[i].s = -1;
    }
    for(i = 0; i < n; i++){
      scanf("%d", &idtemp);
      scanf("%d %d", &l, &r);
      id[idtemp].child = 0;
      id[idtemp].left = l;
      id[idtemp].right = r;
      if(l != -1 && r != -1){
	id[l].p = idtemp;
	id[r].p = idtemp;
	id[l].s = r;
	id[r].s = l;
	id[idtemp].child = 2;
      }else if(l == -1 && r != -1){
	id[r].p = idtemp;
	id[idtemp].child = 1;
      }else if(r == -1 && l != -1){
	id[l].p = idtemp;
	id[idtemp].child = 1;
      }
    }

    for(i = 0; i < n; i++){
      id[i].d = depthsearch(0, i);
    }

    for(i = 0; i < n; i++){
      printf("node %d: parent = %d, sibling = %d, ", i, id[i].p, id[i].s);
      id[i].h = heightsearch(0, i);
      printf("degree = %d, depth = %d, height = %d, ", id[i].child, id[i].d, id[i].h);
      
      if(id[i].p == -1) printf("root\n");
      else if(id[i].left != -1 || id[i].right != -1) printf("internal node\n");
      else printf("leaf\n");
    }

  }
  return 0;
}

int depthsearch(int d, int ids){
  
  if(id[ids].p == -1) return d;
  
  ids = id[ids].p;
  d = depthsearch(d + 1, ids);
 
  return d;
}

int heightsearch(int h, int ids){
  int h1, h2;
  h1 = h2 = 0;
  if(id[ids].right != -1)
    h1 = heightsearch(h, id[ids].right) + 1;
  if(id[ids].left != -1)
    h2 = heightsearch(h, id[ids].left) + 1;

  if(h1 > h2)return h1;
  return h2;
}
