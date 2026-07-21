import java.util.Scanner;

public class Main {
	static int maxn = 100 + 10;
	public static void main(String[] args) 
	{
		Scanner cin = new Scanner(System.in);
		int n=cin.nextInt();
		int k=cin.nextInt();
		if(n<10)
		{
			k+=(10-n)*100;
		}
		System.out.println(k);
	}
	
}
