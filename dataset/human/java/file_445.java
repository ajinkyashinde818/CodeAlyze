import java.util.*;
class Main
{
	public static void main(String arg[])
	{
	Scanner sc = new Scanner(System.in);
	int n,r;
	try
	{
	n=sc.nextInt();
	r=sc.nextInt();
	
	if(n<10)
	{
		int t=100*(10-n);
		int d=r+t;
		System.out.println(d);
	}
	else
	{
		System.out.println(r);
	}
	}
	catch(InputMismatchException e)
	{
		System.out.println("enter numeric value");
	}
	}
}
