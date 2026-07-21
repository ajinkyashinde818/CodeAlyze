#include <stdio.h>
#include <cstdlib>
#include <math.h>

int wx[100],wy[100],r[100],n,m,tx,ty,sx,sy,i,j,check,cos1,cos2;
double distance;

int main()
{
	for(;scanf("%d",&n),n;)
	{
		for(i=0;i<n;i++)
		scanf("%d %d %d",&wx[i],&wy[i],&r[i]);
		
		scanf("%d",&m);
		
		for(j=0;j<m;j++)
		{
			scanf("%d %d %d %d",&tx,&ty,&sx,&sy);
			
			check=0;
			for(i=0;i<n;i++)
			{
				cos1 = (wx[i]-tx)*(sx-tx)+(wy[i]-ty)*(sy-ty);
				cos2 = (wx[i]-sx)*(tx-sx)+(wy[i]-sy)*(ty-sy);
				
				distance = cos1<0 ? hypot(wx[i]-tx,wy[i]-ty) : cos2<0 ? hypot(wx[i]-sx,wy[i]-sy) : abs((sx-tx)*(wy[i]-ty)-(wx[i]-tx)*(sy-ty)) / hypot(sx-tx,sy-ty);
				
				if( (r[i]>hypot(tx-wx[i],ty-wy[i])) - (r[i]>hypot(sx-wx[i],sy-wy[i])) )
				check++;
				
				if(distance<=r[i]&& ( r[i]<hypot(tx-wx[i],ty-wy[i]) || r[i]<hypot(sx-wx[i],sy-wy[i]) ))
				check++;
			}
			puts(check ? "Safe" : "Danger");
		}
	}
	return 0;
}
