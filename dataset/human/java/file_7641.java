import java.io.*;
import java.util.*;
public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] cmd=br.readLine().split(" ");
		int n=Integer.valueOf(cmd[0]);
		long k=Long.valueOf(cmd[1]);
		cmd=br.readLine().split(" ");
		int[] arr=new int[n+1];
		for(int i=1;i<=n;i++)
		{
			arr[i]=Integer.valueOf(cmd[i-1]);
		}
		int start=1;
		int[] bool=new int[n+1];
		long moves=0;
		int b=0;
		int ans=0;
		while(bool[start]==0)
		{
			bool[start]=1;
			moves++;
			start=arr[start];
			if(moves==k)
			{
				b=1;
				ans=start;
				break;
			}
		}
		if(b==1)
			System.out.println(ans);
		else
		{
			b=0;
			bool=new int[n+1];
			int c=0;
			while(bool[start]==0)
			{
				bool[start]=1;
				moves++;
				c++;
				start=arr[start];
				if(moves==k)
				{
					b=1;
					ans=start;
					break;
				}
			}
			if(b==1)
				System.out.println(ans);
			else
			{
				long rem=k-moves;
				rem=rem%c;
				while(rem!=0)
				{
					rem--;
					start=arr[start];
				}
				System.out.println(start);
			}
		}
	}

}
