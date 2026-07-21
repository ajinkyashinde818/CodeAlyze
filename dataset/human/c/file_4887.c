#include<stdio.h>
#define A 100001

typedef struct{
	int p,l,r;
}Node;

Node N[A];

int dep(int i,int d){
	if(N[i].p == -1) return d;
	else return dep(N[i].p,d+1);
}

int sib(int i){
	if(N[i].p == -1) return -1;
	if(N[N[i].p].r == i) return N[N[i].p].l;
	if(N[N[i].p].l == i) return N[N[i].p].r;
	return -1;
}

int deg(int i){
	int x = 0;
	if(N[i].l != -1) x++;
	if(N[i].r != -1) x++;
	return x;
}

int hei(int i){
	int x = 0,y = 0;
	if(N[i].l != -1) x = hei(N[i].l)+1;
	if(N[i].r != -1) y = hei(N[i].r)+1;
	if(x > y) return x;
	else return y;
}

int main(){
	int i,n,id,ch,le,ri;

	scanf("%d",&n);
	for(i=0; i<n; i++){
		N[i].p = -1;
		N[i].l = -1;
		N[i].r = -1;
	}

	for(i=0; i<n; i++){
		scanf("%d %d %d",&id,&le,&ri);
		N[id].l = le;
		N[id].r = ri;
		N[le].p = id;
		N[ri].p = id;
	}

	for(i=0; i<n; i++){
		ch = 0;
		if(N[i].l != -1) ch++;
		if(N[i].r != -1) ch++;

		printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, ",i,N[i].p,sib(i),ch,dep(i,0),hei(i));
		if(N[i].p == -1) printf("root");
		else if(N[i].l == -1 && N[i].r == -1) printf("leaf");
		else printf("internal node");
		printf("\n");
	}

	return 0;
}
