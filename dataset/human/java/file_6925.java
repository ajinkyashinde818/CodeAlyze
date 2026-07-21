import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main
{
	public static void main(String[] args)
	{
		new Thread(null, new Runnable() {
			public void run() {
                solve();
            }
        }, "1", 1 << 26).start();
	}
	static void solve () {
		FastReader fr =new FastReader();	PrintWriter op =new PrintWriter(System.out);
 	
 		int k =fr.nextInt() ,n =fr.nextInt() ,a[] =new int[n] ,i ,j ;
 		for (i =0 ; i<n ; ++i)	a[i] =fr.nextInt() ;	sort (a , 0 , n-1) ;	j =a[0] ;
 		for (i =0 ; i<n ; ++i)	a[i] -= j ;	j =a[n-1] ;
 		for (i =1 ; i<n ; ++i) {
 			j =Math.min(j , k - (a[i]-a[i-1])) ;
 		}
		op.println(j) ;	op.flush();	op.close();
	}
		public static void sort(int[] arr , int l , int u) {
			int m ;
	 
			if(l < u){
				m =(l + u)/2 ;
	 
				sort(arr , l , m);	sort(arr , m + 1 , u);
	 
				merge(arr , l , m , u);
			}
		}
	 
		public static void merge(int[] arr , int l , int m , int u) {
			int[] low = new int[m - l + 1] ;
	 
			int[] upr = new int[u - m] ;
	 
			int i ,j =0 ,k =0 ;
	 
			for(i =l;i<=m;i++)
				low[i - l] =arr[i] ;
	 
			for(i =m + 1;i<=u;i++)
				upr[i - m - 1] =arr[i] ;
	
			i =l;
	 
			while((j < low.length) && (k < upr.length))
			{
				if(low[j] < upr[k])
					arr[i++] =low[j++] ;
				else 
					arr[i++] =upr[k++] ;
			}
	 
			while(j < low.length)
				arr[i++] =low[j++] ;
	 
			while(k < upr.length)
				arr[i++] =upr[k++] ;
		}
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br =new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st==null || (!st.hasMoreElements())) 
			{
				try
				{
					st =new StringTokenizer(br.readLine());
				}
				catch(IOException e)
				{
					e.printStackTrace();
				}
				
			}
			return st.nextToken();
		}

		String nextLine() {
			String str ="";

			try
			{
				str =br.readLine();
			}
			catch(IOException e)
			{
				e.printStackTrace();
			}

			return str;
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next()) ;
		}
	}
}
