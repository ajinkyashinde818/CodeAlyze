import java.io.BufferedReader; 
import java.io.IOException; 
import java.io.InputStreamReader; 
import java.util.Scanner; 
import java.util.StringTokenizer; 
import java.util.*; 
/**
 * :)
 **/
 
public class Main 
{ 
    static class FastReader 
    { 
        BufferedReader br; 
        StringTokenizer st; 
  
        public FastReader() 
        { 
            br = new BufferedReader(new
                     InputStreamReader(System.in)); 
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
  public static long primeFactors(long n)
{
    long ans=1;
    if(n%2==0)
    ans*=2*1l;
    while (n%2 == 0)
    {
        n = n/2;
    }
    
    for (int i = 3; i*i<=n; i = i+2)
    {
        if(n%i==0)
        ans*=i*1l;
        while (n%i == 0)
        {
            n = n/i;
        }
    }
   
    if (n > 2)
        ans*=n*1l;
        return ans;
}

public static long gcd( long a, long b)
{
    if(b==0)
    return a;
    return gcd(b, a%b);
}
    public static void main(String[] args) 
    { 
        FastReader sc=new FastReader(); 
	    int n=sc.nextInt();
	    long k=sc.nextLong();
	    int a[]=new int[n];
	    for( int i=0;i<n;i++)
	    {
	        a[i]=sc.nextInt();
	        a[i]--;
	    }
	    ArrayList<Integer> adj=new ArrayList<>();
	    HashMap<Integer, Integer> hm=new HashMap<>();
	    int x=0;
	    int count=0;
	    while(!hm.containsKey(x))
	    {
	        adj.add(x);
	        hm.put(x,1);
	        x=a[x];
	    }
	    int index=0;
	    for( int i=0;i<adj.size();i++)
	    {
	        if(adj.get(i)==x)
	        {
	           index=i;
	           break;
	        }
	    }
	    //System.out.println(index);
	    int p=adj.size();
	    if(k<index)
	    {
	        System.out.println(adj.get((int)k)+1);
	    }
	    else
	    {
	        k-=index;
	        
	        k%=(p-index);
	        System.out.println(adj.get(index+(int)k)+1);
	    }
	    
	  
		
	}
	public static void sort( long a[])
	{
	    ArrayList<Long> adj=new ArrayList<>();
	    for( int i=0;i<a.length;i++)
	    {
	        adj.add(a[i]);
	    }
	    Collections.sort(adj);
	    for( int i=0;i<a.length;i++)
	    {
	        a[i]=adj.get(i);
	    }
	}
	public static long find(int ind, long bit[])
    {
        long sum=0;
        while(ind>0)
        {
           long last_bit= (ind) & (-ind);
           sum+=bit[ind];
           ind-=last_bit;
           
        }
        return sum;
    }
    public static void update( long bit[], int ind, int val, int lim )
    {
        while(ind<=lim)
        {
            bit[ind]+=val;
            ind+=(ind)&(-ind);
        }
    }
}
