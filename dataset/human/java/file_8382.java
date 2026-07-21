import java.util.*;
public class Main
{
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		long A = sc.nextLong();
		long B = sc.nextLong();
		long min = 100000000;
		long nmin = 0;
		if(A>B)
		{
			min = B;
			nmin = A;
		}
		else
		{
			min = A;
			nmin = B;
		}
		for(long i=1;i<=nmin;i++)
		{
			if(i*min%nmin==0)
			{
				System.out.println(i*min);
				break;
			}
		}
	}
}
