#include <stdio.h>
#include <math.h>
#define NIL -1
#define MAX 25

int Max( int, int );
int Depth( int );
int Height( int );
void Print( int );

struct Node{
    int p;
    int l;
    int r;
    int s; //s means another sibling
    int degree;
};
struct Node A[26];

//------------------------------------------------
int main(){
    int n, id, r, l, cnt, i;

    //initialize
    for(i = 0; i<MAX; i++){
	A[i].p = NIL;
	A[i].l = NIL;
	A[i].r = NIL;
	A[i].s = NIL;
    }
    //input
    scanf("%d",&n);
    for(i = 0; i<n; i++){
	cnt = 0;
	scanf("%d%d%d", &id, &l, &r);
	A[id].l = l; //parent operations
	A[id].r = r;
	if(l != NIL){ //left child
	    A[l].p = id;
	    A[l].s = r;
	    cnt++;
	}
	if(r != NIL){ //right child
	    A[r].p = id;
	    A[r].s = l;
	    cnt++;
	}
	A[id].degree = cnt; //degree
    }
    //display
    for(i = 0; i<n; i++) Print( i );
    
    return 0;
}

//--------------------------------------------------
void Print( int x ){
    int depth, height, i;

    depth = Depth( x );
    height = Height( x );
    printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ", x, A[x].p, A[x].s, A[x].degree, depth, height);
    //the type of the node
    if( A[x].p == NIL ) printf("root\n");
    else if( A[x].degree == 0 ) printf("leaf\n");
    else printf("internal node\n");
    
    return ;
}

//---------------------------------------------------
int Depth( int x ){
    int cnt = 0;

    while( A[x].p != NIL ){
	cnt++;
	x = A[x].p;
    }
    return cnt;
}

//---------------------------------------------------
int Height( int x ){
    if(A[x].degree == 0) return 0;
    else                 return 1+Max( Height(A[x].l), Height(A[x].r) );
}

//---------------------------------------------------
int Max( int x, int y ){
    if (x > y) return x;
    else       return y;
}
