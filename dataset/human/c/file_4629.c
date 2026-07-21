#include <stdio.h>
#include <math.h>
int getSibling(int);
int getDegree(int);
int getDepth(int);
int getHeight(int);
struct Node{
	int p;
	int l;
	int r;
};
struct Node T[25];
int main(){
	int num,i,e;
	scanf("%d",&num);
	for(i=0;i<num;i++){
		T[i].p=-1;
	}
	for(i=0;i<num;i++){
		scanf("%d",&e);
		scanf("%d%d",&T[e].l,&T[e].r);
		if (T[e].l != -1) T[T[e].l].p=e;
		if (T[e].r != -1) T[T[e].r].p=e;
	}
	for(i=0;i<num;i++){
		if(T[i].p == -1){
			printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, root\n",i,T[i].p,getSibling(i),getDegree(i),getDepth(i),getHeight(i));

		}else if(getDegree(i) >= 1){
			printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, internal node\n",i,T[i].p,getSibling(i),getDegree(i),getDepth(i),getHeight(i));

		}else{
			printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, leaf\n",i,T[i].p,getSibling(i),getDegree(i),getDepth(i),getHeight(i));
		}
		//if(i != num-1) printf("\n");
	}
	return 0;
}
int getSibling(int n){
	if(T[n].p==-1){
		return -1;
	}
	else if(T[T[n].p].l!=n){
		return T[T[n].p].l;
	}else{
		return T[T[n].p].r;
	}
}

int getDegree(int n){
	int count=0;
	if(T[n].l != -1) count++;
	if(T[n].r != -1) count++;
	return count;
}

int getDepth(int n){
	if(T[n].p == -1) return 0;
	  return getDepth(T[n].p)+1;
}

int getHeight(int n){
	int right=0,left=0;
	  if(T[n].r == -1 && T[n].l == -1) return 0;

	  if(T[n].r != -1) right = getHeight(T[n].r)+1;
	  if(T[n].l != -1) left = getHeight(T[n].l)+1;

	  return fmaxf(right,left);
}
