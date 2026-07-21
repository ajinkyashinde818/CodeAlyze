import java.util.Scanner;
public class Main
{
	public static void main(String[] args) 
	{
		Scanner in=new Scanner(System.in);
		for(;;)
		{
			int n=in.nextInt();
			if(n==0)
				return;
			double en[][]=new double[n][3];
			for(int i=0;i<n;i++)
				for(int j=0;j<3;j++)
					en[i][j]=in.nextDouble();
			int m=in.nextInt();
			for(int i=0;i<m;i++)
			{
				double tx=in.nextDouble(),ty=in.nextDouble();
				double sx=in.nextDouble(),sy=in.nextDouble();
				boolean judge=false;
				
				for(int j=0;j<n;j++)
				{
					double r=en[j][2];
					double dit=Math.hypot(tx-en[j][0],ty-en[j][1]);
					double dis=Math.hypot(sx-en[j][0],sy-en[j][1]);
					double d=lp_dis(en[j][0],en[j][1],tx,ty,sx,sy);
					if((dit>r||dis>r) && d<=r)
						judge=true;
				}
				System.out.println(judge ? "Safe":"Danger");
			}
		}
	}
	static double lp_dis(double px,double py,double x1,double y1,double x2,double y2)
	{
		double dx=x2-x1,dy=y2-y1;
		double a=dx*dx+dy*dy,b=dx*(x1-px)+dy*(y1-py);
		double t=-b/a;
		if(t<0) t=0;
		if(t>1) t=1;
		double tx=x1+dx*t;
		double ty=y1+dy*t;
		return Math.hypot(px-tx, py-ty);
	}
}
