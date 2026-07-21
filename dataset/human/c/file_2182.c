#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define rep(i,l,n) for(int i=l;i<n;i++)
#define ull unsigned long long
#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)

struct moji{
	char alp;
	struct moji *next;
	struct moji *back;
};

int main(){
	char s[100010];
	scanf("%s",s);
	struct moji *top = (struct moji*)malloc(sizeof(struct moji));
	struct moji *last = top;
	top->alp = s[0];
	top->next = NULL; top->back = NULL;
	for(int i=1;s[i]!=0;i++){
		last->next = (struct moji*)malloc(sizeof(struct moji));
		(last->next)->back = last;
		last = last->next;
		last->alp = s[i];
		last->next = NULL;
	}
	int Q;
	scanf("%d",&Q);
	rep(i,0,Q){
		int t;
		scanf("%d",&t);
		if( t==1 ){
			struct moji *temp=top;
			top=last; last=temp;
		}else{
			int f; char c;
			scanf("%d %c",&f,&c);
			struct moji *data;
			if( f==1 ) data=top;
			else data=last;
			if( data->next==NULL ){
				data->next = (struct moji*)malloc(sizeof(struct moji));
				(data->next)->back = data;
				data = data->next;
				data->alp = c;
				data->next = NULL;
				if(f==1) top = data;
				else last = data;
			}else{
				data->back = (struct moji*)malloc(sizeof(struct moji));
				(data->back)->next = data;
				data = data->back;
				data->alp = c;
				data->back = NULL;
				if(f==1) top = data;
				else last = data;
			}
		}
	}
	struct moji *data=top;
	if( top->next == NULL ){
		while( data!=NULL ){
			printf("%c",data->alp);
			data = data->back;
		}
	}else{
		while( data!=NULL ){
			printf("%c",data->alp);
			data = data->next;
		}
	}
	return 0;
}
