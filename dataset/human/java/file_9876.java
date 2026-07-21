import java.util.*;
public class Main{
	public static void main(String[] args)
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt(),m=in.nextInt(),x=in.nextInt();
		int[][] arr=new int[n][m+1];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				arr[i][j]=in.nextInt();
			}
		}
		int ans=1000000007;
		for(int i=1;i<(1<<n);i++)
		{
			boolean f=true;
			int[] ar=new int[m];
			int sum=0;
			for(int j=0;j<n;j++)
			{
				if((1&(i>>j))==1)
				{
					sum+=arr[j][0];
					for(int k=1;k<=m;k++)
					{
						ar[k-1]+=arr[j][k];
					}
				}
			}
			for(int j=0;j<m;j++)
			{
				if(ar[j]<x)
					f=false;
			}
			if(f)
			{
				ans=Math.min(ans,sum);
			}

		}
		if(ans==1000000007)
		{
			System.out.println(-1);
		}
		else
		{
			System.out.println(ans);
		}
	}
}
