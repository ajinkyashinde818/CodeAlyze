import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

class Main {
	
	public static void main(String[] args) throws IOException {
		Scanner sc=new Scanner(System.in);
			long ans=0;
			int n=sc.nextInt();
			long c=sc.nextLong();
			long []x=new long [n];
			int []v=new int [n];
			for(int i=0;i<n;i++)
			{
				x[i]=sc.nextLong();v[i]=sc.nextInt();
			}
			long []forward=new long [n];
			long []back=new long [n];
			long sum=0;
			for(int i=0;i<n;i++)
			{
				sum+=v[i];
				ans=Math.max(ans, sum-x[i]);
				forward[i]=(sum-x[i]);
				
			}
			sum=0;
			for(int i=n-1;i>=0;i--)
			{
				sum+=v[i];
				ans=Math.max(ans, sum-(c-x[i]));
				back[i]=(sum-(c-x[i]));
			}
			SegmentTree tree=new SegmentTree(back);
			//System.out.println(Arrays.toString(tree.max));
			for(int i=0;i<n;i++)
			{
				long s=forward[i]-x[i];
				long max=0;
				if(i+1<n)
					max=tree.query(1, 0, n-1, i+1, n);
				ans=Math.max(ans, s+max);
			}
			tree=new SegmentTree(forward);
			for(int i=n-1;i>=0;i--)
			{
				long s=back[i]-(c-x[i]);
				long max=0;
				if(i-1>=0)
				max=tree.query(1, 0, n-1, 0, i-1);
				
			
				ans=Math.max(ans, s+max);
			}
			
			System.out.println(ans);
		
	}
	static class SegmentTree
	{
		long []a,max;
		SegmentTree(long []b)
		{
			a=b;
			int size=1;
			while(size<a.length)
				size*=2;
			max=new long[size*2];
			build(1,0,a.length-1);
		}
		void build(int node,int l,int r)
		{
			if(l==r)
			{
				max[node]=a[l];
			}
			else
			{
				int mid=(l+r)/2;
				build(2*node,l,mid);
				build(2*node+1,mid+1,r);
				max[node]=Math.max(max[2*node], max[2*node+1]);
			}
			
		}
		long query(int node,int s,int e,int l,int r)
		{
			if(s>r ||  e<l)
			{
				return 0;
			}
			if(s>=l && e<=r)
				return max[node];
			int mid=(s+e)/2;
			return Math.max(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r)) ;
			
		}
	}

}
class Scanner 
{
	StringTokenizer st;
	BufferedReader br;

	public Scanner(InputStream s){	br = new BufferedReader(new InputStreamReader(s));}

	public String next() throws IOException 
	{
		while (st == null || !st.hasMoreTokens()) 
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	public int nextInt() throws IOException {return Integer.parseInt(next());}
	
	public long nextLong() throws IOException {return Long.parseLong(next());}

	public String nextLine() throws IOException {return br.readLine();}
	
	public double nextDouble() throws IOException
	{
		String x = next();
		StringBuilder sb = new StringBuilder("0");
		double res = 0, f = 1;
		boolean dec = false, neg = false;
		int start = 0;
		if(x.charAt(0) == '-')
		{
			neg = true;
			start++;
		}
		for(int i = start; i < x.length(); i++)
			if(x.charAt(i) == '.')
			{
				res = Long.parseLong(sb.toString());
				sb = new StringBuilder("0");
				dec = true;
			}
			else
			{
				sb.append(x.charAt(i));
				if(dec)
					f *= 10;
			}
		res += Long.parseLong(sb.toString()) / f;
		return res * (neg?-1:1);
	}
	
	public boolean ready() throws IOException {return br.ready();}


}
