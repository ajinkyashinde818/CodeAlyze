#include<stdio.h>
#define ran 222222
int cnt[ran],a[ran];
int n,m;

struct Node{
	int add, val_small, val_cnt;
	void addon(int x){
		add += x;
		val_small += x;
	}
};

Node seg[ran*4];
void push(int i){
	int&tmp = seg[i].add;
	if(tmp == 0)return;
	seg[i*2].addon(tmp);
	seg[i*2+1].addon(tmp);
	tmp = 0;
}
void merge(Node&A,const Node&B,const Node&C){
	if(B.val_small == C.val_small){
		A.val_small = B.val_small;
		A.val_cnt = B.val_cnt + C.val_cnt;
	}else
	if(B.val_small < C.val_small){
		A.val_small = B.val_small;
		A.val_cnt = B.val_cnt;
	}else{
		A.val_small = C.val_small;
		A.val_cnt = C.val_cnt;
	}
}
void upd(int i,int s,int e,int l,int r,int z){
	if(s == l && e == r){
		seg[i].addon(z);
		return;
	}
	push(i);
	int m = (s+e)/2;
	if(r<=m)upd(i*2,s,m,l,r,z);else
	if(l>m)upd(i*2+1,m+1,e,l,r,z);else{
		upd(i*2,s,m,l,m,z);
		upd(i*2+1,m+1,e,m+1,r,z);
	}
	merge(seg[i],seg[i*2],seg[i*2+1]);
}
void draw(int id,int z){
	int L = id - cnt[id] + 1, R = id;
	if(L > R)return;
	if(L <= 0)L = 1;
//	printf("draw %d %d %d\n",L,R,z);
	upd(1,1,n,L,R,z);
}
void build(int i,int s,int e){
	seg[i].add = 0;
	if(s==e){
		seg[i].val_small = 0;
		seg[i].val_cnt = 1;
		return;
	}
	int m = (s+e)/2;
	build(i*2,s,m);
	build(i*2+1,m+1,e);
	merge(seg[i],seg[i*2],seg[i*2+1]);
}
void show_tree(int i,int s,int e,int x){
	x += seg[i].add;
	if(s == e)
		printf("%d ",x);
	else{
		int m=(s+e)/2;
		show_tree(i*2,s,m,x);
		show_tree(i*2+1,m+1,e,x);
	}
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	build(1,1,n);
	for(int i=1; i<=n; i++)
		draw(i, 1);
	while(m--){
		int x,y;
		scanf("%d%d",&x,&y);
		draw(a[x], -1);
		cnt[a[x]]--;
		draw(a[x], 1);
		draw(y, -1);
		a[x] = y;
		cnt[y] ++;
		draw(y, 1);
//		show_tree(1,1,n,0);
		printf("%d\n", seg[1].val_small == 0?seg[1].val_cnt : 0);
	}
	return 0;
}
