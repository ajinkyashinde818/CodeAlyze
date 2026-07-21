import java.util.Scanner;
public class Main
{
	public static void main(String[] args) 
	{
		Scanner in=new Scanner(System.in);
		int ans=0;
		for(int i=0;i<10;i++)
			ans+=in.nextInt();
		System.out.println(ans);
	}
}
