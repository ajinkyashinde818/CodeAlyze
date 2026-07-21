import java.io.*;
import java.util.*;
public class Main
{
	private void solve()throws Exception
	{
		long n=nextLong();
		int ans=0;
		for(long i=2;i*i<=n;i++)
		{
			int p=0;
			while(n%i==0)
			{
				p++;
				n=n/i;
			}
			int j;
			for(j=1;j*(j+1)/2<=p;j++);
			j--;
			ans+=j;
		}
		if(n>1)
			ans++;
		out.println(ans);
	}

	 
	///////////////////////////////////////////////////////////

	public void run()throws Exception
	{
		br=new BufferedReader(new InputStreamReader(System.in));
		st=null;
		out=new PrintWriter(System.out);

		solve();
		
		br.close();
		out.close();
	}
	public static void main(String args[])throws Exception{
		new Main().run();
	}
	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	String nextToken()throws Exception{
		while(st==null || !st.hasMoreTokens())
		st=new StringTokenizer(br.readLine());
		return st.nextToken();
	}
	String nextLine()throws Exception{
		return br.readLine();
	}
	int nextInt()throws Exception{
		return Integer.parseInt(nextToken());
	}
	long nextLong()throws Exception{
		return Long.parseLong(nextToken());
	}
	double nextDouble()throws Exception{
		return Double.parseDouble(nextToken());
	}
}
