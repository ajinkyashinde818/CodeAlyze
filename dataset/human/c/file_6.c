# include <stdio.h>
int main ()
{ 
 int r,g,b,n;
 int ans=0;
 int i,j,k;
 scanf ("%d%d%d%d",&r,&g,&b,&n);
 //printf ("%d %d %d %d\n",r,g,b,n);
 for (i=0;i<=(n/r)+10;++i)
    {
    	for (j=0;j<=(n/g)+10;++j)
    	    {
              int p=n-i*r-g*j;
              if (p%b==0&&p/b>=0)
                  ans++;
    	    }
    }
 printf ("%d\n",ans);
 return 0;
}
