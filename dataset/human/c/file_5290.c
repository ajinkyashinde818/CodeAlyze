#include<stdio.h>
#include<stdlib.h>

#define MAX 100000
#define ROOT 0
#define INODE 1
#define LEAF 2

struct NODE {
	int parent;
	int sibling;
	short degree;
	short depth;
	int height;
	short type;
	int left;
	int right;
};
typedef struct NODE NODE;

NODE nodes[ MAX+1 ];

void inputDepth( int id )
{
	if( -1 == id ) { return; }
	
	if( -1 != nodes[id].left ) {
		nodes[ nodes[id].left ].depth=nodes[id].depth+1;
		inputDepth( nodes[id].left );
	}

	if( -1 != nodes[id].right ) {
		nodes[ nodes[id].right ].depth=nodes[id].depth+1;
		inputDepth( nodes[id].right  );
	}

}				

int main( void ) 
{   
    int n;
    int id,left,right;
    int i,j,prej;
    char types[3][32] = { "root", "internal node", "leaf" };

	       
    scanf( "%d", &n );
    for( i=0; i<n; i++ ) {
        scanf( "%d%d%d", &id, &left, &right );
       	nodes[id].left=left;
        nodes[id].right=right;
        if( -1 == left && -1 == right ) {
        	nodes[id].type=LEAF;
        	nodes[id].degree=0;
        	nodes[id].height=0;
        } else {
        	if( -1 != left && -1 != right ) {
        		nodes[id].degree=2;
        	} else {
        		nodes[id].degree=1;
        	}
        	
    		if( -1 !=  nodes[id].parent && INODE != nodes[id].type && LEAF != nodes[id].type ) {
    			nodes[id].type=ROOT;
    			nodes[id].parent=-1;
    			nodes[id].sibling=-1;
    		}

    		if(  -1 != left ) {
 		        nodes[left].parent=id;
 		        nodes[left].sibling=right;
 		        if( ROOT == nodes[left].type ) {
 		        	nodes[left].type=INODE;	
 		        } 		
    		}
       		if(  -1 != right ) {
		        nodes[right].parent=id;
		        nodes[right].sibling=left;	
 		        if( ROOT == nodes[right].type ) {
 		        	nodes[right].type=INODE;	
 		        }
    		}
        }
    }
    if( 1 == n ) {
    	nodes[id].parent=-1;
    	nodes[id].sibling=-1;
    	nodes[id].type=ROOT;
        nodes[id].degree=0;
        nodes[id].height=0;
    } else {  

	    for( i=0; i<n; i++ ) {
			if( ROOT == nodes[i].type ) {
				inputDepth( i );
				break;
	    	}
	    }

	    for( i=0; i<n; i++ ) {
	    	if( LEAF == nodes[i].type ) {
	    		j=nodes[i].parent;
	    		prej=i;
	    		while( -1 != j ) {
	    			if( nodes[j].height < nodes[prej].height+1 ) {
	    				nodes[j].height=nodes[prej].height+1;
	    			}
	    			prej=j;
	    			j=nodes[j].parent;
	    		}
	    	}
	    }
    }
    
    for( i=0; i<n; i++ ) {
		printf( "node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", 
				i, nodes[i].parent, nodes[i].sibling, nodes[i].degree, nodes[i].depth, nodes[i].height, types[ nodes[i].type ] );
	}

    return 0;
}
