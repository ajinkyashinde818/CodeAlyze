import java.util.ArrayList;
import java.util.*;
  public class Main
{
	public static void main (String[] args)
	 {
		Scanner sc=new Scanner(System.in); 
		long n=sc.nextLong();
		long k=sc.nextLong();
		int a[]=new int[(int)n+1];
		long c[][]=new long[(int)n+1][2];
		long r=0;
		
		for(int i=1;i<=n;i++)
		{
			a[i]=sc.nextInt();
			
		}
		int i=1;
		
		
		while(k>0)
		{
			if(c[i][0]==1)
			{
				r=r-c[i][1];
				break;
			}
			c[i][0]=1;
			c[i][1]=r;
			i=a[i];
			r++;
			k--;
		}
		k%=r;
		
		while(k>0)
		{
			i=a[i];
			k--;
		}
		System.out.println(i);
	}
}
