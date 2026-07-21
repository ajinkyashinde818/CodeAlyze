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
 
 		int n =fr.nextInt() ,m =fr.nextInt() ,x =fr.nextInt() ,c[] =new int[n] ,a[][] =new int[n][m] ,i ,j ;
 		for (i =0 ; i<n ; ++i) {
 			c[i] =fr.nextInt() ;	for (j =0 ; j<m ; ++j)	a[i][j] =fr.nextInt() ;
 		}
 		int k =1<<n ,l ,dm[] ,p ,q ,cst =Integer.MAX_VALUE ;
 		for (i =1 ; i<k ; ++i) {
 			l =0 ;	dm =new int[m] ;

 			for (p =0 ; p<n ; ++p) {
 				if (((1<<p)&i) != 0) {
 					l += c[p] ;
 					for (q =0 ; q<m ; ++q)	dm[q] += a[p][q] ;
 				}
 			}
 			q =Integer.MAX_VALUE ;
 			for (p =0 ; p<m ; ++p)	q =Math.min(q , dm[p]) ;
 			if (q>=x)	cst =Math.min(cst , l) ;
 		}
 		if (cst==Integer.MAX_VALUE)	op.println("-1") ;
 		else 	op.println(cst) ;
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
