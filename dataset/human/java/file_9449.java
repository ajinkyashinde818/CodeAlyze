import java.util.Scanner;

public class Main {
	
	public static void main(String[] args)
	{
		Scanner s=new Scanner(System.in);
		
		int n=s.nextInt();
		
		int p=0;
		
		int count=0;
		
		for(int i=0;i<n;i++)
		{
			int a=s.nextInt();
			int b=s.nextInt();
			
			if(a==b)
			{
				count++;
			}
			else
			{
				count=0;
			}
			
			if(count>=3)
			{
				p=1;
			}
		}
		
		if(p==1)
		{
			System.out.println("Yes");
		}
		else
		{
			System.out.println("No");
		}
		
	}
	
}
