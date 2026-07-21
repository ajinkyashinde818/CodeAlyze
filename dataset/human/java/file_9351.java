/**
 * @author sakt_coder
 * created on 2020-09-19 17:34
 */
import java.io.*;
import java.util.*;
public class Main
{
	
	private boolean solve()throws Exception
	{
		int n=nextInt();
		boolean d[]=new boolean[n+1];
		for(int i=1;i<=n;i++)
		{
			int first=nextInt();
			int second=nextInt();
			if(first==second)
				d[i]=true;
		}
		for(int i=1;i<=n-2;i++)
			if(d[i] && d[i+1] && d[i+2])
				return true;
		return false;
	}

	 
	///////////////////////////////////////////////////////////

	public void run()throws Exception
	{
		br=new BufferedReader(new InputStreamReader(System.in));
		st=null;
		out=new PrintWriter(System.out);

		out.println(solve()?"Yes":"No");
		
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
