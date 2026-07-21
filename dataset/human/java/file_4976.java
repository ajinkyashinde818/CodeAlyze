import java.io.*;
import java.util.*;
public class Main
{
	
	private void solve()throws IOException
	{
		Deque<Character> deque=new LinkedList<>();
		String s=nextLine();
		int n=s.length();
		for(int i=n-1;i>=0;i--)
			deque.addFirst(s.charAt(i));
		int head=0;
		int q=nextInt();
		while(q-->0)
		{
			int t=nextInt();
			if(t==1)
			{
				head=1^head;
			}
			else
			{
				int f=nextInt();
				char c=nextToken().charAt(0);
				if(f==1)
				{
					if(head==0)
						deque.addFirst(c);
					else
						deque.addLast(c);
				}
				else
				{
					if(head==0)
						deque.addLast(c);
					else
						deque.addFirst(c);
				}
			}
		}
		while(!deque.isEmpty())
		{
			if(head==0)
				out.print(deque.removeFirst());
			else
				out.print(deque.removeLast());
		}
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
