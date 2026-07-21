import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class Main{
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
	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		br=new BufferedReader(new InputStreamReader(System.in));
		StringBuilder s=new StringBuilder(br.readLine());
		Deque<Character> dq = new ArrayDeque<>();
		for(int i=0;i<s.length();i++)
		{
			dq.addLast(s.charAt(i));
		}
		int q=cin();
		int rev=0;
		for(int i=0;i<q;i++)
		{
			String[] st=br.readLine().split(" ");
			int t=Integer.valueOf(st[0]);
			if(t==1)
				rev=rev^1;
			else
			{
				StringBuilder g=new StringBuilder(st[2]);
				int f=Integer.valueOf(st[1]);
				if(f==2)
				{
					if(rev==0)
						dq.addLast(st[2].charAt(0));
					else
						dq.addFirst(st[2].charAt(0));
				}
				else
				{
					if(rev==0)
						dq.addFirst(st[2].charAt(0));
					else
						dq.addLast(st[2].charAt(0));
				}
			}
		}
		StringBuilder ans=new StringBuilder("");
		while(!dq.isEmpty())
		{
			ans.append(dq.pollFirst());
		}
		if(rev==0)
			System.out.println(ans);
		else
		{
			System.out.println(ans.reverse().toString());
		}
	}
}
