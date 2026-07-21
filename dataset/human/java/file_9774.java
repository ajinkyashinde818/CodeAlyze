import java.io.*;
import java.util.*;
public class Main
{
	final int inf=(int)(1e9+1);
	private void solve()throws IOException
	{
		int n=nextInt();
		int m=nextInt();
		int X=nextInt();
		int c[]=new int[n+1];
		int a[][]=new int[n+1][m+1];
		for(int i=1;i<=n;i++)
		{
			c[i]=nextInt();
			for(int j=1;j<=m;j++)
				a[i][j]=nextInt();
		}
		int bigmask=(1<<n)-1;
		int mincost=inf;
		for(int i=1;i<=bigmask;i++)
		{
			int cost=0;
			int b[]=new int[m+1];
			for(int j=1;j<=n;j++)
			{
				if(((i>>(j-1))&1)==1)
				{
					for(int k=1;k<=m;k++)
						b[k]+=a[j][k];
					cost+=c[j];
				}
			}
			boolean flag=true;
			for(int k=1;k<=m;k++)
				if(b[k]<X)
					flag=false;
			if(flag)
				mincost=Math.min(mincost,cost);
		}
		out.println(mincost==inf?-1:mincost);
	}

	 
	///////////////////////////////////////////////////////////

	public void run()throws IOException
	{
		br=new BufferedReader(new InputStreamReader(System.in));
		st=null;
		out=new PrintWriter(System.out);

		solve();
		
		br.close();
		out.close();
	}
	public static void main(String args[])throws IOException{
		new Main().run();
	}
	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;
	String nextToken()throws IOException{
		while(st==null || !st.hasMoreTokens())
		st=new StringTokenizer(br.readLine());
		return st.nextToken();
	}
	String nextLine()throws IOException{
		return br.readLine();
	}
	int nextInt()throws IOException{
		return Integer.parseInt(nextToken());
	}
	long nextLong()throws IOException{
		return Long.parseLong(nextToken());
	}
	double nextDouble()throws IOException{
		return Double.parseDouble(nextToken());
	}
}
