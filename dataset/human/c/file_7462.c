#include <stdio.h>
int main (void){
int x,y,z[10001],i[10001],j,k;

for (y=0;y<10000;y++){
z[y]=0;
i[y]=0;
}

for (y=1;y<10001;y++){
 scanf ("%d",&z[y]);
	if (z[y]==0){
	break;
}

i[y]=i[y-1]+1;

}

for (y=1;y<10001;y++){
if (z[y]==0){
break;
}
printf("Case %d: %d\n",i[y],z[y]);

}

return 0;
}
