import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Main
{
	public static void main(String[] args)throws IOException
	{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		String str=br.readLine();
		int n=Integer.parseInt(str);
		for(int i=0;i<n;i++)
		{
			int N=Integer.parseInt(br.readLine());
			str=br.readLine();
			int[] u=new int[N+1];
			int[] d=new int[N+1];
			for(int j=0;j<N+1;j++)
			{
				u[j]=0;d[j]=0;
			}
			String down=str.substring(2*N,4*N);
			for(int j=1;j<N;j++)
			{
				if(str.substring(2*j-1,2*j).equals("Y")||str.substring(2*j,2*j+1).equals("Y"))
				{
					u[j]++;
				}
			}
			for(int j=1;j<N;j++)
			{
				if(down.substring(2*j-1,2*j).equals("Y")||down.substring(2*j,2*j+1).equals("Y"))
				{
					d[j]++;
				}
			}
			if(str.substring(0,1).equals("Y")){u[0]++;}if(str.substring(2*N-1,2*N).equals("Y")){u[N]++;}
			if(down.substring(0,1).equals("Y")){d[0]++;}if(down.substring(2*N-1,2*N).equals("Y")){d[N]++;}


			int ans=N;
			int f=-1,l=-1;
			int ff=-1,ll=-1;
			for(int j=0;j<N+1;j++)
			{
				if(u[j]==1){f=j;break;}
			}
			for(int j=N;j>=0;j--)
			{
				if(u[j]==1){l=j;break;}
			}
			for(int j=0;j<N+1;j++)
			{
				if(d[j]==1){ff=j;break;}
			}
			for(int j=N;j>=0;j--)
			{
				if(d[j]==1){ll=j;break;}
			}


			int uc=0,dc=0;
			for(int j=0;j<N+1;j++)
			{
				uc+=u[j];
				dc+=d[j];
			}



			if(ff==-1)
			{
				ans+=uc;
			}
			else
			{
				ans=ans+uc+dc;
				if(ff<f)
				{
					ans++;
				}
				if(ll>l)
				{
					ans++;
				}


			}

			System.out.println(ans);





		}
	}

}
