/*
文字を、辞書順にa,b,c,……とする。
前から順に「その時点でありえる辞書順最小の文字列」を求め、最後まで整合性が取れるかどうかチェックする。
文字列はaが大部分を占めるので、「aに関する情報は持たない」ことにして圧縮する。
例えば"aabaca"という文字列は"(2,b),(4,c),(5,a)"という(index,文字)のペアの列で持つ。
文字列の伸び縮みをうまく実装すると解ける（大変）
*/

#include <stdio.h>
#define rep(i,l,r)for(int i=(l);i<(r);i++)

int n;
int a[200010];
int q[200010];//index
int c[200010];//文字
//(q[i],c[i])の組の列で文字列を保持する

int f(int m){
	int qc=0;
	q[0]=a[0];
	c[0]=1;
	qc=1;
	rep(i,1,n){
		if(a[i]>q[qc-1]){
			//伸びるときは後ろにaを増やすだけ
			q[qc]=a[i];
			c[qc]=1;
			qc++;
		}else if(a[i]==q[qc-1]){
			//同じときは末尾の文字を変えるだけ
			c[qc-1]++;
		}else{
			//縮むときは頑張る
			while(qc&&q[qc-1]>a[i])qc--;
			if(qc&&q[qc-1]==a[i]){
				c[qc-1]++;
			}else{
				q[qc]=a[i];
				c[qc]=2;
				qc++;
			}
		}
		
		if(c[qc-1]>m){
			int t=a[i];
			//末尾は(t,>m)なので、これをpopして(t-1,*)をincしたい
			while(c[qc-1]>m){
				//1文字目が溢れたらどうしようもない
				if(t==1)return 0;
				qc--;//pop
				if(qc&&q[qc-1]==t-1){
					c[qc-1]++;
				}else{
					q[qc]=t-1;
					c[qc]=2;
					qc++;
				}
				t--;
			}
			//(a[i],1)を追加し直す
			q[qc]=a[i];
			c[qc]=1;
			qc++;
		}
	}
	return 1;
}

int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	
	//答えをにぶたん
	int lans=0,rans=200010;//lはng,rはok
	while(rans-lans>1){
		int m=(lans+rans)/2;
		if(f(m))rans=m;
		else lans=m;
	}
	printf("%d",rans);
}
