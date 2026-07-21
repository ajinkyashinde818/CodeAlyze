#include<stdio.h>

#define MAX 10000
#define NIL -1

typedef struct{
	int a;
	int b;
	int c;
}Node;

Node T[MAX];
int n , D[MAX] , H[MAX];

void setDepth( int u , int d ){
	
	if( u == NIL ){
		return;
	}
	D[u] = d;
	setDepth( T[u].b , d+1 );
	setDepth( T[u].c , d+1 );
}

int setHeight( int u ){
	
	int h1 = 0 , h2 = 0;
	
	if( T[u].b != NIL ){
		h1 = setHeight( T[u].b ) +1;
	}
	if( T[u].c != NIL ){
		h2 = setHeight( T[u].c ) + 1;
	}
	return H[u] = ( h1 > h2 ? h1 : h2 );
}

int getSibling( int u ){
	
	if( T[u].a == NIL ){
		return NIL; 
	}
	if( T[T[u].a].b != u && T[T[u].a].b != NIL ){
		return T[T[u].a].b;
	}
	if( T[T[u].a].c != u && T[T[u].a].c != NIL ){
		return T[T[u].a].c;
	}
	return NIL;
	
}

void print( int u ){
	
	printf( "node %d: " , u );
	printf( "parent = %d, " , T[u].a );
	printf( "sibling = %d, " , getSibling(u) );
	
	int deg = 0;
	
	if( T[u].b != NIL ){
		deg++;
	}
	if( T[u].c != NIL ){
		deg++;
	}
	printf( "degree = %d, " , deg );
	printf( "depth = %d, " , D[u] );
	printf( "height = %d, " , H[u] );
	
	
	if( T[u].a == NIL ){
		printf( "root\n" );
	}else if( T[u].b == NIL && T[u].c == NIL ){
		printf( "leaf\n" );
	}else{
		printf( "internal node\n" );
	}
}

int main( void ){
	
	int v , l , r , root = 0;
	
	scanf( "%d" , &n );
	
	for( int i = 0; i < n; i++ ){
		T[i].a = NIL;
	}
	
	for( int i = 0; i < n; i++ ){
		scanf( "%d" , &v );
		scanf( "%d" , &l );
		scanf( "%d" , &r );
		T[v].b = l;
		T[v].c = r;
		if( l != NIL ){
			T[l].a = v;
		}
		if( r != NIL ){
			T[r].a = v;
		}
	}
	
	for( int i = 0; i < n; i++ ){
		if( T[i].a == NIL ){
			root = i;
		}
	}
	
	setDepth( root , 0 );
	setHeight( root );
	
	for( int i = 0; i < n; i++ ){
		print( i );
	}
	
	return 0;
}
