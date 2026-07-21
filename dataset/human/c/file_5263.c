#include <stdio.h>
#define N 30

/*
How to test
% diff <(./a.out < b1in.txt) <(cat b1out.txt) 
$ ./a.out < ain.txt 2>erra.txt

  for( i=0 ; i < n ; i++){
    fprintf(stderr, "%d: C2[%d] = %c%c \n" ,__LINE__ ,i ,C2[i].suit ,C2[i].value );
  }
    fprintf(stderr, "%d:\n" ,__LINE__ );
*/
typedef enum{
  ROOT, INT, LEAF,
} t_e;

typedef struct{
  int left;
  int right;
  int pa;  // parent
  int sib; // sibling
  int deg; // degree
  int dep; // depth
  int h;   // hight
  t_e type;
} tree_t;

int tree_depth = 0;

int geth(tree_t* ,int);
void prew(tree_t *t_p ,int id);
void pr(tree_t *a_p, int n);

int main(){
  int    n, i, j, k;
  int    id;
  int    pid; // parent ID
  tree_t a[N]; // a[id]

  scanf("%d", &n);
  for ( i = 0; i < n; i++ ){
    scanf("%d", &id );
    scanf("%d%d" ,&(a[id].left) ,&(a[id].right) );
  }

  // set parent, degree
  for( i=0 ; i<n ; i++){
    a[i].pa = -1;
    a[i].sib= -1;
    a[i].deg=  0;
    a[i].h  =  0;
  }

  // fprintf(stderr, "%d:\n" ,__LINE__ );

  for( i=0 ; i<n ; i++ ){
    if( a[i].left != -1 ){
      a[(a[i].left)].pa  = i;
      a[i].deg++;
    }
    if( a[i].right != -1 ){
      a[(a[i].right)].pa = i;
      a[i].deg++;
    }
  }

  // fprintf(stderr, "%d:\n" ,__LINE__ );
  // set type, get parent ID
  for( i=0 ; i<n ; i++ ){
    if( a[i].pa == -1 ){
      pid = i;
      a[i].type = ROOT;
    }else if( a[i].left != -1 || a[i].right != -1 ){
      a[i].type = INT;
    }else{
      a[i].type = LEAF;
    }
  }

  // fprintf(stderr, "%d:\n" ,__LINE__ );
  prew(a, pid);
  // fprintf(stderr, "%d:\n" ,__LINE__ );
  
  // set height
  for( i=0 ; i<n ; i++){
    if( n != 1 ){
      a[i].h = geth(a, i);
    }
  }

  // fprintf(stderr, "%d:\n" ,__LINE__ );

  // set sib
  for( i=0 ; i<n ; i++ ){
    if( a[i].left != -1 && a[i].right != -1 ){
      a[(a[i].left)].sib  = a[i].right;
      a[(a[i].right)].sib = a[i].left;
    }
  }

  // fprintf(stderr, "%d:\n" ,__LINE__ );

  pr( a, n);
  return 0; // Don't forget return 0
}

// get hight
int geth(tree_t *t_p ,int id){
  if( t_p[id].type == LEAF || id == -1 ){
    return 0;
  }
  int a = geth(t_p, t_p[id].left);
  int b = geth(t_p, t_p[id].right);
  return 1 + ( a > b ? a : b );
}

void prew(tree_t *t_p ,int id){ // preorder tree walk
  if(id == -1){
    return;
  }

  t_p[id].dep = tree_depth;
  
  tree_depth++;
  prew(t_p, t_p[id].left);
  prew(t_p, t_p[id].right);
  tree_depth--;
}

void pr(tree_t *a_p, int n){
  int i;
  for( i = 0 ; i < n ; i++ ){
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, "
	   ,i ,a_p[i].pa ,a_p[i].sib ,a_p[i].deg ,a_p[i].dep ,a_p[i].h );
    if( a_p[i].type == ROOT ){
      printf("root");
    }else if( a_p[i].type == INT ){
      printf("internal node");
    }if( a_p[i].type == LEAF ){
      printf("leaf");
    }
    printf("\n"); // note the possible of presentation error
  }

}
