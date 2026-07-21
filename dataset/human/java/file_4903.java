import java.io.*;
import java.util.*;
public class Main {
	static BufferedReader br;
	static int cin() throws Exception
	{
		return Integer.valueOf(br.readLine());
	}
	static int[] split() throws Exception
	{
		String[] cmd=br.readLine().split(" ");
		int[] ans=new int[cmd.length];
		for(int i=0;i<cmd.length;i++)
		{
			ans[i]=Integer.valueOf(cmd[i]);
		}
		return ans;
	}
	static long[] splitL() throws IOException
	{
		String[] cmd=br.readLine().split(" ");
		long[] ans=new long[cmd.length];
		for(int i=0;i<cmd.length;i++)
		{
			ans[i]=Long.valueOf(cmd[i]);
		}
		return ans;
	}
	static long mod=1000000007;
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		br=new BufferedReader(new InputStreamReader(System.in));
		long n=Long.valueOf(br.readLine());
		if(n%2!=0)
			System.out.println(0);
		else
		{
			long x=n/2;
			long twos=x;
			long fives=0;
			long st=2;
			while(true)
			{
				long h=x/st;
				if(h==0)
					break;
				twos+=h;
				st=st*2;
			}
			st=5;
			while(true)
			{
				long h=x/st;
				if(h==0)
					break;
				fives+=h;
				st=st*5;
			}
			System.out.println(Math.min(twos, fives));
		}
	}
}
