import java.util.*;
public class Main 
{
	public static void main(String[] args) 
	{
		Scanner stdIn = new Scanner(System.in);
		int n = stdIn.nextInt();
		while(n-- != 0)
		{
			String s1 = stdIn.next();
			String s2 = stdIn.next();
			int num1 = 0, num2 = 0;
			if(s1.length() == 1)
			{
				if(s1.charAt(0) == 'm')
				{
					num1 = 1000;
				}
				else if(s1.charAt(0) == 'c')
				{
					num1 = 100;
				}
				else if(s1.charAt(0) == 'x')
				{
					num1 = 10;
				}
				else if(s1.charAt(0) == 'i')
				{
					num1 = 1;
				}
			}
			else
			{
				for(int i = 0; i < s1.length(); ++i)
				{
					if(s1.charAt(i) == 'm')
					{
						if(i == 0 || s1.charAt(i - 1) < '2' || '9' < s1.charAt(i - 1))
						{
							num1 += 1000;
						}
						else if('2' <= s1.charAt(i - 1) && s1.charAt(i - 1) <= '9')
						{
							num1 += 1000 * (s1.charAt(i - 1) - '0');
						}
					}
					if(s1.charAt(i) == 'c')
					{
						if(i == 0 || s1.charAt(i - 1) < '2' || '9' < s1.charAt(i - 1) )
						{
							num1 += 100;
						}
						else if('2' <= s1.charAt(i - 1) && s1.charAt(i - 1) <= '9')
						{
							num1 += 100 * (s1.charAt(i - 1) - '0');
						}
					}
					if(s1.charAt(i) == 'x')
					{
						if(i == 0 || s1.charAt(i - 1) < '2' || '9' < s1.charAt(i - 1) )
						{
							num1 += 10;
						}
						else if('2' <= s1.charAt(i - 1) && s1.charAt(i - 1) <= '9')
						{
							num1 += 10 * (s1.charAt(i - 1) - '0');
						}
					}
					if(s1.charAt(i) == 'i')
					{
						if(i == 0 || s1.charAt(i - 1) < '2' || '9' < s1.charAt(i - 1) )
						{
							num1 += 1;
						}
						else if('2' <= s1.charAt(i - 1) && s1.charAt(i - 1) <= '9')
						{
							num1 += 1 * (s1.charAt(i - 1) - '0');
						}
					}
				}
			}
			if(s2.length() == 1)
			{
				if(s2.charAt(0) == 'm')
				{
					num2 = 1000;
				}
				else if(s2.charAt(0) == 'c')
				{
					num2 = 100;
				}
				else if(s2.charAt(0) == 'x')
				{
					num2 = 10;
				}
				else if(s2.charAt(0) == 'i')
				{
					num2 = 1;
				}
			}
			else
			{
				for(int i = 0; i < s2.length(); ++i)
				{
					if(s2.charAt(i) == 'm')
					{
						if(i == 0 || s2.charAt(i - 1) < '2' || '9' < s2.charAt(i - 1))
						{
							num2 += 1000;
						}
						else if('2' <= s2.charAt(i - 1) && s2.charAt(i - 1) <= '9')
						{
							num2 += 1000 * (s2.charAt(i - 1) - '0');
						}
					}
					if(s2.charAt(i) == 'c')
					{
						if(i == 0 || s2.charAt(i - 1) < '2' || '9' < s2.charAt(i - 1) )
						{
							num2 += 100;
						}
						else if('2' <= s2.charAt(i - 1) && s2.charAt(i - 1) <= '9')
						{
							num2 += 100 * (s2.charAt(i - 1) - '0');
						}
					}
					if(s2.charAt(i) == 'x')
					{
						if(i == 0 || s2.charAt(i - 1) < '2' || '9' < s2.charAt(i - 1) )
						{
							num2 += 10;
						}
						else if('2' <= s2.charAt(i - 1) && s2.charAt(i - 1) <= '9')
						{
							num2 += 10 * (s2.charAt(i - 1) - '0');
						}
					}
					if(s2.charAt(i) == 'i')
					{
						if(i == 0 || s2.charAt(i - 1) < '2' || '9' < s2.charAt(i - 1) )
						{
							num2 += 1;
						}
						else if('2' <= s2.charAt(i - 1) && s2.charAt(i - 1) <= '9')
						{
							num2 += 1 * (s2.charAt(i - 1) - '0');
						}
					}
				}
			}
			
			int ans = num1 + num2;
			if(ans >= 2000)
			{
				System.out.print(ans / 1000 + "m");
			}
			else if(ans >= 1000)
			{
				System.out.print("m");
			}
			ans %= 1000;
			if(ans >= 200)
			{
				System.out.print(ans / 100 + "c");
			}
			else if(ans >= 100)
			{
				System.out.print("c");
			}
			ans %= 100;
			if(ans >= 20)
			{
				System.out.print(ans / 10 + "x");
			}
			else if(ans >= 10)
			{
				System.out.print("x");
			}
			ans %= 10;
			if(ans >= 2)
			{
				System.out.print(ans + "i");
			}
			else if(ans >= 1)
			{
				System.out.print("i");
			}
			System.out.println();
		}
	}
}
