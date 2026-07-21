import java.util.Scanner;

public class Main {

	public static void main(String args[])
	{
		Scanner scan=new Scanner(System.in);
		int n=scan.nextInt();
		long ar[]=new long[n+1];
		long[][] sumtill=new long[100001][2];
		
		for(int i=1;i<=n;i++)
		{
			ar[i]=scan.nextLong();
		}
		sumtill[1][0]=ar[1];
		sumtill[1][1]=ar[1];
		sumtill[2][1]=-ar[1]-ar[2];
		sumtill[2][0]=ar[1]+ar[2];
		for(int i=3;i<=n;i++)
		{
			long maxwithout=Math.max(sumtill[i-2][0],sumtill[i-2][1]);
			
			sumtill[i][0]=ar[i]+Math.max(ar[i-1]+maxwithout,sumtill[i-1][1]);
			sumtill[i][1]=-ar[i]+Math.max(-ar[i-1]+maxwithout,sumtill[i-1][1]+2*ar[i-1]);
			
		}
		long answer=Math.max(sumtill[n][0],sumtill[n][1]);
		System.out.println(answer);
		
	}
}
