#include<stdio.h>

typedef struct node{

  int parent;
  int br;
  int child;

}Node;
Node node[100001];
void nodegene( Node*);

//void putdepth( Node*);

int depth(int);

void nodegene( Node* nod){

  nod -> child = -1;
  nod -> br = -1;
  nod -> parent = -1;

}


int depth(int k){
  int dep = 0;
  for(dep = 0 ; node[k].parent != -1 ; dep++){
    k = node[k].parent;
  }
  return dep;

}
int main(){

  int i, j, m, n, l, nod, d, degree,br;

  Node c;
  scanf("%d",&m);

  for( i = 0; i < m; i++)nodegene(&node[i]);
  
  for( i = 0; i < m; i++){

    scanf("%d%d", &n, &nod);
    //    l = node[n].child;
    for( j = 0; j < nod; j++){
      scanf("%d", &degree);
      node[degree].parent = n;
      if( node[n].child == -1){
	node[n].child = degree;
      }
      else{
	//	l = node[n].child;
		//	while( node[l].br != -1) l = node[l].br;
	node[l].br = degree;
	//	l = degree;
	//	printf("flag");
      }
      l = degree;
    }
  }

  //  for(i = 0; i < m; i ++)putdepth(&node[i]);

  for( i = 0; i < m; i++){

    printf("node %d: parent = %d, depth = %d, ", i, node[i].parent,depth(i));

    if(node[i].child == -1 && node[i].parent != -1)
      printf("leaf, ");
    else if(node[i].parent == -1)
      printf("root, " );
    else if(node[i].child != -1 && node[i].parent != -1)
      printf("internal node, " );

    printf("[");

    if(node[i].child != -1){

      printf("%d",node[i].child);

      br = node[i].child;

      while(node[br].br != -1){
	printf(", %d",node[br].br);
	br = node[br].br;
      }
    }

    printf("]\n");
  }
  return 0;
}
