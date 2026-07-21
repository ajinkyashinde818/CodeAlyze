import java.util.*;
import java.io.*;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
 
class Main
{
	static class Pair
	{
		int first, second;
		public Pair(int f, int s)
		{
			first = f;
			second = s;
		}
		
		public String toString()
		{
			return first + " " + second;
		}
	}
	
	static class PairComparator implements Comparator <Pair>
	{
		public int compare(Pair p1, Pair p2)
		{
			if(p1.first < p2.first)
				return -1;
			if(p1.first > p2.first)
				return 1;
			if(p1.second < p2.second)
				return -1;
			if(p1.second > p2.second)
				return 1;
			return 0;
		}
	}
	
	static int log2(double a)
	{
		return (int)(Math.log(a) / Math.log(2));
	}
	
	static long gcd(long a, long b)
	{
		long r;
		while((r = a % b) > 0)
		{
			a = b;
			b = r;
		}
		return b;
	}
	
	static class TrieNode
	{
		TrieNode z, o;
		boolean end;
		long count;
		
		public TrieNode()
		{
			 z = null;
			 o = null;
			 count = 0;
			 end = false;
		}
		
		
	}
	
	public static void main(String[] args) throws IOException
	{
		int n = in.nextInt();
		if(n / 10 == 9 || n % 10 == 9)
			sop("Yes");
		else
			sop("No");
	}
    
	static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;
 
        public FastReader()
        {
            br = new BufferedReader(new InputStreamReader(System.in));
        }
        
        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
 
        int nextInt()
        {
            return Integer.parseInt(next());
        }
 
        long nextLong()
        {
            return Long.parseLong(next());
        }
 
        double nextDouble()
        {
            return Double.parseDouble(next());
        }
 
        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }
    }
	
    static FastReader in = new FastReader();
  
    public static void sop(Object o)
    {
    	System.out.print(o);
    }
}
