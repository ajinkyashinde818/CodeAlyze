import java.util.*;
class Main 
{ 

	
	 
	public static void main(String args[]) 
	{ 
		Scanner s = new Scanner(System.in);
		int a = s.nextInt();
		int b = s.nextInt();
		int k = s.nextInt();
		int count=1;
		for(int i=Math.max(a,b);i>0;i--)
		{
			if(a%i==0 && b%i==0)
			{
				if(count==k)
				{
					System.out.println(i);
					break;
				}
				count++;
			}
		}

		

		
		
		
	}
}
