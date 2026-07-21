import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main
{
	public static void main(String[] args) {
		new Thread(null, new Runnable() {
			public void run() {
                solve();
            }
        }, "1", 1 << 26).start();
	}
	static void solve () {
		FastReader fr =new FastReader();	PrintWriter op =new PrintWriter(System.out);
 
 		int n =fr.nextInt() ,a[] =new int[n+1] ,i =1 ,j =-1 ,k ,cyc[] =new int[n+2] ;
 		long ct =fr.nextLong() ,len ;	boolean mrk[] =new boolean[n+1] ;
 		
 		for (k =1 ; k<=n ; ++k)	a[k] =fr.nextInt() ;
 		
 		while (!mrk[i]) {
 			cyc[++j] =i ;	mrk[i] =true ;	i =a[i] ;
 		}
 		for (k =0 ; k<=j ; ++k) {
 			if (cyc[k]==i)	break;
 		}
 		len =j-k+1 ;
 		
 		if (ct <= k)	op.println(cyc[(int)ct]) ;
 		else {
 			ct -= k ;	ct %= len ;	k += ct ;
 			op.println(cyc[k]) ;
 		}
		op.flush();	op.close();
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
