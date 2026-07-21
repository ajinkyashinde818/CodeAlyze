#include <stdio.h>

#define SIZE 1000

int sum[SIZE][SIZE], n;
char map[SIZE][SIZE];

int in(int y, int x, int size)
{
     int d=size-1, t;

     t = sum[y+d][x+d];
     
     if(x>0) t -= sum[y+d][x-1];
     if(y>0) t -= sum[y-1][x+d];
     
     if(x>0 && y>0) t += sum[y-1][x-1];

     return t;
}

int main(void)
{
     int i, j, max=0, count;

     while(1){
	  max = 0;
	  
	  // input
	  scanf("%d%*c",&n); if(n==0) return 0;
	  for(i=0; i<n; i++) scanf("%s",map[i]);

	  // init sum
	  for(i=0; i<n; i++)
	       for(j=0; j<n; j++)
		    sum[i][j] = (map[i][j]=='*'? 1 : 0);

	  // add vertically
	  for(i=1; i<n; i++)
	       for(j=0; j<n; j++)
		    sum[i][j] += sum[i-1][j];
     
	  //add horizontally
	  for(i=1; i<n; i++)
	       for(j=0; j<n; j++)
		    sum[j][i] += sum[j][i-1];

	  // check
	  for(i=0; i<n; i++)
	       for(j=0; j<n; j++)
		    if(map[i][j]!='*'){
			 count=1;

			 while(i+count<n && j+count<n && !in(i,j,count+1))
			      count++;
		    
			 if(count>max) max=count;
		    }

	  printf("%d\n",max);
     }
}
