import java.io.*;
import java.util.*;
public class Main {

	public static void main(String[] args) throws Exception{
		// TODO Auto-generated method stub
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String[] cmd=br.readLine().split(" ");
		int n=Integer.valueOf(cmd[0]);
		int m=Integer.valueOf(cmd[1]);
		int x=Integer.valueOf(cmd[2]);
		int[][] arr=new int[n][m];
		int[] cost=new int[n];
		for(int i=0;i<n;i++)
		{
			cmd=br.readLine().split(" ");
			cost[i]=Integer.valueOf(cmd[0]);
			for(int j=1;j<=m;j++)
			{
				arr[i][j-1]=Integer.valueOf(cmd[j]);
			}
		}
		int min=1000000000;
		for(int i=1;i<=Math.pow(2,n);i++)
		{
			int cnt=0;
			int cos=0;
			for(int j=0;j<n;j++)
			{
				if(((1<<j)&i)!=0)
					cos=cos+cost[j];
			}
			for(int j=0;j<m;j++)
			{
				int d=0;
				for(int k=0;k<n;k++)
				{
					if(((1<<k)&i)!=0)
						d+=arr[k][j];
				}
				if(d>=x)
					cnt++;
			}
			if(cnt==m && min>cos)
				min=cos;
		}
		if(min==1000000000)
			System.out.println(-1);
		else
		System.out.println(min);
	}

}
