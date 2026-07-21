import java.util.*;

public class Main
{
	public static void main(String args[])
	{
		Scanner s1=new Scanner (System.in);
		int n,r;
		n=s1.nextInt();
		r=s1.nextInt();
		if(n<10)
		{
			System.out.print(r+100*(10-n));
		}
		else
		{
			System.out.println(r);
		}
	}
}
