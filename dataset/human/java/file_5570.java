import java.util.Scanner;

public class Main {

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		long n = sc.nextLong(); //nums
		long k = sc.nextLong(); //"pairs"
		long s = sc.nextLong(); //sum
		
		long filler = s==1000000000?1:s+1;
		
		StringBuilder sb = new StringBuilder();
		
		for(int i = 0; i < n; i++)
		{
			if(i>0)sb.append(" ");
			if(i < k)
			{
				sb.append(s);
			}
			else
			{
				sb.append(filler);
			}
		}
		System.out.print(sb);

	}

}
