import java.util.*;
import java.io.*;

public class Main
{
	public static void main(String [] Args)
	{
		Scanner in=new Scanner(System.in);
		ArrayDeque<String> deque = new ArrayDeque<String>();
		StringBuilder sb = new StringBuilder();
		String s = in.next();
		deque.add(s);
		int n=in.nextInt();
		int rev=0;
		for(int i=0;i<n;i++)
		{
			int t=in.nextInt();
			if(t==1)
			{
				rev=(rev+1)%2;
			}
			else
			{
				int f=in.nextInt();
				String c=in.next();
				if((f==1&&rev==0)||(f==2&&rev==1))
				{
					deque.addFirst(c);
				}
				else
				{
					deque.addLast(c);
				}
			}
		}
		int m = deque.size();
			for(int i = 0 ;i < m ; i++) {
				sb.append(deque.pollFirst());
			}
		if(rev==1) { 
			sb.reverse();
			}
		
		System.out.println(sb.toString());
	}
}
