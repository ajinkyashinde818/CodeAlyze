import java.util.*;

public class Main
{
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		
		long a=s.nextLong();
		long a_c=a;
		long b=s.nextLong();
		long b_c=b;
		long ans=1;
		long x=1;
		
		for(int i=2;a>i && b>i;i++)
		{
			while((a_c%i)==0 && (b_c%i)==0)
			{
				a_c/=i;
				b_c/=i;
				x*=i;
			}
		}
		ans=a_c*b_c*x;
		System.out.println(ans);
		
		s.close();
	}
}
