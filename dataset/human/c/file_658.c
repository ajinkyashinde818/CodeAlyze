#include <stdio.h>
int main() {
	int n, m,f=0,finish=0;
	char a[50][50], b[50][50];
	scanf("%d %d", &n, &m);
	for (int i = 0;i < n;i++) scanf("%s", a[i]);
	for (int i = 0;i < m;i++) scanf("%s", b[i]);

	for (int y = 0;y < n;y++) {
		for (int x = 0;x < n;x++) {
          if(a[y][x]==b[0][0]){
            for(int yy=0;yy<m;yy++){
              for(int xx=0;xx<m;xx++){
                if(a[y+yy][x+xx]==b[yy][xx]) f++;
                else f=0;
                if(f==m*m){
                  finish=1;
                  break;
                }
              }
              if(finish==1) break;
            }
            if(finish==1) break;
          }
          f=0;
          if(finish==1) break;
		}
      if(finish==1) break;
	}
	if (f == 0) printf("No");
	else printf("Yes");
	return 0;
}
