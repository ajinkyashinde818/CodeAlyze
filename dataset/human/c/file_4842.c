#include <stdio.h>

typedef struct{
  int id;
  int parents;
  int sibling;
  int child1;
  int child2;
}Tree;

int main(void){
  int i,j,k,l,n,id,left,right,depth,height,temp, s_temp, root;
  Tree tree[25];

  scanf("%d",&n);

  for( i = 0 ; i < n ; i++ ){
    tree[i].parents = -1;
    tree[i].sibling = -1;
    tree[i].child1 = -1;
    tree[i].child2 = -1;
  }

  for( i = 0 ; i < n ; i++ ){
    scanf("%d %d %d",&id,&left,&right);
    tree[i].id = id;
    tree[i].child1 = left;
    tree[i].child2 = right;
  }

  for( i = 0 ; i < n ; i++ ){
    for( j = 0 ; j < n ; j++ ){
      if( tree[i].id == tree[j].child1 ){
	tree[i].parents = tree[j].id;
	tree[i].sibling = tree[j].child2;
      }
      if( tree[i].id == tree[j].child2 ){
	tree[i].parents = tree[j].id;
	tree[i].sibling = tree[j].child1;
      }
    }
  }  
  
  for(i = 0 ; i < n ; i++ ){
    if( tree[i].parents == -1 ){
      root = tree[i].id;
    }
  }
  
  /*bublle sort */
  for( i = 0 ; i < n - 1 ; i++ ){
    for( j = n - 1 ; j > i ; j-- ){
      if( tree[j - 1].id > tree[j].id ){
	s_temp = tree[j].id;
	tree[j].id = tree[j - 1].id;
	tree[j - 1].id = s_temp;
        s_temp = tree[j].parents;
        tree[j].parents = tree[j - 1].parents;
        tree[j - 1].parents = s_temp;
        s_temp = tree[j].sibling;
        tree[j].sibling = tree[j - 1].sibling;
        tree[j - 1].sibling = s_temp;
        s_temp = tree[j].child1;
        tree[j].child1 = tree[j - 1].child1;
        tree[j - 1].child1 = s_temp;
        s_temp = tree[j].child2;
        tree[j].child2 = tree[j - 1].child2;
        tree[j - 1].child2 = s_temp;
      }
    }
  }


  for( i = 0 ; i < n ; i++ ){
    depth = 0;
    printf("node %d: parent = %d, sibling = %d, ",tree[i].id, tree[i].parents, tree[i].sibling);
    for( j = 0 ; j < n ; j++ ){
      if( tree[i].child1 != -1 && tree[i].child2 != -1 ){
	printf("degree = 2, ");
	break;
      }
      else if( tree[i].child1 == -1 && tree[i].child2 == -1 ){
	printf("degree = 0, ");
	break;
      }
      else if( tree[i].child1 != -1 || tree[i].child2 != -1 ){
	printf("degree = 1, ");
	break;
      }
    }

    j = i;
    while(1){
      if( tree[j].id == root ){
	printf("depth = %d, ",depth);
	break;
      }
      else{
	j = tree[j].parents;
	depth++;
      }
    }

    height = 0;
    for( j = 0 ; j < n ; j++ ){
      temp = 0;
      k = j;
      if( tree[i].id == tree[j].id && tree[j].child1 == -1 && tree[j].child2 == -1 ) break;
      while(1){
	if( tree[k].parents == tree[i].id ){
	  temp++;
	  if( height <= temp ){
	    height = temp;
	  }
	  break;
	}
	else if( tree[k].parents == -1 ){
	  break;
	}
	else{
	  k = tree[k].parents;
	  temp++;
	}
      }
    }
    printf("height = %d, ",height);
    if( depth == 0 ) printf("root\n");
    else if( height == 0 ) printf("leaf\n");
    else printf("internal node\n");
  }
  return 0;
}
