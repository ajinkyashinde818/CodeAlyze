#include<stdio.h>
#define A 100001

	typedef struct {
		int p,l,r;
	}Node;

	Node N[A];

	int D(int i,int d){
		if(N[i].p == -1) return d;
		else return D(N[i].p,d+1);
	}

	int main(){
		int n,m,i,j,id,ch,le;
		
		scanf("%d",&n);

		for(i=0; i<n; i++){
			N[i].p = -1;
			N[i].l = -1;
			N[i].r = -1;
		}

		for(i=0; i<n; i++){
			scanf("%d %d",&id,&m);
			for(j=0; j<m;j++){
				scanf("%d",&ch);
				if(j==0) N[id].l = ch;
				else N[le].r = ch;
				le = ch;
				N[le].p = id;
			}
		}

		for(i=0; i<n; i++){
			printf("node %d: parent = %d, depth = %d, ",i,N[i].p,D(i,0));
			if(N[i].p == -1) printf("root, ");
			else if(N[i].l == -1) printf("leaf, ");
			else printf("internal node, ");
			if(N[i].l == -1) printf("[]");
			else{
				printf("[%d",N[i].l);
				le = N[i].l;
				while(1){
					if(N[le].r == -1){
						printf("]");
						break;
					}
					else printf(",");
					printf(" %d",N[le].r);
					le = N[le].r;
				}
			}
			printf("\n");
		}

		return 0;
	}
