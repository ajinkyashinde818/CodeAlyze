#include <stdio.h>
bool RB[105000];int ans[10005];int main() {int i,j;for (i=0;i<105000;RB[i++]=true);for (i=2;i<325;i++) if (RB[i]) for (j=i*i;j<105000;RB[j]=false,j+=i);for (i=2,j=1,ans[0]=0;i<105000;i++) if (RB[i]) ans[j]=ans[j-1]+i,j++;while (1) {scanf("%d",&i);if (!i) return 0;printf("%d\n",ans[i]);}}
