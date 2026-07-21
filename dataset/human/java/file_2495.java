import java.util.Scanner;

public class Main 
{
	static Scanner scan = new Scanner(System.in);
	
	static int decrypt(String s)
	{
		int val = 0;
		
		int pos = s.indexOf('m');
		if(pos == 0)
		{
			val += 1000;
			s = s.substring(pos+1);
		}
		else if(pos > 0)
		{
			val += Integer.parseInt(s.substring(0, pos))*1000;
			s = s.substring(pos+1);
		}
		
		pos = s.indexOf('c');
		if(pos == 0)
		{
			val += 100;
			s = s.substring(pos+1);
		}
		else if(pos > 0)
		{
			val += Integer.parseInt(s.substring(0, pos))*100;
			s = s.substring(pos+1);
		}
		
		pos = s.indexOf('x');
		if(pos == 0)
		{
			val += 10;
			s = s.substring(pos+1);
		}
		else if(pos > 0)
		{
			val += Integer.parseInt(s.substring(0, pos))*10;
			s = s.substring(pos+1);
		}
		
		pos = s.indexOf('i');
		if(pos == 0)
		{
			val += 1;
			s = s.substring(pos+1);
		}
		else if(pos > 0)
		{
			val += Integer.parseInt(s.substring(0, pos))*1;
			s = s.substring(pos+1);
		}
		
		return val;
	}
	
	public static void main(String[] args) 
	{
		int n = scan.nextInt();
		
		for(int i = 0; i < n; i++)
		{

			
			String s1 = scan.next();
			
			String s2 = scan.next();
			
			int val = decrypt(s1)+decrypt(s2);
			
			String ans = "";
			
			if(val >= 1000)
			{
				int div = val/1000;
				if(div > 1)
				{
					ans += div;
				}
				ans += "m";
				
				val = val%1000;
			}
			
			if(val >= 100)
			{
				int div = val/100;
				if(div > 1)
				{
					ans += div;
				}
				ans += "c";
				
				val = val%100;
			}
			
			if(val >= 10)
			{
				int div = val/10;
				if(div > 1)
				{
					ans += div;
				}
				ans += "x";
				
				val = val%10;
			}
			
			if(val >= 1)
			{
				int div = val/1;
				if(div > 1)
				{
					ans += div;
				}
				ans += "i";
				
				val = val%1;
			}
			
			System.out.println(ans);
		}
	}

}
